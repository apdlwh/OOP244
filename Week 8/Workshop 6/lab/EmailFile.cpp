#define _CRT_SECURE_NO_WARNINGS

#include "EmailFile.h"
#include <cstring>
#include <fstream>
#include <iostream>
//did not use namespace std...
namespace seneca {

Email::Email(){ //default constructor 
    m_email = nullptr; 
    m_name = nullptr;
    m_year[0] = '\0';
}

Email& Email::operator=(const Email& rhs) { //**o copy assignment operator

        if (this != &rhs && rhs.m_email && rhs.m_name) {
            delete[] m_email;
            m_email = nullptr;
            m_email = new char[strlen(rhs.m_email) + 1];
            strcpy(m_email, rhs.m_email);
            delete[] m_name;
            m_name = nullptr;
            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(m_name, rhs.m_name);
            strcpy(m_year, rhs.m_year);
        }

        return *this;
    }


bool Email::load(std::ifstream& in) {//o

        char buffer[BUFFER_SIZE];
        bool result = false; 

        if (in.getline(buffer, BUFFER_SIZE, ',')) {
            delete[] m_email;
            m_email = new char[strlen(buffer) + 1];
            strcpy(m_email, buffer);

            if (in.getline(buffer, BUFFER_SIZE, ',')) {
                delete[] m_name;
                m_name = new char[strlen(buffer) + 1];
                strcpy(m_name, buffer);

                if (in.getline(buffer, BUFFER_SIZE, '\n')) {
                    strcpy(m_year, buffer);
                    result = true;
                }
            }
        }

        return result;
    }

Email::~Email() {//o
      delete[] m_name;
      delete[] m_email;
   }

EmailFile::EmailFile() 
{
    m_emailLines = nullptr;
    m_filename = nullptr;
    m_noOfEmails = 0;
    setEmpty();
}

 void EmailFile::setEmpty() //o
    {
        delete[] m_emailLines;
        delete[] m_filename;
        m_emailLines = nullptr;
        m_filename = nullptr;
        m_noOfEmails = 0;
    }

void EmailFile::setFilename(const char* filename) //o
    {
        delete[] m_filename;
        m_filename = nullptr;
        if (filename)
        {
            m_filename = new char[strlen(filename) + 1];
            m_filename[0] = '\0';
            strcpy(m_filename, filename);
        }
    }


 bool EmailFile::setNoOfEmails() {//o

        bool isValid = false;
        std::ifstream file(m_filename);

        if (!file.is_open()) {
            std::cout << "Failed to open file: " << m_filename << std::endl;
        }
        else
        {
            m_noOfEmails = 0;
            while (file) {
                m_noOfEmails += (file.get() == '\n');
            }
            file.close();

            if (m_noOfEmails == 0)
            {
                delete[] m_filename;
                m_filename = nullptr;
            }
            else {
                m_noOfEmails++;
                isValid = true;
            }
        }
        return isValid;
    }

void EmailFile::loadEmails() {
    if (!m_filename || m_noOfEmails <= 0) return; // if the file name is null or number of emails is less than equals to zero  it does nothing

    std::ifstream in(m_filename); //open file name 
    if (!in) return; // if file cant be opened function would exit 

    delete[] m_emailLines;
    m_emailLines = new Email[m_noOfEmails];
    
    int emailsLoad = 0;
    for (; emailsLoad < m_noOfEmails && !in.eof(); ++emailsLoad) {
        if (!m_emailLines[emailsLoad].load(in)) {
            break;
        }
    }
    if (emailsLoad < m_noOfEmails) {
        m_noOfEmails = emailsLoad;
    }
}


EmailFile::EmailFile(const char* filename) {
    if (filename == nullptr) { // if input argument is nullptr
        setEmpty(); // sets the EmailFile object to a safe empty state
    } else { //otherwise
        setFilename(filename); //it will set file name 
        if (setNoOfEmails()) { 
            loadEmails(); // and finally load the emails
        }
    }
}

bool EmailFile::saveToFile(const char* filename) const {
    std::ofstream out(filename);
    if (!out) return false;
    for (int i = 0; i < m_noOfEmails; i++) {
        out << m_emailLines[i].m_email << ',' << m_emailLines[i].m_name << ',' << m_emailLines[i].m_year << '\n';
    }
    return true;
}


void EmailFile::fileCat(const EmailFile& obj, const char* name)
 {
    if (!m_filename || m_noOfEmails <= 0 || !obj.m_filename || obj.m_noOfEmails <= 0) {
         return;
    }

    int totalEmails = m_noOfEmails + obj.m_noOfEmails;
    Email* temp = new Email[totalEmails];
    for (int i = 0; i < m_noOfEmails; i++) {
        temp[i] = m_emailLines[i];
    }
    for (int i = 0; i < obj.m_noOfEmails; i++) {
        temp[m_noOfEmails + i] = obj.m_emailLines[i];
    }
    delete[] m_emailLines;
    m_emailLines = temp;
    m_noOfEmails = totalEmails;
    if (name != nullptr) {
        setFilename(name);
    }
    saveToFile(m_filename);
}


std::ostream& EmailFile::view(std::ostream& ostr) const //o
    {
        if (m_filename) {
            ostr << m_filename << std::endl;
            ostr.width(strlen(m_filename));
            ostr.fill('=');
            ostr << "=" << std::endl;
            ostr.fill(' ');
            for (int i = 0; i < m_noOfEmails; i++) {
                ostr.width(35);
                ostr.setf(std::ios::left);
                ostr << m_emailLines[i].m_email;
                ostr.width(25);
                ostr << m_emailLines[i].m_name;
                ostr << "Year = " << m_emailLines[i].m_year << std::endl;
            }
        }

            return ostr;
}


EmailFile::EmailFile(const EmailFile& src)
{
    *this = src;
}

EmailFile& EmailFile::operator=(const EmailFile& rhs) {
    if (this != &rhs) {
        setEmpty();
        setFilename(rhs.m_filename);
        if (rhs.m_noOfEmails > 0) {
            m_emailLines = new Email[rhs.m_noOfEmails];
            m_noOfEmails = rhs.m_noOfEmails;
            for (int i = 0; i < m_noOfEmails; i++) {
                m_emailLines[i] = rhs.m_emailLines[i];
            }
        }
    }
    return *this;
}

EmailFile::operator bool() const { 
    return m_filename != nullptr && m_noOfEmails > 0;
}

EmailFile::~EmailFile() {//destructor
    setEmpty();
}
std::ostream& operator<<(std::ostream& ostr, const EmailFile& text)  //o
{
    return text.view(ostr);
}

} 


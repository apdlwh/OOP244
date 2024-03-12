#ifndef SENECA_EMAILFILE_H
#define SENECA_EMAILFILE_H

#include <iostream>
#include <fstream>

namespace seneca {

const int BUFFER_SIZE = 1024; // Maximum possible size for all the fields of the Email record


class EmailFile;

class Email {
    char* m_email{ nullptr }; // holds the address of the dynamically allocated Cstring to hold the email address
    char* m_name{ nullptr };
    char m_year[5];
    friend class EmailFile; // make the emailFile class a friend of the email class
public:
    Email();
    Email(const Email&) = delete; // prohibits the copy constructor
    Email& operator=(const Email&); // copy assignment operator 
	bool load(std::ifstream& in);
    ~Email();
    
};

class EmailFile {
    Email* m_emailLines{ nullptr };
    char* m_filename{};
    int m_noOfEmails{ 0 };
    void setFilename(const char* filename);
    void setEmpty();
    bool setNoOfEmails();
    void loadEmails();
public:
	
	operator bool() const;
    EmailFile();
    EmailFile(const char* filename);
    EmailFile(const EmailFile& src);
    EmailFile& operator=(const EmailFile& rhs);
    ~EmailFile();
    bool saveToFile(const char* filename) const;
    void fileCat(const EmailFile& obj, const char* name = nullptr);
    std::ostream& view(std::ostream& ostr) const;
        
};

    std::ostream& operator<<(std::ostream& ostr, const EmailFile& text);
}

#endif


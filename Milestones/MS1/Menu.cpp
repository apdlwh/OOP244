#include "Menu.h"
#include <limits>
namespace seneca {


    Menu::Menu(const char* menuContent, int numberOfTabs)
    {
        m_numTabs = numberOfTabs;
        m_numOptions = 0;

        if(menuContent != nullptr) {
            m_text = new char[std::strlen(menuContent) + 1];
            std::strcpy(m_text, menuContent);

            for(const char* p = menuContent; *p; p++) {
                if (*p == '\n') {
                    m_numOptions++;
                }
            }
        } else {
            m_text = nullptr;
        }
    }


    Menu::~Menu()
    {
        delete[] m_text;
    }
   
void Menu::display() const {
    if (m_text != nullptr) {
        if (m_numTabs > 0) {
            for (int i = 0; i < m_numTabs; i++) {
                std::cout << "   ";
            }
        }
        for (int i = 0; m_text[i] != '\0'; i++) {
            std::cout << m_text[i];
            if (m_text[i] == '\n' && m_text[i+1] != '\0') { 
                for (int j = 0; j < m_numTabs; j++) {
                    std::cout << "   ";
                }
            }
        }
    }

    std::cout << std::endl;
    if (m_numTabs > 0) {
        for (int i = 0; i < m_numTabs; i++) {
            std::cout << "   ";
        }
    }
    std::cout << "0- Exit" << std::endl;
    if (m_numTabs > 0) {
        for (int i = 0; i < m_numTabs; i++) {
            std::cout << "   ";
        }
    }
    std::cout << "> ";
}



int& Menu::operator>>(int& selection)
{
     display(); 
    while (true) { 
        std::cin >> selection;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Bad integer value, try again: ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            if (std::cin.gcount() > 1) { 
                std::cout << "Only enter an integer, try again: ";
            } else if (selection < 0 || selection > m_numOptions) { 
                std::cout << "Invalid value enterd, retry[0 <= value <= " << m_numOptions << "]: ";
            } else {
                break; 
            }
        }
    }

    return selection;
}


}

   


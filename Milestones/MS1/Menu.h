#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <cstring>

namespace seneca{
class Menu{
private:
   char* m_text;
   int m_numOptions;
   int m_numTabs;

   Menu(const Menu& other) = delete; //prevents copy
   Menu& operator=(const Menu& other) = delete; //and assignment 

public:

    Menu(const char* menuContent, int numberOfTabs = 0);
    ~Menu();
    void display() const;
    int& operator>>(int& selection);


 
};








}
#endif

#include "LibraryItem.h"

namespace seneca{

     LibraryItem::LibraryItem()
     {
     m_title = nullptr;
     m_year = 0;
     }

     LibraryItem::LibraryItem(const char* title, int year)
     {
     m_title = new char [strlen(title) + 1];
     strcpy(m_title, title);
     m_year = year;
     }

     LibraryItem::LibraryItem(const LibraryItem& other) // deep copy of title
     {
     if (other.m_title)
     {
     m_title = new char[strlen(other.m_title)+ 1];
     strcpy(m_title, other.m_title);
     }
     else
     {
     m_title = nullptr;
     }
     m_year = other.m_year;
     }

     LibraryItem& LibraryItem::operator=(const LibraryItem& other) // deep copies 
     {
     if (this != &other) // this prevents slef-assignmnt
     {
     delete[] m_title;
     if(other.m_title)
         {
         m_title = new char[strlen(other.m_title) + 1];
         strcpy(m_title, other.m_title);
         }
     else
         {
         m_title = nullptr;
         }
     m_year = other.m_year;
     }
     return *this;
     }

     LibraryItem::~LibraryItem()
     {
     delete[] m_title;
     }

     std::ostream& LibraryItem::display(std::ostream& ostr) const 
     {
     ostr << "Title: " << (m_title ? m_title : "Unknown") << " (" << m_year << ")";
     return ostr;
     }

}

#include "Book.h"

namespace seneca{
     Book::Book(const char* title, int year, const char* author) : LibraryItem(title, year)
     {
     m_author = new char[strlen(author) + 1];
     strcpy(m_author, author);
     }

     Book::Book(const Book& other) : LibraryItem(other) //deep copy of author
     {
     if (other.m_author)
     {
     m_author = new char[strlen(other.m_author) + 1];
     strcpy(m_author, other.m_author);
     }
     else
     {
     m_author = nullptr;
     }
     }

     Book& Book::operator=(const Book& other) // deep copy of author and the base
     {
     if (this != &other)
     {
     LibraryItem::operator=(other);
     delete[] m_author;
     if (other.m_author)
         {
         m_author = new char[strlen(other.m_author) + 1];
         strcpy(m_author, other.m_author);
         }
     else 
         {
         m_author = nullptr;
         }

     }
     return *this;
     }

     Book::~Book()
     {
     delete[] m_author;
     }

     std::ostream& Book::display(std::ostream& ostr) const
     {
     LibraryItem::display(ostr) << std::endl;
     ostr << "Author: " << (m_author ? m_author: "Unknown");
     return ostr;
     }

     bool Book::operator>(const Book& other) const
     {
     return m_author && other.m_author && strcmp(m_author, other.m_author) > 0;
     }
}

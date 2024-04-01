#ifndef BOOK_H
#define BOOK_H
#include "LibraryItem.h"

namespace seneca{
class Book : public LibraryItem
{
private:
     char* m_author;
public:
     Book(const char* title, int year, const char* author);
     Book(const Book& other);
     Book& operator=(const Book& other);
     ~Book();

     std::ostream& display(std::ostream& ostr = std::cout) const override;
     bool operator>(const Book& other) const;
};
}
#endif

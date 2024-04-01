#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H
#include <iostream>
#include <cstring>

namespace seneca{

class LibraryItem{
protected:
     char* m_title;
     int m_year;
public:
     LibraryItem();
     LibraryItem(const char* title, int year);
     LibraryItem(const LibraryItem& other);
     LibraryItem& operator=(const LibraryItem& other);
     virtual ~LibraryItem();
     virtual std::ostream& display(std::ostream& ostr = std::cout) const;
};

}
#endif

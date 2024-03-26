#ifndef IOABLE_H
#define IOABLE_H
#include <iostream>
namespace seneca{

class IOAble{

public:
     virtual ~IOAble() {}
     virtual std::ostream& write(std::ostream& os) const = 0;
     virtual std::istream& read(std::istream& is) = 0;
};
     
     std::ostream& operator<<(std::ostream& os, const IOAble& io);
     std::istream& operator>>(std::istream& is, IOAble& io);
    
}

#endif

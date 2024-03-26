#include "IOAble.h"

namespace seneca {

    std::ostream& operator<<(std::ostream& os, const IOAble& io)
    {
        return io.write(os);
    }
    std::istream& operator>>(std::istream& is, IOAble& io) 
    {
        return io.read(is);
    }


}

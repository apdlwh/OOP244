#include "Time.h"
#include "Utils.h"
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
namespace seneca{


Time& Time::reset()
{
    minutes = U.getTime();
    return *this;
}

Time::Time(unsigned int min) //constructor 
{
    minutes = min;
}

std::ostream& Time::write(std::ostream& ostr) const 
{
    ostr << std::setw(2) << std::setfill('0') << minutes / 60 << ":" << std::setw(2) << std::setfill('0') << minutes % 60;
    return ostr;
} // setw(2) is used for setting field width to 2 characters. (ensures next value occupies atleast 2 char)
// if next output operation is less than the width set "0" will be used to fill in extra space

  std::istream& Time::read(std::istream& istr) {
        int hours = 0, mins = 0;
        char colon;
        std::string lineInput;

 while (true) { 
     if (std::getline(istr, lineInput)) {
       std::istringstream lineStream(lineInput);
         if (lineStream >> hours >> colon && colon == ':' && lineStream >> mins) {
         if (hours >= 0 && mins >= 0) {
          hours += mins / 60;
        mins %= 60;
        minutes = static_cast<unsigned int>(hours * 60 + mins);
        break; 
        } else {
        std::cerr << "Bad time entry, retry (HH:MM): ";}
        } else {
        std::cerr << "Bad time entry, retry (HH:MM): ";
    }
    } else {
        istr.setstate(std::ios::failbit);
    break;
            }
        }
        return istr;
    } //i spent 5 hours trying to debug this lil shit. i had ask help from friends. but it does the same..... idk i give on this function



Time::operator unsigned int() const 
{
    return minutes;
}

Time& Time::operator*= (int val)
{
    minutes *= val;
    return *this;
}

Time& Time::operator-= (const Time& D)
{
 if (minutes < D.minutes) {
    minutes += 1440; 
 }
 minutes -= D.minutes;
 return *this;
}

Time Time::operator-(const Time& T) const
{
    Time temp(*this); //preserve original state
    temp -= T;
    return temp;
}

std::ostream& operator<<(std::ostream& ostr, const Time& time)
{
    return time.write(ostr);
}

std::istream& operator>>(std::istream& istr, Time& time)
{
    return time.read(istr);
}

}

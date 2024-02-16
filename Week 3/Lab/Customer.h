#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Car.h"

namespace seneca{

class Customer{
private: 
    int m_id;
    char* m_name;
    const Car* m_car;

public:
Customer();
~Customer();

    bool isEmpty() const;
    void setEmpty();
    void deallocateMemory();
    void set(int customerID, const char* name, const Car* car);
    void display() const;
    const Car& car() const;

    };
}

#endif

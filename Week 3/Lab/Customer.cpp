#include "Customer.h"
#include "Car.h"
#include <iostream>
#include <cstring>
#include <iomanip>



namespace seneca{


Customer::Customer(): m_id(0), m_name(nullptr), m_car(nullptr){
   
}

Customer::~Customer(){
    deallocateMemory();
}

bool Customer::isEmpty() const{
return m_name == nullptr || strlen(m_name) == 0 || m_car == nullptr;

}

void Customer::setEmpty() {
m_id = 0;
deallocateMemory();
m_name = nullptr;
m_car = nullptr;
}

void Customer::deallocateMemory() {
 if (m_name != nullptr) {
    delete[] m_name;
    m_name = nullptr;
}

}

void Customer::set(int customerID, const char* name, const Car* car){
    deallocateMemory();

    if(name != nullptr && strlen(name) > 0 && car != nullptr) {
        m_id = customerID;
        m_name = new char[strlen(name) + 1];
        strcpy(m_name, name);
        m_car = car;
    } else {
        setEmpty();
    }
}

void Customer::display() const {
    if (!isEmpty()) {
        std::cout << std::left << std::setw(15) << "Customer ID:" << std::right << std::setw(20) << m_id << std::endl
                  << std::left << std::setw(15) << "First Name:" << std::right << std::setw(20) << (m_name ? m_name : "N/A") << std::endl;

        if (m_car) {
            m_car ->display();
       }

}
}

const Car& Customer::car()const {
    return *m_car;
}



}//

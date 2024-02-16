#include "Car.h"
#include <iostream>
#include <cstring>
#include <iomanip>

namespace seneca{

Car::Car() {
   setEmpty();
}

Car::~Car(){
    deallocateMemory(); //2.2 clean up the DA memory 
}

/*Member function to check if the object is in a safe recognizable 
empty state. A car is considered empty if the either "make and model"
 or "service description" is either null or an empty cstring. */
bool Car::isEmpty() const{
return m_makeModel == nullptr || m_serviceDesc == nullptr || strlen(m_makeModel) == 0 || strlen(m_serviceDesc) == 0;
}

/*Member function sets the object a safe recognizable empty state.
 setEmpty accomplishes this by setting the attributes to empty cstring, nullptr and 0.0. */
void Car::setEmpty() {
m_makeModel = nullptr;
m_serviceDesc = nullptr;
m_licensePlate[0] = '\0';
m_cost = 0.0;
}

/*Member function to deallocate dynamically allocated memory for
 "make and model" and "service description" member variables.*/
void Car::deallocateMemory() {

if (m_makeModel != nullptr) {
    delete[] m_makeModel;
    m_makeModel = nullptr;
}
if (m_serviceDesc != nullptr) {
    delete[] m_serviceDesc;
    m_serviceDesc = nullptr;
}

}

/*Member function to Set car information and service details as follows.
1.Deallocates existing memory and then sets it to a safe empty state.

If the incoming information is valid (license plate is not empty and "make and model" and "description" 
are not null and not empty. note: the cost is not validated).

-2. copies the corresponding argument to the license plate attribute
-3. Allocates memory and copies the data for car make and model
-4. Allocates memory and copies the date for the service description
-5. Assigns the 'serviceCost' value to the corresponding argument value.*/
void Car::set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost) {

// 1
setEmpty();
// char plateNo treated as pointer(string array)
if (plateNo != nullptr && strlen(plateNo) < 9 && 
    carMakeModel && strlen(carMakeModel) > 0 && 
    serviceDesc && strlen(serviceDesc) > 0) {

    strncpy(m_licensePlate, plateNo, 8); // 2 (dest, source, size)
    m_licensePlate[8] = '\0'; //safety null termination

    // deallocateMemory(); // release any memory to avoid memory leaks before we prepare for new data

    m_serviceDesc = new char[strlen(serviceDesc) + 1]; // 3. + 1 for null terminator
    strcpy(m_serviceDesc, serviceDesc);

    m_makeModel = new char[strlen(carMakeModel) + 1]; // 4
    strcpy(m_makeModel, carMakeModel);

    m_cost = serviceCost;
} else {
    setEmpty();
}

}


void Car::display() const {
    if(!isEmpty()) {

    std::cout << std::left << std::setw(15) << "License Plate:" << std::right << std::setw(20) << m_licensePlate << std::endl;
    std::cout << std::left << std::setw(15) << "Model:" << std::right << std::setw(20) << m_makeModel << std::endl;
    std::cout << std::left << std::setw(15) << "Service Name:" << std::right << std::setw(20) << m_serviceDesc << std::endl;
    std::cout << std::left << std::setw(15) << "Service Cost:" << std::right << std::setw(20) << std::fixed << std::setprecision(2) << m_cost << std::endl;
} 

    }

} // namespace

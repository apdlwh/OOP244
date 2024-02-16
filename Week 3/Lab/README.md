Part 1 - LAB (50%)

Your task for Workshop 3 Part 1 is to create a C++ program for a car service shop that offers different maintenance services. The program should consist of three modules:

Car.cpp
Customer.cpp
main.cpp (tester)
The car service shop needs to maintain information about customers and their cars, including the following information:

Car, including license plate, make and model, service description, and cost.
Customer, containing an ID, name, and an address pointing to their Car.
Car class

The Car class is typically defined in a header file named Car.h and implemented in a corresponding source file and must keep the following information:

Private data members

m_licencePlate: a maximum 8-character long Cstring
m_makeModel: that holds make and model dynamically in a C string. (char *)
m_serviceDesc: that holds the service description dynamically in a C string. (char *)
m_cost: a double variable for the cost of the service
Public methods

bool isEmpty() const;
Member function to check if the object is in a safe recognizable empty state. A car is considered empty if the either "make and model" or "service description" is either null or an empty cstring.

void setEmpty();
Member function sets the object a safe recognizable empty state. setEmpty accomplishes this by setting the attributes to empty cstring, nullptr and 0.0.

void deallocateMemory();
Member function to deallocate dynamically allocated memory for "make and model" and "service description" member variables.

void set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost);
Member function to Set car information and service details as follows.

Deallocates existing memory and then sets it to a safe empty state.
If the incoming information is valid (license plate is not empty and "make and model" and "description" are not null and not empty. note: the cost is not validated)
Copies the corresponding argument to the license plate attribute
Allocates memory and copies the data for car make and model
Allocates memory and copies the date for the service description
Assigns the 'serviceCost' value to the corresponding argument value.
void display() const;
This function displays the car in the following format:

The labels of the data are left justified in 15 spaces.
The data of the attributes are right justified in 20 spaces.
The cost is displayed with 2 digits after the decimal point.
License Plate:                  ABC
Model:                 Toyota Camry
Service Name:     Engine oil change
Service Cost:                 50.00
Customer class

The Customer class is typically defined in a header file named Customer.h and implemented in a corresponding source file and must keep the following information:

Private data members

m_id: an integer holds the customer ID
m_name: that is held dynamically in a C string. (char *)
m_car: that is a pointer to an unmodifiable Car object. (customer's car).
Note that this is not dynamically allocated. It is only a pointer to be set to the address of a "Car" object that exists somewhere.
Public methods

The Customer class has the following Private function:

bool isEmpty() const;
This query method checks if the object is in a safe empty state. A customer is considered empty if the name pointer is null or empty cString or the car pointer is null.

void setEmpty();
This method sets the customer to a safe empty state by setting the pointers to null and the id to 0.

void deallocateMemory();
This Member function deallocates the dynamically allocated memory for the m_name member variable.

void set(int customerId, const char* name, const Car* car);
Member function to Set the Customer name, ID and Car.

Deallocates existing memory and then sets it to a safe empty state.
If the incoming information is valid (i.e. the name is not null and not empty and the Car pointer is not null. The ID is not validated)
Copies the corresponding argument to the ID attribute
Allocates memory and copies the data for the name of the customer
Assigns the Car pointer attribute to the corresponding argument
void display() const;
This function displays the Customer in the following format:

The labels of the data are left justified in 15 spaces.
The data of the attributes are right justified in 20 spaces. After the customer information is printed, the Car will be displayed.
  Customer ID:                   1005
  First Name:              Jane Smith
  License Plate:                  ABC
  Model:                 Toyota Camry
  Service Name:     Engine oil change
  Service Cost:                 50.00
V1.1

const Car& car()const;
This function returns the car object pointed to by m_car pointer by dereferencing it. There is no need to validate the pointer prior to dereferencing. It can be assumed to be valid.

The Tester Program

main.cpp

This module is fully provided. Please do not change it. Please review it and make sure you understand how the functions that you have developed are being used.

Expected output

correct_output.txt



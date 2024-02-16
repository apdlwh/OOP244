#ifndef CAR_H
#define CAR_H

namespace seneca {

class Car{
private:
     char m_licensePlate[9];
     char* m_makeModel;
     char* m_serviceDesc;
     double m_cost;

public:

Car();
~Car();   
     bool isEmpty() const; // ember function to check if the object is in a safe recognizable empty state. A car is considered empty if the either "make and model" or "service description" is either null or an empty cstring.
     void setEmpty(); 
     void deallocateMemory();
     void set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost);
     void display() const;
};


}

#endif

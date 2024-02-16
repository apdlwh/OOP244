#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include "Fridge.h"

namespace seneca {


Food::Food() {}

Food::Food(const char* nm, int wei) {
    strncpy(m_name, nm, NAME_LEN - 1);
    m_name[NAME_LEN - 1] = '\0';
    m_weight = wei;
}

const char* Food::name() const {
    return m_name;
}

int Food::weight() const {
    return m_weight;
}


Fridge::Fridge() : m_numFoods(0), m_model(nullptr) {}

Fridge::Fridge(Food farr[], int nf, const char* mod) : Fridge() { 
    if (nf > 0 && mod != nullptr && std::strlen(mod) > 0) {
        m_numFoods = (nf < FRIDGE_CAP) ? nf : FRIDGE_CAP;
        m_model = new char[std::strlen(mod) + 1];
        std::strcpy(m_model, mod);
        for (int i = 0; i < m_numFoods; ++i) {
            m_foods[i] = farr[i];
        }
    }
}

Fridge::~Fridge() {
    delete[] m_model;
}

bool Fridge::addFood(const Food& f) {
    if (m_numFoods < FRIDGE_CAP) {
        m_foods[m_numFoods++] = f;
        return true;
    }
    return false;
}

void Fridge::changeModel(const char* m) {
    if (m != nullptr && std::strlen(m) > 0) {
        delete[] m_model;
        m_model = new char[std::strlen(m) + 1];
        std::strcpy(m_model, m);
    }
}

bool Fridge::fullFridge() const {
    return m_numFoods == FRIDGE_CAP;
}

bool Fridge::findFood(const char* f) const {
    for (int i = 0; i < m_numFoods; ++i) {
        if (std::strcmp(m_foods[i].name(), f) == 0) {
            return true;
        }
    }
    return false;
}

std::ostream& Fridge::display(std::ostream& os) const {
    if (m_model == nullptr || std::strlen(m_model) == 0) return os;

    os << "Fridge Model: " << m_model << std::endl;
    os << "Food count: " << m_numFoods << " Capacity: " << FRIDGE_CAP << std::endl;
    os << "List of Foods" << std::endl;
    for (int i = 0; i < m_numFoods; ++i) {
        int spacesBeforeName = 20 - std::strlen(m_foods[i].name()); 
        os << std::string(spacesBeforeName, ' ') << m_foods[i].name() << " | " << m_foods[i].weight() << std::endl;
    }

    return os;
}

}


#include "Guitar.h"
#include <iomanip> 

namespace seneca{
    
    GuitarStr::GuitarStr(){ 
        m_gauge = 0.0; //GuitarStr safety constructor
        m_material[0] = '\0';
    }

    GuitarStr::GuitarStr(const char* ma, double ga) {
        strncpy(m_material, ma, MAT_LEN - 1); // copy from ma to m_material
        m_material[MAT_LEN - 1] = '\0'; // sets last char to null terminator
        m_gauge = ga;
    }

    const char* GuitarStr::material() const {
        return m_material;
    }

    double GuitarStr::gauge() const {
        return m_gauge;
    }

    
    Guitar::Guitar(const char* mod) {
        m_strings = nullptr;
        m_numStrings = 0;
        strncpy(m_model, mod, 15);
        m_model[15] = '\0';
    }



//asdjnajadjafak bleh
    Guitar::Guitar(GuitarStr strs[], int ns, const char* mod) {
        m_numStrings = ns;
        strncpy(m_model, mod, 15);
        m_model[15] = '\0';
        m_strings = new GuitarStr[ns];
        for (int i = 0; i < ns; ++i) {
            m_strings[i] = strs[i];
        }
    }

    Guitar::~Guitar() {
        delete[] m_strings;
    }

    bool Guitar::changeString(const GuitarStr& gs, int sn) {
        if (sn >= 0 && sn < m_numStrings) {
            m_strings[sn] = gs;     // changing string [sn] to [gs]  ?
            return true;
        }
        return false;
    }

    void Guitar::reString(GuitarStr strs[], int ns) {
        delete[] m_strings;                          
        m_strings = new GuitarStr[ns];    //EDIT: Hi cass, if you see this, would it be pliable to make a helper function to avoid redundancy here?
        m_numStrings = ns;               // 
        for (int i = 0; i < ns; ++i) {
            m_strings[i] = strs[i];
        }
    }

    void Guitar::deString() {
        delete[] m_strings;
        m_strings = nullptr;
        m_numStrings = 0;
    }

    bool Guitar::strung() const {
        return m_numStrings > 0;
    }

    bool Guitar::matchGauge(double ga) const {
        for (int i = 0; i < m_numStrings; ++i) {
            if (m_strings[i].gauge() == ga) return true;
        }
        return false;
    }



   std::ostream& Guitar::display(std::ostream& os) const {
    if (m_numStrings == 0) {
        os << "***Empty Guitar***\n";
    } else {
        os << "Guitar Model: " << m_model << "\nStrings: " << m_numStrings << "\n";
        for (int i = 0; i < m_numStrings; ++i) {
            
            int spaces = 10 - std::strlen(m_strings[i].material());  // had to ask for help on this. got a little stuck trying to match the output
            os << "#" << (i + 1);
            for (int j = 0; j < spaces; ++j) {
                os << " "; 
            }
            os << m_strings[i].material() << " | " 
               << std::fixed << std::setprecision(1) << m_strings[i].gauge() << "\n";
        }
    }   
    return os;  
    }


}

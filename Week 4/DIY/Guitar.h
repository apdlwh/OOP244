#ifndef GUITAR_H
#define GUITAR_H

#include <iostream>
#include <cstring>
#define MAT_LEN 10


namespace seneca {
    

    class GuitarStr {
        char m_material[MAT_LEN]{};
        double m_gauge;
    public:
        GuitarStr();
        GuitarStr(const char* ma, double ga);
        const char* material() const;
        double gauge() const;
    };

    class Guitar {
        GuitarStr* m_strings; //dynamic array of GuitarStr
        int m_numStrings; //number of GuitarStr in the array
        char m_model[16]; // model name for guitar. max 15 char.

    public:
        Guitar(const char* mod = "Stratocaster");
        Guitar(GuitarStr strs[], int ns, const char* mod);
        ~Guitar();

        bool changeString(const GuitarStr& gs, int sn);
        void reString(GuitarStr strs[], int ns);
        void deString();
        bool strung() const;
        bool matchGauge(double ga) const;
        std::ostream& display(std::ostream& os = std::cout) const;
    };
}

#endif 

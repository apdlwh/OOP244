#include "Assessment.h"
#include <cstring> 

namespace seneca {

    bool read(int& value, FILE* fptr) {
        return fscanf(fptr, "%d", &value) == 1;
    }

    bool read(double& value, FILE* fptr) {
        return fscanf(fptr, "%lf", &value) == 1;
    }

    bool read(char* cstr, FILE* fptr) {
        return fscanf(fptr, ",%60[^\n]\n", cstr) == 1;
    }

    bool read(Assessment& assess, FILE* fptr) {
        double tempMark;
        char tempTitle[61];

        if (read(tempMark, fptr) && read(tempTitle, fptr)) {
            assess.m_mark = new double(tempMark);

            assess.m_title = new char[strlen(tempTitle) + 1];
            strcpy(assess.m_title, tempTitle);

            return true;
        }
        return false;
    }

    void freeMem(Assessment*& aptr, int size) {
        for (int i = 0; i < size; ++i) {
            delete aptr[i].m_mark;
            delete[] aptr[i].m_title;
        }
        delete[] aptr;
        aptr = nullptr;
    }

    int read(Assessment*& aptr, FILE* fptr) {
        int numRecords;
        if (!read(numRecords, fptr)) return 0;

        aptr = new Assessment[numRecords];
        int i;
        for (i = 0; i < numRecords && read(aptr[i], fptr); ++i);

        if (i != numRecords) {
            freeMem(aptr, i);
            return 0;
        }

        return numRecords;
    }

} // namespace seneca


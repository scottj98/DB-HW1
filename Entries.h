//
// Created by Scott on 2/5/2020.
//

#ifndef HW1_ENTRIES_H
#define HW1_ENTRIES_H

#include <fstream>
using namespace std;

class Entries
{
    public:
        Entries();
        Entries(const Entries &newEntries);
        ~Entries();

        void setEntries(string Company, string Rank, string City, string State, string Zip, string Employees);
        void Read(fstream &dinout);
        void Write(fstream &dinout);
        void Print();

    private:
        string company, rank, city, state, zip, employees;
};


#endif //HW1_ENTRIES_H

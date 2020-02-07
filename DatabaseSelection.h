//
// Created by Scott on 2/5/2020.
//

#ifndef HW1_DATABASESELECTION_H
#define HW1_DATABASESELECTION_H

#include "Entries.h"
#include <string>
using namespace std;

class DatabaseSelection
{
    public:
        DatabaseSelection();
        DatabaseSelection(const DatabaseSelection &newDatabase);
        ~DatabaseSelection();

        bool openDB();
        void closeDB();
        void displayRecord();
        void updateRecord();
        void createReport();
        void addRecord();
        void deleteRecord();
        void quitDB();

    protected:
        bool getRecord(ifstream &din, const int recordNum, string &rank, string &company, string &city, string &state, string &zip, string &employees);
        int binarySearch(ifstream &din, const string company, string &rank, string &city, string &state, string &zip, string &employees);

    private:
        static const int numFields = 6;
        static const int recordSize = 501;
        int Records;
        string entryNames[numFields];
        fstream dinout;
};


#endif //HW1_DATABASESELECTION_H

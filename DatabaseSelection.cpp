//
// Created by Scott on 2/5/2020.
//

#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "DatabaseSelection.h"

//Default Constructor
DatabaseSelection::DatabaseSelection()
{
    Records = 0;
    for (int i = 0; i < numFields; i++)
        entryNames[i] = "";
}

//Copy Constructor
DatabaseSelection::DatabaseSelection(const DatabaseSelection &OtherDatabaseSelection)
{
    Records = OtherDatabaseSelection.Records;
    for (int i = 0; i < numFields; i++)
        entryNames[i] = OtherDatabaseSelection.entryNames[i];
}

//Destructor
DatabaseSelection::~DatabaseSelection() {}

bool DatabaseSelection::openDB()
{
    bool success = false;
    ifstream ConInfo;
    ifstream Data;
    ifstream Oflow;

    dinout.open ("Fortune_500_HQ.csv");
    if(dinout.fail())
        cout << "Failed to open Fortune_500_HQ.csv" << endl;
    else
    {
        ConInfo.open("Fortune_500_HQ.config");
        if(ConInfo.fail())
            cout << "Failed to open Fortune_500_HQ.config" << endl;
        else
        {
            Data.open("Fortune_500_HQ.data");
            if(Data.fail())
                cout << "Failed to open Fortune_500_HQ.data" << endl;
            else
            {
                Oflow.open("Fortune_500_HQ.overflow");
                if(Oflow.fail())
                    cout << "Failed to open Fortune_500_HQ.overflow" << endl;
                else
                {
                    ConInfo >> Records;
                    for(int i = 0; i < numFields; i++)
                        ConInfo >> entryNames[i];
                    ConInfo.close();
                    success = true;
                }
            }
        }
    }
    return success;
}

void DatabaseSelection::closeDB()
{
    dinout.close();
}

void DatabaseSelection::displayRecord()
{
    string name;

    cout << "Enter Company's name: ";
    cin.ignore();
    getline(cin, name);
}

void DatabaseSelection::updateRecord()
{

}

void DatabaseSelection::createReport()
{
    Entries entry;

    entry.setEntries(entryNames[0], entryNames[1], entryNames[2], entryNames[3], entryNames[4], entryNames[5]);
    entry.Print();

    dinout.seekg(0);
    for (int i = 0; i < 10; i++)
    {
        entry.Read(dinout);
    }

    entry.Print();
}

void DatabaseSelection::addRecord()
{

}

void DatabaseSelection::deleteRecord()
{

}

/*bool DatabaseSelection::getRecord(ifstream &din, const int recordNum, string &rank, string &company, string &city,
                                  string &state, string &zip, string &employees)
{
    bool Success = false;

    if ((0 <= RecordNum) && (RecordNum < recordSize))
    {
        din.seekg(RecordNum * recordSize, ios::beg);
        din >> Id >> Experience >> Married >> Wage >> Industry;
        Success = true;
    }
    else
        cout << "Record " << RecordNum << " out of range.\n";

    return Success;
}

int DatabaseSelection::binarySearch(ifstream &din, const string company, string &rank, string &city, string &state,
                                    string &zip, string &employees)
{
    int Low = 0;
    int High = recordSize-1;
    int Middle;
    string MiddleId;
    bool Failure = false;

    bool Found = false;
    while (!Found && (High >= Low) && !Failure)
    {
        Middle = (Low + High) / 2;
        if (getRecord(din, Middle, MiddleId, Experience, Married, Wage, Industry))
        {
            if (MiddleId == Id)
                Found = true;
            else if (MiddleId < Id)
                Low = Middle + 1;
            else
                High = Middle -1;
        }
        else
        {
            cout << "Could not get record " << Middle << endl;
            Failure = true;
        }
    }
    if (Found)
        return Middle;  // the record number of the record
    else
        return -1;
}*/

void DatabaseSelection::quitDB()
{}
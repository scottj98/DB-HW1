//
// Created by Scott on 2/5/2020.
//

#include "Entries.h"
#include <iostream>
#include <algorithm>
using namespace std;

Entries::Entries()
{
    company = "";
    rank = "";
    city = "";
    state = "";
    zip = "";
    employees = "";
}

Entries::Entries(const Entries &newEntries)
{
    company = newEntries.company;
    rank = newEntries.rank;
    city = newEntries.city;
    state = newEntries.state;
    zip = newEntries.zip;
    employees = newEntries.employees;
}

Entries::~Entries() {}

void Entries::setEntries(string Company, string Rank, string City, string State, string Zip, string Employees)
{
    company = Company;
    rank = Rank;
    city = City;
    state = State;
    zip = Zip;
    employees = Employees;
}

void Entries::Read(fstream &dinout)
{
    dinout >> rank >> company >> city >> state >> zip >> employees;
    replace(company.begin(),company.end(), '_', ' ');
}

void Entries::Write(fstream &dinout)
{
    replace(company.begin(), company.end(), ' ', '_');
    dinout << rank << ' ' << company << ' ' << city << ' '
           << state << ' ' << zip << ' ' << employees << endl;
}

void Entries::Print()
{
    cout << rank << ' ' << company << ' ' << city << ' '
           << state << ' ' << zip << ' ' << employees << endl;
}

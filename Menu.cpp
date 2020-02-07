//
// Created by Scott on 2/6/2020.
//

#include <iostream>
#include <string>
#include "DatabaseSelection.h"
using namespace std;

int getChoice()
{
    int Choice;
    do
    {
        cout << "\n\nEnter '1' open the database\n"
             << "      '2' to display a record\n"
             << "      '3' to update a record\n"
             << "      '4' to create a report\n"
             << "      '5' to add a record\n"
             << "      '6' to delete a record\n"
             << "      '7' to quit the program\n"
             << "Selection: ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 7);
    return Choice;
}

int main()
{
    DatabaseSelection companies;
    int Choice;

    Choice = getChoice();
    cout << "You picked " << Choice << endl;
    while(Choice != 7)
    {
        switch (Choice)
        {
            case 1:   companies.openDB(); break;
            case 2:   companies.displayRecord(); break;
            case 3:   companies.updateRecord(); break;
            case 4:   companies.createReport(); break;
            case 5:   companies.addRecord(); break;
            case 6:   companies.deleteRecord(); break;
        }
        // Ask for next choice
        Choice = getChoice();
        cout << "You picked " << Choice << endl;
    }
    companies.quitDB();
    return 0;
}


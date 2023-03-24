//adam plankey

#include <iostream>
#include "PerferredCustomer.h"
#include "PersonData.h"
#include "CustomerData.h"

#include <vector>
using namespace std;

void PrintAllRecords(const vector<PersonData*>& records) {
    for (size_t i = 0; i < records.size(); i++) {
        records[i]->PrintRecord();
    }
}
void printallshortrecords(const vector<PersonData*>& records){
        for (size_t i = 0; i < records.size(); i++) {
        records[i]->PrintshortRecord();
        cout << endl;
    }
}

int main() {
    int number = 1;
    vector<PersonData*> p1;
    while(number >= 1 && number <= 6){
        cout << "1. Add Person" << endl;
        cout << "2. Add Customer" << endl;
        cout << "3. Add Preferred Customer" << endl;
        cout << "4. View Database Long Form" << endl;
        cout << "5. View Database Short Form" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter a number from the menu: ";
        cin >> number;

        switch(number){
            case 1:{
                PersonData* pd = new PersonData();
                pd->ReadData();
                p1.push_back(pd);
                break;
            }
            case 2:{
                CustomerData* p2 = new CustomerData();
                p2->ReadData();
                p1.push_back(p2);
                break;
            }
            case 3:{
                PreferredCustomer* p3 = new PreferredCustomer();
                p3->ReadData();
                p1.push_back(p3);
                break;
            }
            case 4:{
                PrintAllRecords(p1);
                break;
            }
            case 5:{
                printallshortrecords(p1);
                break;
            }
            case 6:
                number = 7;
                break;

            default:
                cout << "Invalid input." << endl;
                break;
        }
    }

    return 0;
}

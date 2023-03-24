//adam plankey

#ifndef CUSTOMER_DATA_H
#define CUSTOMER_DATA_H

#include <iostream>
#include <string>
#include "PersonData.h"

class CustomerData : public PersonData {
public:
    void setCustomerNumber(int num) {
        customerNumber = num;
    }
    void setMailingList(bool ml) {
        mailingList = ml;
    }
    int getCustomerNumber() const {
        return customerNumber;
    }
    bool getMailingList() const {
        return mailingList;
    }
    void PrintRecord() const override {
        PersonData::PrintRecord();
        std::cout << "Customer Number: " << customerNumber << std::endl;
        std::cout << "On the Mailing List: " << (mailingList ? "Yes" : "No") << std::endl;
    }

    void PrintshortRecord() const override{
        PersonData::PrintshortRecord();
        std::cout << "C#: " << customerNumber << " / " << "ML: " << (mailingList ? "Yes" : "No") << " / ";
    }
    std::string getRecord() const override {
        return PersonData::getRecord() + " / C#: " + std::to_string(customerNumber) + " / ML: " + (mailingList ? "Yes" : "No");
    }
    virtual void ReadData() {
        std::string first, last, addr, cty, st, zp, phn, mail;
        int cus;
        std::cin.sync();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter first name: ";
        std::getline(std::cin, first);
        std::cout << "Enter last name: ";
        std::getline(std::cin, last);
        std::cout << "Enter address: ";
        std::getline(std::cin, addr);
        std::cout << "Enter city: ";
        std::getline(std::cin, cty);
        std::cout << "Enter state: ";
        std::getline(std::cin, st);
        std::cout << "Enter zip: ";
        std::getline(std::cin, zp);
        std::cout << "Enter phone: ";
        std::getline(std::cin, phn);
        std::cout << "Input Customer Number: ";
        std::cin >> cus;
        std::cout << "Do they wish to be on the mailing list? (Y/N): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, mail);
        setCustomerNumber(cus);
        if (mail == "Y" || mail == "y") {
            setMailingList(true);
        } else {
            setMailingList(false);
        }
        setName(first, last);
        setAddress(addr, cty, st, zp);
        setPhone(phn);
    }

private:
    int customerNumber;
    bool mailingList;
};
#endif // CUSTOMER_DATA_H



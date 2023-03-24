//adam plankey

#ifndef PREFERRED_CUSTOMER_H
#define PREFERRED_CUSTOMER_H

#include "CustomerData.h"

class PreferredCustomer : public CustomerData {
public:
    PreferredCustomer(double purchasesAmount = 0.0) {
        setPurchasesAmount(purchasesAmount);
    }
    void setPurchasesAmount(double amount) {
        purchasesAmount = amount;
        if (purchasesAmount >= 2000.0) {
            discountLevel = 0.10;
        } else if (purchasesAmount >= 1500.0) {
            discountLevel = 0.07;
        } else if (purchasesAmount >= 1000.0) {
            discountLevel = 0.06;
        } else if (purchasesAmount >= 500.0) {
            discountLevel = 0.05;
        } else {
            discountLevel = 0.0;
        }
    }
    double getPurchasesAmount() const {
        return purchasesAmount;
    }
    double getDiscountLevel() const {
        return discountLevel;
    }
    void PrintRecord() const override {
        CustomerData::PrintRecord();
        std::cout << "Purchases Amount: $" << purchasesAmount << std::endl;
        std::cout << "Discount Level: " << (discountLevel * 100) << "%" << std::endl;
    }

    void PrintshortRecord() const override {
        CustomerData::PrintshortRecord();
        std::cout << "Account: " << purchasesAmount << " / " << (discountLevel * 100) << "%" << std::endl;
    }

    std::string getRecord() const override {
        return CustomerData::getRecord() + " / PA: $" + std::to_string(purchasesAmount) + " / DL: " + std::to_string(discountLevel);
    }
    virtual void ReadData() {
        std::string first, last, addr, cty, st, zp, phn, mail;
        int cusnum,purc;
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
        std::cin >> cusnum;
        std::cout << "Do they wish to be on the mailing list? (Y/N): ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, mail);

        do {
            std::cout << "Input Purchases Amount: ";
            std::cin >> purc;
        } while (purc < 0);
        
        if(mail == "Y"||mail=="y"){
            setMailingList(true);
        }else{
            setMailingList(false);
        }
        setCustomerNumber(cusnum);
        setPurchasesAmount(purc);
        setName(first, last);
        setAddress(addr, cty, st, zp);
        setPhone(phn);
    }

private:
    double purchasesAmount;
    double discountLevel;
};

#endif // PREFERRED_CUSTOMER_H

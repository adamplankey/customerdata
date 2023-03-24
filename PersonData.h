//adam plankey

#ifndef PERSONDATA_H
#define PERSONDATA_H
#include <limits>

#include <iostream>
#include <string>
#include <vector>

class PersonData {
public:

    void push_back(std::vector<PersonData*>& p1, PersonData* pd) {
        p1.push_back(pd);
    }

    void setName(std::string first, std::string last) {
        firstName = first;
        lastName = last;
    }
    void setAddress(std::string addr, std::string cty, std::string st, std::string zp) {
        address = addr;
        city = cty;
        state = st;
        zip = zp;
    }
    void setPhone(std::string phn) {
        phone = phn;
    }
    std::string getFirstName() const {
        return firstName;
    }
    std::string getLastName() const {
        return lastName;
    }
    std::string getAddress() const {
        return address;
    }
    std::string getCity() const {
        return city;
    }
    std::string getState() const {
        return state;
    }
    std::string getZip() const {
        return zip;
    }
    std::string getPhone() const {
        return phone;
    }
    virtual void PrintshortRecord() const{
        std::cout << firstName << " "<< lastName << " / " << address<< " / " << city << ","<< state << " " << zip << " / ";

    };


    virtual void PrintRecord() const {
        std::cout << lastName << ", " << firstName << std::endl;
        std::cout << address << std::endl;
        std::cout << city << ", " << state << " " << zip << std::endl;
        std::cout << phone << std::endl;
    }
    virtual std::string getRecord() const {
        return lastName + ", " + firstName + " / " + address + " / " + city + ", " + state + " " + zip + " / " + phone;
    }

virtual void ReadData() {
    std::string first, last, addr, cty, st, zp, phn;
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
    
    setName(first, last);
    setAddress(addr, cty, st, zp);
    setPhone(phn);
}



private:
    std::string lastName;
    std::string firstName;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
    std::string phone;
};

#endif // PERSONDATA_H

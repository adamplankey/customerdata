# customerdata
This repository contains a simple C++ program for maintaining a customer database. The program supports adding person, customer, and preferred customer records, as well as displaying records in long and short formats.

Files
PersonData.h: This header file contains the PersonData class, which stores basic information about a person, including name, address, and phone number.


CustomerData.h: This header file contains the CustomerData class, which inherits from PersonData and adds a customer number and a mailing list flag.


PreferredCustomer.h: This header file contains the PreferredCustomer class, which inherits from CustomerData and adds a purchase amount and a discount level based on the purchase amount.


main.cpp: The main source file containing the program's entry point and user interface. It allows users to add records, view records in long and short formats, and exit the program.

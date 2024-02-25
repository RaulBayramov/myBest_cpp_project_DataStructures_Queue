#include "Employee.h"
#include <iostream>
#include "Employee.h"
#include <iostream>
void userInterface() {
    EmployeePriorityQueue test;
    while (true) {
        cout << "*************************\n";
        cout << "     Personnel Management   \n";
        cout << "*************************\n";
        cout << "1. Add new employee\n";
        cout << "2. View employee information\n";
        cout << "3. Delete employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            // Add new employee function here
            //cout << "Function to add a new employee is not implemented yet.\n";
            test.push(createEmployee());
            break;
        }
        case 2: {
            // Add function to display employee information here
            //cout << "Function to display employee information is not implemented yet.\n";
            test.printQueue();
            break;
        }
        case 3: {
            // Add function to display employee information here
            test.pop();
            break;
        }
        case 4: {
            cout << "Exiting the program...\n";
            exit(0);
        }
        default: {
            cout << "Invalid option. Please choose a valid option.\n";
            break;
        }

        }
    }
}
int main() {
    userInterface();
	FrontendDeveloper f1("Raul", "12001099633", EmployeeClass::FD, 12, Level::Middle, new Technology(FrontendTechnology::Angular));
	EmployeePriorityQueue test;
	for (int i = 0; i < 10; i++) {
		test.push(createEmployee());
	}
	test.printQueue();
	test.pop();
	test.push(&f1);
	test.printQueue();
	test.printQueue();
	EmployeePriorityQueue AssigmentOperatorTest;
	AssigmentOperatorTest = test;
	AssigmentOperatorTest.printQueue();
	EmployeePriorityQueue CopyConstructorTest = test;
	CopyConstructorTest.printQueue();
	//deneme.push(&obj1); 

	return 0;
}

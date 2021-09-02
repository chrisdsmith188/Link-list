#ifndef EMPLOYEE_LIST_H
#define EMPLOYEE_LIST_H

#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
	// constructor
	Employee(int ID, string name, string department, int salary);
	
	friend class EmployeeList;

private:
	int ID;
	string name;
	string department;
	int salary;
	Employee* next;
};

class EmployeeList {
public:
	// constructor
	EmployeeList();

	// adds a new employee to the list based on salary from lowest to highest
	void addEmployee(int ID, string name, string department, int salary);
	// removes the employee using ID
	void removeEmployee(int ID);
	// prints all employees in (salary) order
	void print();
	// prints all employees whose department matches with the user input department
	void print(string department);
	// prints the employee with given input ID
	void print(int ID);
	// returns the number of employees in the list
	int getSize();
	// returns true if list empty, returns false otherwise
	bool isEmpty();

private:
	Employee* head;
	int size;
};

#endif

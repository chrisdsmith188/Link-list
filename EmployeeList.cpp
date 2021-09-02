#include "EmployeeList.h"

// constructor
Employee::Employee(int ID, string name, string department, int salary) {
	this->ID = ID;
	this->name = name;
	this->department = department;
	this->salary = salary;
	this->next = NULL;
}

// constructor
EmployeeList::EmployeeList() {
	head = NULL; 
	size = 0;
}

// adds a new employee to the list based on salary from lowest to highest
void EmployeeList::addEmployee(int ID, string name, string department, int salary) {
	Employee* employee = new Employee(ID, name, department, salary);
	Employee* current = head;
	Employee* previous = NULL;

	while (current != NULL) {
		if (current->salary >= salary)
			break;

		previous = current;
		current = current->next;
	}

	employee->next = current;

	if (previous == NULL)
		head = employee;
	else
		previous->next = employee;

	size++;
}

// removes the employee using ID
void EmployeeList::removeEmployee(int ID) {
	Employee* current = head;
	Employee* previous = NULL;

	while (current != NULL) {
		if (current->ID == ID) {
			if (previous == NULL)
				head = current->next;
			else
				previous->next = current->next;

			delete current;
			size--;
			return;
		}

		previous = current;
		current = current->next;
	}

	cout << "Error: ID not found" << endl;
}

// prints all employees in (salary) order
void EmployeeList::print() {
	Employee* current = head;

	while (current != NULL) {
		cout << current->ID << " " << current->name << " " << current->department 
			<< " " << current->salary << endl;
		current = current->next;
	}
}

// prints all employees whose department matches with the user input department
void EmployeeList::print(string department) {
	Employee* current = head;

	while (current != NULL) {
		if (current->department == department) {
			cout << current->ID << " " << current->name << " "
				<< current->department << " " << current->salary << endl;
		}

		current = current->next;
	}
}

// prints the employee with given input ID
void EmployeeList::print(int ID) {
	Employee* current = head;
	bool found = false;

	while (current != NULL) {
		if (current->ID == ID) {
			cout << current->ID << " " << current->name << " "
				<< current->department << " " << current->salary << endl;
			found = true;
		}

		current = current->next;
	}

	if (!found)
		cout << "Error: ID not found" << endl;
}

// returns the number of employees in the list
int EmployeeList::getSize() {
	return size;
}

// returns true if list empty, returns false otherwise
bool EmployeeList::isEmpty() {
	return (size == 0);
}

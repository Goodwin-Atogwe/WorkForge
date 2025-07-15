#include <iostream>
#include <iomanip>
#include "Employee.h"

void Employee::print() const {
	std::cout << "----------------------------------------------------" << "\n";
	std::cout << "Employee ID: " << employee_id << "\n";
	std::cout << "Full Name:   " << full_name << "\n";
	std::cout << "Job Title:   " << job_title << "\n";
	std::cout << "Department:  " << department << "\n";
	std::cout << "Salary:      " << std::fixed << std::setprecision(2) << salary << "\n";
	std::cout << "Date Hired:  " << date_hired << "\n";
	std::cout << "Created At:  " << created_at << "\n";
	std::cout << "Updated At:  " << updated_at << "\n";
	std::cout << "Is Active:   " << (is_active ? "Yes":"No") << "\n";
	std::cout << "----------------------------------------------------";
}
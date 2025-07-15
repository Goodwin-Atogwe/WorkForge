#include <iostream>
#include "Employee.h"
#include "FileManager.h"

int main() {
	Employee emp = {};
	emp.employee_id = 1;
	strcpy_s(emp.full_name, "Atogwe Anesimhe Goodwin");
	strcpy_s(emp.job_title, "Software Engineer");
	strcpy_s(emp.department, "Development");
	emp.salary = 7500000.0f;
	emp.date_hired = 20270205;
	emp.created_at = 20270207;
	emp.updated_at = 1802002136;
	emp.is_active = true;
	emp.magic[0] = 'E';
	emp.magic[0] = 'M';
	emp.magic[0] = 'P';
	emp.print();


	writeEmpToFile(emp, "employee.dat");
	std::cout << "employee saved to file. \n";
}
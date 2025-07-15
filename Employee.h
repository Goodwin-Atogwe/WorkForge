#ifndef EMPLOYEE_H
#define EMPLOYEE_H 

// Export/Import macro for dll usage 
#ifdef BUILDING_COREEMPLOYEE
	#define EMP_API __declspec(dllexport)
#else 
	#define EMP_API __declspec(dllimport)
#endif

#include <cstdint>

// 128bytes Employee object struct

struct  EMP_API Employee{
	int employee_id;
	char full_name[50];
	char job_title[30];
	char department[20];
	float salary;
	int date_hired; //(YYYYMMDD)
	int created_at; //(YYYYMMDD)
	int64_t updated_at; //unix timestamp
	bool is_active;
	char magic[3];

	void print() const;
};


#endif
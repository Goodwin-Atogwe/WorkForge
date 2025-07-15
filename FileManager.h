#ifndef FILEMANAGER_H
#define FILEMANAGER_H 

#include "Employee.h"

// Export/Import macro for dll usage 
#ifdef BUILDING_FILEMANAGER
#define FILE_API __declspec(dllexport)
#else 
#define FILE_API __declspec(dllimport)
#endif

FILE_API void writeEmpToFile(const Employee& emp, const char* filename);

#endif
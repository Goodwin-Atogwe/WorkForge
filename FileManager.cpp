#include "FileManager.h"
#include <fstream>
#include <iostream>

void writeEmpToFile(const Employee& emp, const char* filename) {
	std::ofstream outfile(filename, std::ios::binary | std::ios::app);
	if (outfile) {
		outfile.write(reinterpret_cast<const char*>(&emp), sizeof(Employee));
		outfile.close();
	}
	else {
		std::cerr << "Failed to open file: " << filename << "\n";
	}
}
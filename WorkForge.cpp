#include <iostream>

void drawHeader(const char* hName) {
    std::cout << "------------------------------------------------------------\n";
    std::cout << "------------------------------------------------------------\n";
    std::cout << "\t\t" << hName;
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "------------------------------------------------------------\n";
 }

void drawOption(const char* oName) {
    std::cout << oName << "\n";
}

int main()
{
    drawHeader("EMPLOYEE MANAGEMENT SYSTEM");
    drawOption("1. Login as Admin");
    drawOption("2. Login as Manager");
    drawOption("3. Exit");
}

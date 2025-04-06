#include <iostream>

void drawHeader(const char* hName) {
    std::cout << "------------------------------------------------------------\n";
    std::cout << "------------------------------------------------------------\n";
    std::cout << hName ;
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << "------------------------------------------------------------\n";
 }

int main()
{
    drawHeader("EMPLOYEE MANAGEMENT SYSTEM");
}

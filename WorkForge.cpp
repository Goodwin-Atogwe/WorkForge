#include <iostream>
#include <vector>
using namespace std;

class createMenu {
private: 
    const char* hName;
    vector<string> options;
    void drawHeader() {
        std::cout << "------------------------------------------------------------\n";
        std::cout << "------------------------------------------------------------\n";
        std::cout << "\t\t" << hName;
        std::cout << "\n------------------------------------------------------------\n";
        std::cout << "------------------------------------------------------------\n";
    }
    int index = 1;
    int menuChoice = 0;
public:
    
    createMenu(const char* headerText):hName(headerText) {}
    void addOption(const char* option) {
        options.push_back(option);
    }
    void draw() {
        drawHeader();
        for (const auto& opt : options) {
            cout << index << " " << opt << endl;
            index++;
        }
        cout << "Enter your choice: ";
        cin >> menuChoice;

        cout << "Your choice was: " << menuChoice;
    }

};


int main()
{
    createMenu mainMenu("EMPLOYEE MANAGEMENT SYSTEM");
    mainMenu.addOption("Login As Admin");
    mainMenu.addOption("Login As Manager");
    mainMenu.addOption("Exit");
    mainMenu.draw();
        
}

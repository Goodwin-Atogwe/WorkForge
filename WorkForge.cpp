#include <iostream>
#include <vector>
#include <cstdlib>
#include <functional>
using namespace std;

class Menu {
public:
    void draw(){};
};

class createMenu : public Menu {
private: 
    const char* hName;
    vector<string> options;
    vector<function<void()>> actions;
    void drawHeader() {
        std::cout << "------------------------------------------------------------\n";
        std::cout << "------------------------------------------------------------\n";
        std::cout << "\t\t" << hName;
        std::cout << "\n------------------------------------------------------------\n";
        std::cout << "------------------------------------------------------------\n";
    }
public:
    int menuChoice = 0;
    createMenu(const char* headerText):hName(headerText) {}
    void addOption(const char* option, function<void()> action) {
        options.push_back(option);
        actions.push_back(action);
    }
    void draw() {
        system("cls");
        int index = 1;
        drawHeader();
        for (const auto& opt : options) {
            cout << index << " " << opt << endl;
            index++;
        }

        
        int menuMap = options.size();
        
        //accepts user input
        cout << "Enter your choice: ";
        cin >> menuChoice;
        if (menuChoice <= actions.size()) {
            actions[menuChoice - 1]();
        }
        else {
            cout << "INVALID CHOICE!!\n";
        }
        /*//check if user input is correct
        if (cin.fail()){
            cin.clear();
            cin.sync();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "INVALID INPUT! PLEASE ENTER A NUMBER";
        }*/
    }

};


int main()
{

    createMenu adminMenu("ADMIN DASHBOARD");
    adminMenu.addOption("View Employees", []() {exit(0); });
    adminMenu.addOption("Add Employee", []() {exit(0); });
    adminMenu.addOption("Search Employee", []() {exit(0); });
    adminMenu.addOption("Update Employee", []() {exit(0); });
    adminMenu.addOption("Delete Employee", []() {exit(0); });
    adminMenu.addOption("Logout", []() {exit(0); });

    createMenu managerMenu("MANAGER DASHBOARD");
    managerMenu.addOption("Add Employee", []() {cout << "this is the Addemployee Page" << endl;});
    managerMenu.addOption("Search Employee", []() {exit(0); });
    managerMenu.addOption("Update Employee", []() {exit(0); });
    managerMenu.addOption("Delete Employee", []() {exit(0); });
    managerMenu.addOption("Logout", []() {exit(0); });

    createMenu mainMenu("EMPLOYEE MANAGEMENT SYSTEM");
    mainMenu.addOption("Login As Admin", [&adminMenu]() {adminMenu.draw();});
    mainMenu.addOption("Login As Manager", [&managerMenu]() {managerMenu.draw(); });
    mainMenu.addOption("Exit", []() {exit(0);});
    mainMenu.draw();

    /*//Admin Menu
    if (mainMenu.menuChoice == 1) {
        adminMenu.draw();
    }
    //Manager menu
    else if (mainMenu.menuChoice == 2) {
        managerMenu.draw();
    }
    //Exit
    else if (mainMenu.menuChoice == 3)
        exit(0);
    */
}

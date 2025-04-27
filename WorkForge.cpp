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
        
        //accepts user input
        cout << "Enter your choice: ";
        cin >> menuChoice;
        //switches menu based on user's input
        if (menuChoice > 0 && menuChoice <= actions.size() && !cin.fail()) {
            actions[menuChoice - 1]();
        }
        else {
            cin.clear();
            cin.sync();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "INVALID INPUT!!!\n";
            cout << "Press Enter to continue";
            cin.get();
            draw();
        }
    }

};


int main()
{
    createMenu mainMenu("EMPLOYEE MANAGEMENT SYSTEM");
    createMenu adminMenu("ADMIN DASHBOARD");
    createMenu managerMenu("MANAGER DASHBOARD");


    mainMenu.addOption("Login As Admin", [&adminMenu]() {adminMenu.draw(); });
    mainMenu.addOption("Login As Manager", [&managerMenu]() {managerMenu.draw(); });
    mainMenu.addOption("Exit", []() {exit(0); });

    adminMenu.addOption("View Employees", []() {cout << "this is the View Employees Page" << endl; });
    adminMenu.addOption("Add Employee", []() {cout << "this is the Add Employee Page" << endl; });
    adminMenu.addOption("Search Employee", []() {cout << "this is the Search Employee Page" << endl; });
    adminMenu.addOption("Update Employee", []() {cout << "this is the Update Employee Page" << endl; });
    adminMenu.addOption("Delete Employee", []() {cout << "this is the Delete Employee Page" << endl; });
    adminMenu.addOption("Logout", [&mainMenu]() {mainMenu.draw(); });

    managerMenu.addOption("Add Employee", []() {cout << "this is the Add Employee Page" << endl;});
    managerMenu.addOption("Search Employee", []() {cout << "this is the Search Employee Page" << endl; });
    managerMenu.addOption("Update Employee", []() {cout << "this is the Update Employee Page" << endl; });
    managerMenu.addOption("Delete Employee", []() {cout << "this is the Delete Employee Page" << endl; });
    managerMenu.addOption("Logout", [&mainMenu]() {mainMenu.draw(); });


    while (true) {
        mainMenu.draw();
    }
}

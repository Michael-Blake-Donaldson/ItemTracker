#include "MenuQuitOption.h"

#include <iostream>
using namespace std;


MenuQuitOption::MenuQuitOption()
    : MenuItem("Quit") {}

MenuQuitOption::MenuQuitOption(int t_menuPosition, map<string, unsigned int>* t_inventoryMap)
    : MenuItem("Quit", t_menuPosition, t_inventoryMap) {}

void MenuQuitOption::Select() {
    cout << "Thank you for using Corner Grocer Item Tracker!" << endl;
    exit(0);
}
#include "MenuItem.h"

#include <iostream>
using namespace std;


// Full constructor for input with all neccessary values
MenuItem :: MenuItem(string t_label, int t_menuPosition, map<string, unsigned int>* t_inventoryMap) 
    : m_menuLabel(t_label), m_inventoryMap(t_inventoryMap) {
    m_menuHotkey = to_string(t_menuPosition).at(0);
}

// Default values for named menu items
MenuItem :: MenuItem(string t_label) {
    m_menuLabel = t_label;
    m_menuHotkey = t_label.at(0);
    m_inventoryMap = new map<string, unsigned int>;
}

// Default values for empty menu items
MenuItem :: MenuItem() : MenuItem("Menu Option") {}


bool MenuItem::Check(string t_userInput) const {
    // Test to see if the user hotkey input matches this menu item
    bool isMatch = (tolower(t_userInput.at(0)) == tolower(m_menuHotkey))
        || (tolower(t_userInput.at(0)) == tolower(m_menuLabel.at(0)));
    return isMatch;
}

void MenuItem::Print() const {
    cout << m_menuHotkey << ") " << m_menuLabel << endl;
}
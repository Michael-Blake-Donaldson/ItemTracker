#include "Menu.h"
#include "FileManagement.h"
#include "MenuSearchOption.h"
#include "MenuListOption.h"
#include "MenuHistogramOption.h"
#include "MenuQuitOption.h"

#include <iostream>
using namespace std;


// Construct the menu and define the menu options
Menu::Menu() {

    // Import the inventory file and make a backup of the inventory data
    m_inventoryMap = loadFile();
    makeBackup(m_inventoryMap);

    m_menuItems = {
        new MenuSearchOption(1, m_inventoryMap),
        new MenuListOption(2, m_inventoryMap),
        new MenuHistogramOption(3, m_inventoryMap),
        new MenuQuitOption(4, m_inventoryMap)
    };
}

// Destructor that deletes the menu option objects and inventory map
Menu::~Menu() {
    // Free up the memory allocated to the inventory map
    delete m_inventoryMap;

    // Delete the menu option objects
    for (MenuItem* menuItem : m_menuItems) {
        delete menuItem;
    }
}

// Output the menu options to the user
void Menu::Print() const {
    cout << "Select a menu option:" << endl;
    for (MenuItem* menuItem : m_menuItems) {
        menuItem->Print();
    }
    cout << endl;
}

// Take user input to select a menu option
void Menu::InputHotkey() {
    string userInput;
    bool isMatch;
    unsigned int menuLength = m_menuItems.size();

    getline(cin, userInput);

    // Loop at choices to see if any have been selected
    for (unsigned int i = 0; i <= menuLength; i++) {
        if (i < menuLength) {
            // Check the user input
            isMatch = m_menuItems.at(i)->Check(userInput);

            // Selects choice if matches input
            if (isMatch) {
                cout << endl;
                m_menuItems.at(i)->Select();
                cout << endl << endl;

                // Stop looking for matches
                break;
            }
        }
        else {
            cout << "That is not a valid choice. Ex: (1, 2, 3, 4) or (S, L, H, Q)";
            cout << endl << endl;
        }
    }
}


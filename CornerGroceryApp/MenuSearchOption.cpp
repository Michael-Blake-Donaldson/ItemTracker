#include "MenuSearchOption.h"

#include <iostream>
using namespace std;


MenuSearchOption::MenuSearchOption()
	: MenuItem("Search") {}

MenuSearchOption::MenuSearchOption(int t_menuPosition, map<string, unsigned int>* t_inventoryMap)
	: MenuItem("Search", t_menuPosition, t_inventoryMap) {}

// Capitalizes the first letters in a string and converts the rest to lowercase
string MenuSearchOption::ProperCase(string t_input) {
	for (int i = t_input.length() - 1; i >= 0; i--) {
		if ((i == 0) || (t_input[i - 1] == ' ')) {
			t_input[i] = toupper(t_input[i]);
		}
		else {
			t_input[i] = tolower(t_input[i]);
		}
	}
	return t_input;
}

// Take user input and return the number of an item in inventory
void MenuSearchOption::Select() {
	string searchInput;

	cout << "Type the name of an inventory item:" << endl;

	// Take user input for the search query
	getline(cin, searchInput);

	// Format the input to match the inventory string keys
	searchInput = ProperCase(searchInput);

	cout << endl;

	// Check the map object of inventory item keys the search term
	if ((*m_inventoryMap).count(searchInput) > 0) {
		cout << "Item: " << searchInput << endl;
		cout << "Number in inventory: " << (*m_inventoryMap)[searchInput] << endl;
	}
	else {
		cout << searchInput << " not found in inventory." << endl;
		
	}
}
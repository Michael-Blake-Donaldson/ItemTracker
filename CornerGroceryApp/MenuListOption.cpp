#include "MenuListOption.h"

#include <iostream>
#include <iomanip>
using namespace std;


MenuListOption::MenuListOption()
	: MenuItem("List Inventory") {}

MenuListOption::MenuListOption(int t_menuPosition, map<string, unsigned int>* t_inventoryMap)
	: MenuItem("List Inventory", t_menuPosition, t_inventoryMap) {}

// Output a formatted list of inventory items and the number in inventory
void MenuListOption::Select() {

	// Print headers
	cout << setw(14) << left << "Item" << "Amount" << endl << endl;

	// For each item in the inventory, print a formatted line with the item name and number
	cout << setfill('.');
	for (const pair<const string, unsigned int> item : (*m_inventoryMap))
	{
		cout << setw(16) << left << item.first;
		cout << setw(4) << right << item.second << endl;
	}
	cout << setfill(' ');

}
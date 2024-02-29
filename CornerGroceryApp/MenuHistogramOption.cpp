#include "MenuHistogramOption.h"

#include <iostream>
#include <iomanip>
using namespace std;


MenuHistogramOption::MenuHistogramOption()
	: MenuItem("Histogram") {}

MenuHistogramOption::MenuHistogramOption(int t_menuPosition, map<string, unsigned int>* t_inventoryMap)
	: MenuItem("Histogram", t_menuPosition, t_inventoryMap) {}

// Output a formatted list of inventory items and the number in inventory
void MenuHistogramOption::Select() {

	// Print headers
	cout << setw(16) << right << "Item" << "  Amount" << endl << endl;

	// For each item in the inventory, print a formatted line with the item name and number
	for (const pair<const string, unsigned int> item : (*m_inventoryMap))
	{
		cout << setw(16) << right << item.first << "  ";
		cout << std::string(item.second, '+') << endl;
	}

}
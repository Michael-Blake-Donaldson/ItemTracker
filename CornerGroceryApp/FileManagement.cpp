#include "FileManagement.h"

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


map<string, unsigned int>* loadFile() {
    string inputFilename = "Inventory.txt";
    ifstream inputFile;
    string inventoryRef;
    unsigned int currentNum;
    map<string, unsigned int>* inventoryMap = new map<string, unsigned int>;

    // Open the input file containing inventory information
    inputFile.open(inputFilename);

    // If the file can't be opened, let the user know
    if (!inputFile.is_open())
    {
        throw runtime_error("Could not open " + inputFilename);
    }

    // Continue until the end of the file
    while (!inputFile.fail())
    {
        // Read in one line of the file
        getline(inputFile, inventoryRef);

        // Check the current number of this inventory item
        currentNum = (*inventoryMap)[inventoryRef];

        // Store an incremenmted inventory number (to add this occurance)
        (*inventoryMap)[inventoryRef] = currentNum + 1;
    }

    // Close the input file
    inputFile.close();

    return inventoryMap;
}

/**
 * Exports inventory data to a backup file ("frequency.dat")
 * @param t_inventoryMap a map with string keys identifying inventory items and corresponding int number in inventory
 * @return 0 on success, 1 on file error
 */
int makeBackup(map<string, unsigned int>* t_inventoryMap) {
    string outputFilename = "frequency.dat";
    ofstream outputFile;
    string inventoryRef;
    unsigned int currentNum;

    // Open the file to back up inventory information in
    outputFile.open(outputFilename);

    // If the file can't be opened, let the user know
    if (!outputFile.is_open())
    {
        throw runtime_error("Could not open " + outputFilename);
        return 1;
    }

    // For each item in the inventory, add a line to the backup file
    for (const pair<const string, unsigned int> item : (*t_inventoryMap))
    {
        outputFile << item.first << "," << item.second << endl;
    }

    // Close the output file
    outputFile.close();

    return 0;
}

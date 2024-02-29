#ifndef CORNER_GROCER_APP_FILE_MANAGEMENT_H_
#define CORNER_GROCER_APP_FILE_MANAGEMENT_H_

#include <string>
#include <map>

int makeBackup(std::map<std::string, unsigned int>* t_inventoryMap);
std::map<std::string, unsigned int>* loadFile();

#endif // CORNER_GROCER_APP_FILE_MANAGEMENT_H_
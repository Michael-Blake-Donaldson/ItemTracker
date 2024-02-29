#ifndef CORNER_GROCER_APP_MENU_H_
#define CORNER_GROCER_APP_MENU_H_

#include <vector>
#include <string>
#include <map>

#include "MenuItem.h"


class Menu {
    public:
        Menu();
        ~Menu();
        void Print() const;
        void InputHotkey();

    private:
        std::map<std::string, unsigned int>* m_inventoryMap;
        std::vector<MenuItem*> m_menuItems;

};

#endif // CORNER_GROCER_APP_MENU_H_
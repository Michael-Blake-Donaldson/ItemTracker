#ifndef CORNER_GROCER_APP_MENU_ITEM_H_
#define CORNER_GROCER_APP_MENU_ITEM_H_

#include <string>
#include <map>

// Abstract base class for menu items
class MenuItem {
    public:
        MenuItem(std::string t_label, int t_menuPosition, std::map<std::string, unsigned int>* t_inventoryMap);
        MenuItem(std::string t_label);
        MenuItem();
        bool Check(std::string t_userInput) const;
        virtual void Select() = 0;
        virtual void Print() const;
    protected:
        char m_menuHotkey;
        std::string m_menuLabel;
        std::map<std::string, unsigned int>* m_inventoryMap;
};

#endif // CORNER_GROCER_APP_MENU_ITEM_H_
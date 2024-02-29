#ifndef CORNER_GROCER_APP_MENUITEM_HISTOGRAM_OPTION_H_
#define CORNER_GROCER_APP_MENUITEM_HISTOGRAM_OPTION_H_

#include <string>
#include <map>

#include "MenuItem.h"


class MenuHistogramOption : public MenuItem {
public:
    MenuHistogramOption();
    MenuHistogramOption(int t_menuPosition, std::map<std::string, unsigned int>* t_inventoryMap);
    void Select();
};

#endif // CORNER_GROCER_APP_MENUITEM_HISTOGRAM_OPTION_H_
#ifndef SWITCHMENU_HPP
#define SWITCHMENU_HPP
#include "menu.hpp"
#include "tractor.hpp"

class switchMenu : public menu{
public:
    tractor* trekker;
    switchMenu(sf::RenderWindow & window, tractor* trekker);
    void create() override;
};





#endif

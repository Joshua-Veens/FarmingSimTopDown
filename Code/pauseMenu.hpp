#ifndef PAUSE_MENU_HPP
#define PAUSE_MENU_HPP
#include "menu.hpp"

class pause_menu : public menu
{
private:
    void create() override;

public:
    pause_menu(sf::RenderWindow &window);
};

#endif
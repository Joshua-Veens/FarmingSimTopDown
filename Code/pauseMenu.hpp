#ifndef PAUSE_MENU_HPP
#define PAUSE_MENU_HPP
#include "menu.hpp"
///@file 
///@brief pause menu class derived from menu
class pause_menu : public menu
{
private:
    void create() override;

public:
    ///@brief constructor for pause menu
    pause_menu(sf::RenderWindow &window, saver & Save);
};

#endif
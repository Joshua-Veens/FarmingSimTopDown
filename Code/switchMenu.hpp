// this file contains doxygen lines
#ifndef SWITCHMENU_HPP
#define SWITCHMENU_HPP
#include "menu.hpp"
#include "player.hpp"

/// @file switchMenu.hpp
/// @brief switchMenu class
/// @details the menu class to switch between vehicles. it uses the superclass menu

class switchMenu : public menu{
private:
    player * Player;
public:
    /// @brief constructor of the switch menu
    switchMenu(sf::RenderWindow & window, saver save, player * Player);

    /// @brief creates the menu on the screen
    void create() override;
};
#endif

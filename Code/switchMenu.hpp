#ifndef SWITCHMENU_HPP
#define SWITCHMENU_HPP
#include "menu.hpp"
#include "player.hpp"

class switchMenu : public menu{
public:
    player &Player;
    switchMenu(sf::RenderWindow & window, player & Player);
    void create() override;
};
#endif

#ifndef SWITCHMENU_HPP
#define SWITCHMENU_HPP
#include "menu.hpp"
#include "player.hpp"

class switchMenu : public menu{
private:
    player * Player;
public:
    switchMenu(sf::RenderWindow & window, saver save, player * Player);

    void create() override;
};
#endif

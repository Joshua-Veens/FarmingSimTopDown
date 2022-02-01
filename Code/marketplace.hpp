//
// Created by joshu on 28-1-2022.
//

#ifndef V2CPSE2_EXAMPLES_MARKETPLACE_HPP
#define V2CPSE2_EXAMPLES_MARKETPLACE_HPP

#include "drawable.hpp"
#include "inventory.hpp"
#include "menu.hpp"

class marketplace : public menu{
private:

    unsigned int money = 30000;
    inventory * inv;

public:
    marketplace(sf::RenderWindow & window, saver save, inventory * inv);

    void sellAll();

    void create() override;

    unsigned int getMoney();

    void addMoney(unsigned int moneyToAdd);
    void removeMoney(unsigned int moneyToRemove);
};


#endif //V2CPSE2_EXAMPLES_MARKETPLACE_HPP

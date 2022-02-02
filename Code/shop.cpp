//
// Created by joshu on 1-2-2022.
//

#include "shop.hpp"
#include "iostream"

shop::shop(std::vector<std::vector<dirt *>> & farmlands, marketplace * market, sf::Clock & clock):
    farmlands(farmlands),
    clock(clock),
    market(market)
{
    image.loadFromFile("images\\forSale.png");
    font.loadFromFile("Xhers_Regular.otf");
    text.setStyle(sf::Text::Bold);
    text.setFillColor(color);
}

void shop::drawPrice(sf::RenderWindow &window, int price, sf::Vector2f position) {
    text_string = "$ " + std::to_string(price);
    text = sf::Text(text_string, font);
    text.setCharacterSize(24);
    text.setPosition(sf::Vector2f(position));
    window.draw(text);
}

void shop::drawNotEnoughMoney(sf::RenderWindow &window) {
    text_string = "Not enough money $$$";
    moneyText = sf::Text(text_string, font);
    moneyText.setCharacterSize(32);
    moneyText.setPosition(sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window))));
    window.draw(moneyText);
}

void shop::draw(sf::RenderWindow &window) {
    int counter=0;
    sf::Time time = clock.getElapsedTime();
    if(!enoughMoney){
        if (time.asMilliseconds() <= 1000){
            drawNotEnoughMoney(window);
        }else if(time.asMilliseconds() > 1000){
            clock.restart();
            enoughMoney = true;
        }
    }
    for(auto &sign : saleSigns){
        if(farmlands[counter][0]->getOwned()){
            sprite.setTexture(image, true);
            sprite.setPosition(sf::Vector2f(sign.x,sign.y));
            sprite.setScale(2,2);
            window.draw(sprite);
            drawPrice(window,prices[counter],sf::Vector2f(sign.x+70, sign.y+20));
        }
        counter++;
    }
}

void shop::addForSaleSign(sf::Vector2f position) {
    saleSigns.push_back(position);
    sf::FloatRect collider(position.x, position.y, 128,128);
    colliders.push_back(collider);
}



void shop::buyLand(sf::Vector2f mouse, sf::RenderWindow &window) {
    sf::Time time = clock.getElapsedTime();
    clock.restart();
    if (time.asMilliseconds() > 500) {
        for (unsigned int i = 0; i < colliders.size(); i++) {
            if (colliders[i].contains(sf::Vector2f(mouse))) {
                if (i == 0) {
                    if (market->getMoney() >= 10000) {
                        if (farmlands[0][0]->getOwned()) {
                            market->removeMoney(10000);
                            for (auto dirt: farmlands[i]) {
                                dirt->setToOwned();
                            }
                        }
                    }else{
                        enoughMoney = false;
                    }
                }
                if (i == 1) {
                    if (market->getMoney() >= 60000) {
                        if (farmlands[1][0]->getOwned()) {
                            market->removeMoney(60000);
                            for (auto dirt: farmlands[i]) {
                                dirt->setToOwned();
                            }
                        }
                    }else{
                        enoughMoney = false;
                    }
                }
                if (i == 2) {
                    if (market->getMoney() >= 30000) {
                        if (farmlands[2][0]->getOwned()) {
                            market->removeMoney(30000);
                            for (auto dirt: farmlands[i]) {
                                dirt->setToOwned();
                            }
                        }
                    }else{
                        enoughMoney = false;
                    }
                }
                if (i == 3) {
                    if (market->getMoney() >= 45000) {
                        if (farmlands[3][0]->getOwned()) {
                            market->removeMoney(45000);
                            for (auto dirt: farmlands[i]) {
                                dirt->setToOwned();
                            }
                        }
                    }else{
                        enoughMoney = false;
                    }
                }
                if (i == 4) {
                    if (market->getMoney() >= 32000) {
                        if (farmlands[4][0]->getOwned()) {
                            market->removeMoney(32000);
                            for (auto dirt: farmlands[i]) {
                                dirt->setToOwned();
                            }
                        }
                    }else{
                        enoughMoney = false;
                    }
                }
            }
        }
    }
}
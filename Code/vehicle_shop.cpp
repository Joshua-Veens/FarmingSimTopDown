#include "vehicle_shop.hpp"

vehicle_shop::vehicle_shop(sf::Vector2f position, sf::Clock & clock):
    position(position),
    clock(clock),
    collider(position.x, position.y + 25, 512, 206),
    big_tractor(position.x+10, position.y + 340, 90, 60),
    small_tractor(position.x+410, position.y + 242, 90, 60),
    big_harvester(position.x+230, position.y + 270, 90, 60),
    small_harvester(position.x+410, position.y + 430, 90, 60),
    shop_collider(position.x+210, position.y + 430, 90, 60)
//    blokje(sf::Vector2f(position.x+210, position.y + 430), sf::Vector2f(90, 60))
{
    image.loadFromFile("images\\shop.png");
    sprite.setTexture(image);
    sprite.setPosition(position);
    font.loadFromFile("Xhers_Regular.otf");
    text.setStyle(sf::Text::Bold);
    text.setFillColor(color);
}

void vehicle_shop::drawTractorPrice(sf::RenderWindow & window) {
    text_string = "$ 350.000";
    text = sf::Text(text_string, font);
    text.setCharacterSize(24);
    text.setPosition(sf::Vector2f(position.x+10,position.y+330));
    window.draw(text);
}

void vehicle_shop::drawHarvesterPrice(sf::RenderWindow & window) {
    text_string = "$ 550.000";
    text = sf::Text(text_string, font);
    text.setCharacterSize(24);
    text.setPosition(sf::Vector2f(position.x+220, position.y + 250));
    window.draw(text);
}

void vehicle_shop::drawNotEnoughMoney(sf::RenderWindow &window) {
    text_string = "Not enough money $$$";
    moneyText = sf::Text(text_string, font);
    moneyText.setCharacterSize(32);
    moneyText.setPosition(sf::Vector2f(window.mapPixelToCoords(sf::Mouse::getPosition(window))));
    window.draw(moneyText);
}

void vehicle_shop::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    sf::Time time = clock.getElapsedTime();
    if(!enoughMoney){
        if (time.asMilliseconds() <= 1000){
            drawNotEnoughMoney(window);
        }else if(time.asMilliseconds() > 1000){
            clock.restart();
            enoughMoney = true;
        }
    }
//    blokje.draw(window);
}

sf::FloatRect vehicle_shop::getCollider() {
    return collider;
}


void vehicle_shop::buyVehicle(sf::RenderWindow & window, tractor * trekker, harvester * combine, marketplace * market) {
    auto mouse_pos = sf::Mouse::getPosition(window);
    auto translated_pos = window.mapPixelToCoords(mouse_pos);
    if(trekker->getCollider().intersects(shop_collider)){
        if(trekker->getSize() == 0){
            if(!boughtBigTractor){
                drawTractorPrice(window);
            }
            if(big_tractor.contains(translated_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(boughtBigTractor){
                    trekker->setSize(true);
                }else if(market->getMoney() > 350000){
                    market->removeMoney(350000);
                    trekker->setSize(true);
                    boughtBigTractor = true;
                }else{
                    enoughMoney = false;
                }
            }
        }else{
            if(small_tractor.contains(translated_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                trekker->setSize(false);
            }
        }
    }
    if(combine->getCollider().intersects(shop_collider)){
        if(combine->getSize() == 0){
            if(!boughtBigHarvester){
                drawHarvesterPrice(window);
            }
            if(big_harvester.contains(translated_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                if(boughtBigHarvester){
                    combine->setSize(true);
                }else if(market->getMoney() > 550000){
                    market->removeMoney(550000);
                    combine->setSize(true);
                    boughtBigHarvester = true;
                }else{
                    enoughMoney = false;
                }
            }
        }else{
            if(small_harvester.contains(translated_pos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                combine->setSize(false);
            }
        }
    }
}
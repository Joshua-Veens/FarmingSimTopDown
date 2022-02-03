//
// Created by joshu on 28-1-2022.
//

#include "marketplace.hpp"
#include <iomanip>
#include <sstream>
#include "iostream"

marketplace::marketplace(sf::Vector2f position):
    position(position),
    sell_collider(position.x+208, position.y+200, 48, 43),
    collider(position.x + 21, position.y + 126, 123, 85)
{
    image.loadFromFile("images\\market.png");
    sprite.setTexture(image);
    sprite.setPosition(position);
    font.loadFromFile("Xhers_Regular.otf");
}

void marketplace::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

sf::FloatRect marketplace::getCollider() {
    return collider;
}

sf::FloatRect marketplace::getSellCollider() {
    return sell_collider;
}

float marketplace::getMoney() {
    return money;
}

void marketplace::addMoney(float moneyToAdd) {
    money += moneyToAdd;
}
    
void marketplace::removeMoney(float moneyToRemove) {
    money -= moneyToRemove;
}

sf::Vector2f marketplace::getPosition() {
    return position;
}

void marketplace::sellCrops(float wheat, float corn, float weed) {
    money += wheat * 0.27;
    money += corn * 0.4;
    money += weed * 5;
}

void marketplace::setMoney(float allMoney){
    money = allMoney;
}

void marketplace::drawMoney(sf::RenderWindow &window, sf::Vector2f moneyPosition) {
    std::stringstream stream;
    stream << "$ " << std::fixed << std::setprecision(2) << money;
    text_string = stream.str();
    text.setFillColor(sf::Color::Blue);
    text.setStyle(sf::Text::Bold);
    text = sf::Text(text_string, font);
    text.setCharacterSize(32);
    text.setPosition(sf::Vector2f (moneyPosition.x+1750, moneyPosition.y+5));
    window.draw(text);
}

//void marketplace::sellAll() {
//    money += inv->getWheat() /100 * 27;
//    money += inv->getCorn() / 100 * 40;
//    inv->removeCrops();
//    std::cout << money << "\n";
//}
//
//void marketplace::create() {
//    options.clear();
//    options.push_back(option(
//            std::to_string(inv->getWheat()), (sf::Vector2f)window_middle - sf::Vector2f(840, 220), [&]
//            { },
//            font_file));
//    options.push_back(option(
//            std::to_string(inv->getCorn()), (sf::Vector2f)window_middle - sf::Vector2f(840, 150), [&]
//            { },
//            font_file));
//    options.push_back(option(
//            "$ " + std::to_string(money), (sf::Vector2f)window_middle - sf::Vector2f(580, 220), [&]
//            { },
//            font_file));
//    options.push_back(option(
//            "Sell all crops", (sf::Vector2f)window_middle - sf::Vector2f(580, 150), [&]
//            { sellAll();},
//            font_file));
//    options.push_back(option(
//            "Close", (sf::Vector2f)window_middle - sf::Vector2f(580, 80), [&]
//            { this->active = false;},
//            font_file));
//}



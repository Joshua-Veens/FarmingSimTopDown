#include "inventory.hpp"
#include "iostream"

inventory::inventory()
{
    wheatImage.loadFromFile("images\\wheatCrop.png");
    cornImage.loadFromFile("images\\cornCrop.png");
}

void inventory::drawWheat(sf::RenderWindow &window) {
    text_string = std::to_string(wheatCount);
    sf::Font font;
    font.loadFromFile(font_file);
    sf::Text text(text_string, font);
    text.setCharacterSize(40);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(color);
    text.setPosition(sf::Vector2f(80,20));
    sprite.setTexture(wheatImage);
    sprite.setPosition(sf::Vector2f(10, 20));
    window.draw(sprite);
    window.draw(text);
}

void inventory::drawCorn(sf::RenderWindow &window) {
    text_string = std::to_string(cornCount);
    sf::Font font;
    font.loadFromFile(font_file);
    sf::Text text(text_string, font);
    text.setCharacterSize(40);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(color);
    text.setPosition(sf::Vector2f(80,80));
    sprite.setTexture(cornImage);
    sprite.setPosition(sf::Vector2f(10, 80));
    window.draw(sprite);
    window.draw(text);
}

void inventory::draw(sf::RenderWindow &window) {
    drawWheat(window);
    drawCorn(window);
}

void inventory::setHarvest(type croptype) {
    active_crop_type = croptype;
    if(active_crop_type == 0){
        wheatCount += rand() % ((40 - 30) + 1) + 30;
    }
    if(active_crop_type == 1){
        cornCount += rand() % ((60 - 40) + 1) + 40;
    }
}

unsigned int inventory::getWheat() {
    return wheatCount;
}

unsigned int inventory::getCorn() {
    return cornCount;
}

void inventory::removeCrops() {
    wheatCount = 0;
    cornCount = 0;
}

#include "inventory.hpp"

inventory::inventory(sf::Vector2f position):
    position(position),
    collider(position.x+172, position.y+208, 48, 43),
    blokje(sf::Vector2f(position.x+172, position.y+208), sf::Vector2f(48, 43))
{
    image.loadFromFile("images\\silo.png");
    sprite.setTexture(image);
    sprite.setPosition(position);
    wheatImage.loadFromFile("images\\wheatCrop.png");
    cornImage.loadFromFile("images\\cornCrop.png");
    font.loadFromFile("Xhers_Regular.otf");
    text.setStyle(sf::Text::Bold);
    text.setFillColor(color);
    wheatSprite.setTexture(wheatImage);
    cornSprite.setTexture(cornImage);
}

void inventory::draw(sf::RenderWindow &window) {
    window.draw(sprite);
//    blokje.draw(window);
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

void inventory::addWheat(unsigned int wheat) {
    wheatCount += wheat;
}

void inventory::addCorn(unsigned int corn) {
    cornCount += corn;
}

void inventory::drawInventory(sf::RenderWindow &window) {
    drawWheat(window);
    drawCorn(window);
}

void inventory::drawWheat(sf::RenderWindow &window) {
    text_string = std::to_string(wheatCount);
    text = sf::Text(text_string, font);
    text.setCharacterSize(28);
    text.setPosition(sf::Vector2f(position.x+64,position.y+103));
    wheatSprite.setScale(0.4, 0.4);
    wheatSprite.setPosition(sf::Vector2f(position.x+38, position.y+100));
    window.draw(wheatSprite);
    window.draw(text);
}

void inventory::drawCorn(sf::RenderWindow &window) {
    text_string = std::to_string(cornCount);
    text = sf::Text(text_string, font);
    text.setCharacterSize(28);
    text.setPosition(sf::Vector2f(position.x+64,position.y+148));
    cornSprite.setScale(0.4, 0.4);
    cornSprite.setPosition(sf::Vector2f(position.x+38, position.y+146));
    window.draw(cornSprite);
    window.draw(text);
}

sf::FloatRect inventory::getCollider() {
    return collider;
}

sf::Vector2f inventory::getPosition() {
    return position;
}
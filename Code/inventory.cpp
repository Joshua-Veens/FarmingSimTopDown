#include "inventory.hpp"

inventory::inventory(sf::Vector2f position):
    position(position),
    collider(position.x+172, position.y+208, 48, 43),
    silo_collider(position.x+38, position.y+180, 110, 72),
    blokje(sf::Vector2f(position.x+38, position.y+180), sf::Vector2f(110, 72))
{
    image.loadFromFile("images\\put.png");
    sprite.setTexture(image);
    sprite.setPosition(sf::Vector2f(position.x+132, position.y+163));
    silo_texture.loadFromFile("images\\silo.png");
    silo_sprite.setTexture(silo_texture);
    silo_sprite.setPosition(position);
    wheatImage.loadFromFile("images\\wheatCrop.png");
    cornImage.loadFromFile("images\\cornCrop.png");
    font.loadFromFile("Xhers_Regular.otf");
    wheat_text.setStyle(sf::Text::Bold);
    corn_text.setStyle(sf::Text::Bold);
    wheatSprite.setTexture(wheatImage);
    cornSprite.setTexture(cornImage);
}

void inventory::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void inventory::drawSilo(sf::RenderWindow &window) {
    window.draw(silo_sprite);
//    blokje.draw(window);
}

int inventory::getWheat() {
    return wheatCount;
}

int inventory::getCorn() {
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

void inventory::removeWheat(unsigned int wheat) {
    wheatCount -= wheat;
}

void inventory::removeCorn(unsigned int corn) {
    cornCount -= corn;
}

void inventory::drawInventory(sf::RenderWindow &window) {
    drawWheat(window);
    drawCorn(window);
}

void inventory::drawWheat(sf::RenderWindow &window) {
    text_string = std::to_string(wheatCount);
    wheat_text = sf::Text(text_string, font);
    wheat_text.setCharacterSize(28);
    wheat_text.setPosition(sf::Vector2f(position.x+64,position.y+103));
    wheatSprite.setScale(0.4, 0.4);
    wheatSprite.setPosition(sf::Vector2f(position.x+38, position.y+100));
    window.draw(wheatSprite);
    window.draw(wheat_text);
}

void inventory::drawCorn(sf::RenderWindow &window) {
    text_string = std::to_string(cornCount);
    corn_text = sf::Text(text_string, font);
    corn_text.setCharacterSize(28);
    corn_text.setPosition(sf::Vector2f(position.x+64,position.y+148));
    cornSprite.setScale(0.4, 0.4);
    cornSprite.setPosition(sf::Vector2f(position.x+38, position.y+146));
    window.draw(cornSprite);
    window.draw(corn_text);
}

sf::FloatRect inventory::getCollider() {
    return silo_collider;
}

sf::FloatRect inventory::getDepositCollider() {
    return collider;
}

sf::FloatRect inventory::getWheatTextCollider() {
    return wheat_text.getGlobalBounds();
}

sf::FloatRect inventory::getCornTextCollider() {
    return corn_text.getGlobalBounds();
}

sf::Vector2f inventory::getPosition() {
    return position;
}
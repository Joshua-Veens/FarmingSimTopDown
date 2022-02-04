#include "saveHouse.hpp"

saveHouse::saveHouse(sf::Vector2f position) : position(position),
                                              save_collider(position.x - 25, position.y+255, 300, 120),
                                              house_collider(position.x + 13, position.y + 115, 235, 133)
{
    image.loadFromFile("images\\saveHouse.png");
    sprite.setTexture(image);
    sprite.setPosition(position);
}

void saveHouse::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
    sf::Time saveTime = saveClock.getElapsedTime();
    if (saveTime.asSeconds () > 1)
    {

        if (trekker->getCollider().intersects(save_collider))
        {
            drawSaveHelp(window, trekker);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::H))
            {
                save->save("save.txt");
                saveClock.restart();
            }
        }
    }
}

sf::FloatRect saveHouse::getCollider()
{
    return house_collider;
}

sf::FloatRect saveHouse::getSavePoint()
{
    return save_collider;
}

void saveHouse::setTractor(tractor *newTrekker)
{
    trekker = newTrekker;
}

void saveHouse::drawSaveHelp(sf::RenderWindow &window, tractor *trekker)
{
    text_string = "Press \"H\" to save";
    font.loadFromFile("Xhers_Regular.otf");
    text = sf::Text(text_string, font);
    text.setCharacterSize(32);
    text.setPosition(sf::Vector2f(trekker->getPosition().x + 10, trekker->getPosition().y + 10));
    window.draw(text);
}

void saveHouse::setSaver(saver *newSave)
{
    save = newSave;
}
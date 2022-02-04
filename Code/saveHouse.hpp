#ifndef SAVEHOUSE_HPP
#define SAVEHOUSE_HPP

#include "drawable.hpp"
#include "rectangle.hpp"
#include "tractor.hpp"
#include "saver.hpp"

class saveHouse : public drawable{
private:
    sf::Vector2f position;
    sf::Texture image;
    sf::Sprite sprite;
    sf::FloatRect save_collider, house_collider;
    std::string text_string;
    sf::Font font;
    sf::Color color = sf::Color::White;
    sf::Clock saveClock;
    sf::Text text;
    tractor * trekker;
    saver * save;
public:
    saveHouse(sf::Vector2f position);

    void draw(sf::RenderWindow & window) override;

    sf::FloatRect getCollider() override;

    sf::FloatRect getSavePoint() override;

    void setTractor(tractor * trekker);

    void setSaver(saver * newSave);

    void drawSaveHelp(sf::RenderWindow &window,tractor * trekker);
};


#endif //SAVEHOUSE_HPP

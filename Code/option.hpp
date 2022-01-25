#ifndef OPTION_HPP
#define OPTION_HPP
#include "drawable.hpp"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <functional>
#include "option.hpp"
class option : public drawable
{
private:
    std::string text_string;
    sf::Vector2f position;
    sf::Color color = sf::Color::Green;
    sf::FloatRect rect;
    std::function<void()> work;
    const std::string font_file;

public:
    option(std::string text_string, sf::Vector2f position, std::function<void()> work, const std::string font_file);

    void draw(sf::RenderWindow &window) override;
    void update(sf::RenderWindow &window);
    void change_text(std::string text);
};


#endif
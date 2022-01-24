#include "option.hpp"


option::option(std::string text_string, sf::Vector2f position, std::function<void()> work, const std::string font_file) : text_string(text_string), position(position), work(work), font_file(font_file) {}

void option::draw(sf::RenderWindow &window)
{
    sf::Font font;
    font.loadFromFile(font_file);
    sf::Text text(text_string, font);
    text.setCharacterSize(60);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(color);
    text.setPosition(position);
    window.draw(text);
    rect = text.getGlobalBounds();
}
void option::update(sf::RenderWindow &window)
{
    sf::Vector2f mouse_pos = (sf::Vector2f(sf::Mouse::getPosition(window)));
    sf::Font font;
    font.loadFromFile(font_file);
    sf::Text text(text_string, font);
    text.setCharacterSize(60);
    text.setStyle(sf::Text::Bold);
    if (rect.contains(mouse_pos))
    {
        color = sf::Color::White;
    }
    else
    {
        color = sf::Color::Green;
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (rect.contains(mouse_pos))
        {
            work();
        }
    }
    text.setFillColor(color);
    text.setPosition(position);
    window.draw(text);
    rect = text.getGlobalBounds();
}
void option::change_text(std::string new_text)
{
    text_string = new_text;
}
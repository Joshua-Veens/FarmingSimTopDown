#ifndef MENU_HPP
#define MENU_HPP
#include "drawable.hpp"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <functional>
class option : public drawable
{
private:
    std::string text_string;
    sf::Vector2f position;
    const std::string font_file = "unispace_rg.ttf";
    sf::Color color = sf::Color::Green;
    sf::FloatRect rect;
    std::function<void()> work;

public:
    option( std::string text_string, sf::Vector2f position, std::function<void()> work);

    void draw(sf::RenderWindow &window) override;
    void update(sf::RenderWindow &window);
    void change_text(std::string text);
};
class menu
{
protected:
    std::vector<option> options;
    sf::RenderWindow &window;
    sf::Vector2u window_middle = sf::Vector2u(window.getSize().x / 2, window.getSize().y / 2);
    void draw();
    const std::string font_file = "unispace_rg.ttf";
    bool active = true;
public:
    menu(sf::RenderWindow &window);
    // menu(std::vector<option> &options, sf::RenderWindow &window);

    void show();
    void showHelp();
};

class pause_menu :public menu{
public:
    pause_menu(sf::RenderWindow & window);
};
#endif
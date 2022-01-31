#ifndef MENU_HPP
#define MENU_HPP
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <functional>
#include "option.hpp"
#include "saver.hpp"
class menu
{
protected:
    std::vector<option> options;
    sf::RenderWindow &window;
    sf::Vector2u window_middle = sf::Vector2u(window.getSize().x / 2, window.getSize().y / 2);
    const std::string font_file = "Xhers_Regular.otf";
    bool active = false;
    void draw();
    virtual void create();
    saver & Save;

public:
    menu(sf::RenderWindow &window, saver & Save);
    // menu(std::vector<option> &options, sf::RenderWindow &window);

    void show();
    void showHelp();
    bool getActive();
};


#endif
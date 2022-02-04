#ifndef MENU_HPP
#define MENU_HPP
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <functional>
#include "option.hpp"
#include "saver.hpp"

///@file
///@brief superclass menu, is the main menu as well as the super class for other menu's
class menu
{
protected:
    std::vector<option> options;
    std::string filename = "images\\mainBack.png";
    sf::RenderWindow &window;
    sf::Vector2u window_middle = sf::Vector2u(window.getSize().x / 2, window.getSize().y / 2);
    const std::string font_file = "Xhers_Regular.otf";
    bool active = false;
    void draw();
    ///@brief private function, should be overwritten to change menu items
    ///@details add objects of class option to object to create your menu
    virtual void create();
    saver & Save;

public:
    menu(sf::RenderWindow &window, saver & Save);
    ///@brief shows menu
    void show();
    ///@brief shows menu
    ///@param file the background image
    void show(std::string file);
    ///@brief shows help
    void showHelp();
    ///@brief returns if the menu is currently on
    bool getActive();
};


#endif
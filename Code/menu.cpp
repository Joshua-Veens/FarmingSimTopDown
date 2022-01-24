#include "menu.hpp"
#include <iostream>
#include "picture.hpp"

menu::menu(sf::RenderWindow &window) : window(window)
{
}

void menu::create()
{
    options.push_back(option(
        "start", (sf::Vector2f)window_middle - sf::Vector2f(0, 80), [this]
        { active = false; },
        font_file));
    options.push_back(option(
        "help", (sf::Vector2f)window_middle - sf::Vector2f(0, 0), [this]
        { showHelp(); },
        font_file));
    options.push_back(option(
        "exit", (sf::Vector2f)window_middle + sf::Vector2f(0, 80), []
        { exit(0); },
        font_file));
}

void menu::draw()
{
    picture bkg("mainBack.png",sf::Vector2f(0,0));
    bkg.draw(window);
    sf::Font font;
    font.loadFromFile(font_file);
    std::string text_string = "Top down farming simulator";
    sf::Text text(text_string, font);
    text.setCharacterSize(60);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color(91,127,0));
    text.setPosition((sf::Vector2f)window_middle - sf::Vector2f(300,320));
    window.draw(text);
    for (auto item : options)
    {
        item.draw(window);
        item.update(window);
    }
}

void menu::show()
{
    if (options.size() == 0)
    {
        create();
    }
    active = true;
    while (active)
    {
        window.clear();
        draw();
        window.display();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }
        }
    }
}

void menu::showHelp()
{
    window.clear();
    sf::Font font;
    font.loadFromFile(font_file);
    std::string text_string = "TODO: make help";
    sf::Text text(text_string, font);
    text.setCharacterSize(30);
    text.setStyle(sf::Text::Regular);
    text.setFillColor(sf::Color::Red);
    text.setPosition((sf::Vector2f)window_middle);
    window.draw(text);
    window.display();
    sf::sleep(sf::milliseconds(1000));
}

bool menu::getActive()
{
    return active;
}

// menu::menu(std::vector<option> &options,sf::RenderWindow &window) : options(options),window(window) {}
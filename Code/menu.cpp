#include "menu.hpp"
#include <iostream>
#include "picture.hpp"

menu::menu(sf::RenderWindow &window, saver & Save) : window(window), Save(Save)
{
}

void menu::create()
{
    options.push_back(option(
        "start", (sf::Vector2f)window_middle - sf::Vector2f(665, 150), [this]
        { active = false; },
        font_file));
    options.push_back(option(
        "help", (sf::Vector2f)window_middle - sf::Vector2f(650, 70), [this]
        { showHelp(); },
        font_file));
    options.push_back(option(
        "exit", (sf::Vector2f)window_middle + sf::Vector2f(-650, 10), [this]
        { window.close(); exit(0); },
        font_file));
}

void menu::draw()
{
    picture bkg("images\\mainBack.png",sf::Vector2f(0,0));
    bkg.draw(window);
    sf::Font font;
    font.loadFromFile(font_file);
    std::string text_string = "Top down farming simulator";
    sf::Text text(text_string, font);
    text.setCharacterSize(60);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color(91,127,0));
    text.setPosition((sf::Vector2f)window_middle - sf::Vector2f(900,420));
    sf::View view = window.getView();
    view.setCenter(window_middle.x, window_middle.y);
    window.draw(text);
    window.setView(view);
    for (auto item : options)
    {
        item.draw(window);
        item.update(window);
    }
}

void menu::show()
{
    active = true;
    while (active)
    {
        create();
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
    std::string text_string = "Controls:\n"
                              "WASD     Driving\n"
                              "1,2,3    Switch to action\n"
                              "R        Switch vehicle\n"
                              "V        Change crop";
    sf::Text text(text_string, font);
    text.setCharacterSize(30);
    text.setStyle(sf::Text::Regular);
    text.setFillColor(sf::Color::Green);
    text.setPosition((sf::Vector2f)window_middle);
    window.draw(text);
    window.display();
    sf::sleep(sf::milliseconds(3000));
}

bool menu::getActive()
{
    return active;
}

// menu::menu(std::vector<option> &options,sf::RenderWindow &window) : options(options),window(window) {}
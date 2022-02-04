#include "menu.hpp"
#include <iostream>
#include "picture.hpp"

menu::menu(sf::RenderWindow &window, saver &Save) : window(window), Save(Save)
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
    picture bkg(filename, sf::Vector2f(0, 0));
    bkg.draw(window);
    sf::Font font;
    font.loadFromFile(font_file);
    std::string text_string = "Top down farming simulator";
    sf::Text text(text_string, font);
    text.setCharacterSize(60);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color(91, 127, 0));
    text.setPosition((sf::Vector2f)window_middle - sf::Vector2f(900, 420));
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

void menu::show(std::string file)
{
    filename = file;
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
    bool open = true;
    window.clear();
    sf::Font font;
    font.loadFromFile(font_file);
    std::string text_string = "Move with WASD\n"
                              "press '2' to equip to the seeder, if you're in the tractor, the selected crop is in the top left, cycle through with 'V'\n"
                              "To buy land press the sale sign to the top  left of the field you want to buy, the prices are stated beside them(recommended starting with the 10000 cost field)\n"
                              "when a crop is grown, press R to enter the vehicle select and choose harvester, press '2' to activate the harvester\nand '3' to unload in the trailer(which you get to by switching back to tractor and pressing '3'\n"
                              "press any key to continue....";
    sf::Text text(text_string, font);
    text.setCharacterSize(30);
    text.setStyle(sf::Text::Regular);
    text.setFillColor(sf::Color::Green);
    text.setPosition((sf::Vector2f)window_middle - sf::Vector2f(910, 150));
    window.draw(text);
    window.display();
    sf::Event event;
    while (open)
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return;
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                open = false;
            }
        }
    }
}

bool menu::getActive()
{
    return active;
}

// menu::menu(std::vector<option> &options,sf::RenderWindow &window) : options(options),window(window) {}
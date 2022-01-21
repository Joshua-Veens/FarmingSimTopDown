#include "menu.hpp"
#include <iostream>

option::option(std::string text_string, sf::Vector2f position, std::function<void()> work) : text_string(text_string), position(position), work(work) {}

void option::draw(sf::RenderWindow &window)
{
    sf::Font font;
    font.loadFromFile(font_file);
    sf::Text text(text_string, font);
    text.setCharacterSize(30);
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
    text.setCharacterSize(30);
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
void option::change_text(std::string new_text){
    text_string = new_text;
}
menu::menu(sf::RenderWindow &window) : window(window)
{
    options.push_back(option("start", (sf::Vector2f)window_middle - sf::Vector2f(0, 40), [this]
                             { active = false; }));
    options.push_back(option("help", (sf::Vector2f)window_middle - sf::Vector2f(0, 0), [this]
                             { showHelp(); }));
    options.push_back(option("exit", (sf::Vector2f)window_middle + sf::Vector2f(0, 40), []
                             { exit(0); }));
}

void menu::draw()
{
    for (auto item : options)
    {
        item.draw(window);
        item.update(window);
    }
}

void menu::show()
{
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
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::Red);
    text.setPosition((sf::Vector2f)window_middle);
    window.draw(text);
    window.display();
    sf::sleep(sf::milliseconds(1000));
}

pause_menu::pause_menu(sf::RenderWindow &window) : menu(window) {
    options[0].change_text("continue");
}
// menu::menu(std::vector<option> &options,sf::RenderWindow &window) : options(options),window(window) {}
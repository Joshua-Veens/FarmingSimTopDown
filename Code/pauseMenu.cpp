

#include "pauseMenu.hpp"

pause_menu::pause_menu(sf::RenderWindow &window) : menu(window)
{
}

void pause_menu::create()
{
    options.push_back(option(
        "continue", (sf::Vector2f)window_middle - sf::Vector2f(700, 150), [this]
        { active = false; },
        font_file));
    options.push_back(option(
        "help", (sf::Vector2f)window_middle - sf::Vector2f(650, 70), [this]
        { showHelp(); },
        font_file));
    options.push_back(option(
        "exit", (sf::Vector2f)window_middle + sf::Vector2f(-650, 10), []
        { exit(0); },
        font_file));
}
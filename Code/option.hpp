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
protected:
    std::string text_string;
    sf::Vector2f position;
    sf::Color color = sf::Color::White;
    sf::FloatRect rect;
    std::function<void()> work;
    const std::string font_file;

public:
    option(std::string text_string, sf::Vector2f position, std::function<void()> work, const std::string font_file);

    virtual void draw(sf::RenderWindow &window) override;
    virtual void update(sf::RenderWindow &window);
    void change_text(std::string text);
};

class non_option : public option {
public:
    non_option(std::string text_string, sf::Vector2f position,const std::string font_file);
    void update(sf::RenderWindow &window) override;
};


class non_option_picture : public non_option {
private:
    std::string file_name;
public:
    non_option_picture(std::string file_name, sf::Vector2f position);
    void draw(sf::RenderWindow &window);
};

#endif
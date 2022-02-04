#ifndef OPTION_HPP
#define OPTION_HPP
#include "drawable.hpp"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <functional>
#include "option.hpp"

///@file
///@brief class option options for menu
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
    ///@brief constructor for option class
    option(std::string text_string, sf::Vector2f position, std::function<void()> work, const std::string font_file);
    ///@brief draw for option class
    virtual void draw(sf::RenderWindow &window) override;
    ///@brief update for option class
    virtual void update(sf::RenderWindow &window);
    ///@brief change_text for option class
    void change_text(std::string text);
};
///@brief class option non_options for menu
class non_option : public option {
public:
    ///@brief constructor for non_option
    non_option(std::string text_string, sf::Vector2f position,const std::string font_file);
    ///@brief update function for non_option
    void update(sf::RenderWindow &window) override;
};

///@brief class non_option_picture options for menu
class non_option_picture : public non_option {
private:
    std::string file_name;
public:
    ///@brief constructor for non_option_picture
    non_option_picture(std::string file_name, sf::Vector2f position);
    ///@brief draw function for non_option_picture
    void draw(sf::RenderWindow &window);
};

#endif
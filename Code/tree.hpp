#ifndef TREE_HPP
#define TREE_HPP

#include "drawable.hpp"
#include "rectangle.hpp"

class tree : public drawable{
private:
    sf::Vector2f position;
    std::string tree_1 = "images\\tree_1.png";
    std::string tree_2 = "images\\tree_2.png";
    std::string tree_3 = "images\\tree_3.png";
    std::vector<std::string> files = {tree_1, tree_2, tree_3};
    sf::Texture image;
    sf::Sprite sprite;
    sf::FloatRect collider;
public:
    tree(sf::Vector2f position, int index = 0);

    void draw(sf::RenderWindow & window) override;

    sf::FloatRect getCollider() override;
};


#endif //TREE_HPP

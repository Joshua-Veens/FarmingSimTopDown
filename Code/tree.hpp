#ifndef TREE_HPP
#define TREE_HPP

#include "drawable.hpp"

class tree : public drawable{
private:
    std::string filename = "tree.png";
    sf::Vector2f position;
    sf::Texture image;
    sf::Sprite sprite;

public:
    tree(sf::Vector2f position);

    void draw(sf::RenderWindow & window) override;

};


#endif //TREE_HPP

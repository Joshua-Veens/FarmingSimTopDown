#ifndef TREE_HPP
#define TREE_HPP

#include "drawable.hpp"

///@file this file contains the class that creates the object tree
///@details tree class draws the tree with corresponding colliders
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
    ///@brief tree class constructor
    ///@param index decides which tree image will be used
    tree(sf::Vector2f position, int index = 0);

    ///@brief draws the tree
    void draw(sf::RenderWindow & window) override;

    ///@brief returns the Floatrect of the collider from the tree
    sf::FloatRect getCollider() override;
};


#endif //TREE_HPP

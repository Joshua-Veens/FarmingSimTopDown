#ifndef V2CPSE2_EXAMPLES_INVENTORY_HPP
#define V2CPSE2_EXAMPLES_INVENTORY_HPP


class inventory : public drawable{
private:
    unsigned int wheatCount = 0;
    unsigned int cornCount = 0;
    type active_crop_type;
    std::string text_string;
    sf::Color color = sf::Color::White;
    const std::string font_file = "Xhers_Regular.otf";
    sf::Texture wheatImage;
    sf::Texture cornImage;
    sf::Sprite sprite;

public:
    inventory();

    void draw( sf::RenderWindow & window ) override;

    void drawWheat(sf::RenderWindow &window);

    void drawCorn(sf::RenderWindow &window);

    void setHarvest(type croptype);

    unsigned int getWheat();

    unsigned int getCorn();

    void removeCrops();

};


#endif //V2CPSE2_EXAMPLES_INVENTORY_HPP

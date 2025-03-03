#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class Map {
    public:
        Map(const std::string& name, std::vector<std::vector<sf::Sprite>>& sprites);
        ~Map();
        void updateSprite(sf::Sprite& sprite, int row, int column);
        void setSprites(std::vector<std::vector<sf::Sprite>>& sprites);
        void zoom();
        void draw(sf::RenderTarget& target);
    private:
        std::string name;
        std::vector<std::vector<sf::Sprite>> sprites;
};

#endif //MAP_HPP
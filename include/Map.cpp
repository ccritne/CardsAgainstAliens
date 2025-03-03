#include <Map.hpp>

Map::Map(
    const std::string& name, 
    std::vector<std::vector<sf::Sprite>>& sprites
): name(name), sprites(sprites) {};

Map::~Map() {};

void Map::updateSprite(sf::Sprite &sprite, int row, int column) {
    sprites[row][column] = sprite;
};

void Map::setSprites(std::vector<std::vector<sf::Sprite>>& sprites) {
    this->sprites = sprites;
};

void Map::zoom() {

};

void Map::draw(sf::RenderTarget& target) {

    for (std::vector<sf::Sprite> list : sprites) 
        for(sf::Sprite sprite : list) {
            target.draw(sprite);
        }
    
};
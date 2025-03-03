#include <Entity.hpp>

Entity::Entity(const std::string& texturePath, sf::Vector2f size, sf::Vector2f spawn) {
    if (!texture.loadFromFile(texturePath)) {
        throw std::runtime_error("Failed to load texture");
    }
    setSize(size);
    setPosition(spawn);
    setTexture(&texture);
}

Entity::~Entity() {

};

void Entity::nextFrame(sf::IntRect rect) {
    iteratorFrame++; 
}
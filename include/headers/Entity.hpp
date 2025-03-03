#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>
#include <Directions.hpp>
#include <TypeEntity.hpp>

class Entity: public sf::RectangleShape {
public:
    // Constructor that accepts the texture path
    Entity(const std::string& texturePath, sf::Vector2f size, sf::Vector2f spawn);
    ~Entity();

    void nextFrame(sf::IntRect rect);
private:
    int iteratorFrame = 0;

    sf::Texture texture;  // Keep the texture to ensure it persists as long as the sprite uses it
};

#endif // ENTITY_HPP
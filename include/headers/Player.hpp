#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include <Directions.hpp>
#include <TypeEntity.hpp>
#include <Entity.hpp>

class Player : public Entity {
    
    private:
        std::string name;
        TypeEntity type;
        float speed;

    public:
        Player(const std::string& name, TypeEntity type, float speed, const std::string& path, sf::Vector2f size, sf::Vector2f coords);
        ~Player();

        void move(Direction direction);
};



#endif //PLAYER_HPP
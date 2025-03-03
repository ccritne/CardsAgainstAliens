#include <Player.hpp>

Player::Player(
    const std::string& name, 
    TypeEntity type, 
    float speed, 
    const std::string& path, 
    sf::Vector2f size,
    sf::Vector2f coords
): name(name), type(type), speed(speed), Entity(path, size, coords) {};

Player::~Player() {}

void Player::move(Direction direction) {

    sf::Vector2f actualPosition = getPosition();

    switch (direction)
    {
        case NORTH:
            actualPosition.y -= speed;
            break;
        case SOUTH:
            actualPosition.y += speed;
            break;
        case WEST:
            actualPosition.x -= speed;
            break;
        case EAST:
            actualPosition.x += speed;
            break;
        default:
            break;
    }

    setPosition(actualPosition);

}
#include <KeyboardControl.hpp>

bool isMovementEvent(std::optional<sf::Event> event) {

    // Check if event exists and is of type KeyPressed
    if (!event || !event->is<sf::Event::KeyPressed>()) {
        return false;
    }

    // Get key press event safely
    const sf::Event::KeyPressed* keyEvent = event->getIf<sf::Event::KeyPressed>();
    if (!keyEvent) return false;

    // Extract key code
    sf::Keyboard::Key key = keyEvent->code;

    switch (key)
    {
        case sf::Keyboard::Key::W:
        case sf::Keyboard::Key::A:
        case sf::Keyboard::Key::S:
        case sf::Keyboard::Key::D:
            return true;
        default:
            return false;
    }

} 

Direction directionKey(sf::Keyboard::Key key) {
    switch (key)
    {
        case sf::Keyboard::Key::W:
            return NORTH;
        case sf::Keyboard::Key::A:
            return WEST;
        case sf::Keyboard::Key::S:
            return SOUTH;
        case sf::Keyboard::Key::D:
            return EAST;
        
        default:
            return ERROR;
    }

}
#ifndef KEYBOARD_CONTROL_HPP
#define KEYBOARD_CONTROL_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <Directions.hpp>

bool isMovementEvent(std::optional<sf::Event> event);

Direction directionKey(sf::Keyboard::Key key);

#endif // DIRECTIONS_H
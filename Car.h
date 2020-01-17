#pragma once

#include <SFML/Graphics.hpp>

class Car {
private:
    sf::Vector2f position;
    struct Machine {
        sf::RectangleShape corpse;
        sf::RectangleShape head;
        sf::CircleShape wheelOne;
        sf::CircleShape wheelTwo;
        sf::CircleShape inWheelOne;
        sf::CircleShape inWheelTwo;
        float angle;
        float speed;
    } car;

    void setPosition(sf::Vector2f);

    void update();

public:
    bool canRide{};

    Car();

    explicit Car(sf::Vector2f);

    void moveForward();

    void moveBack();

    sf::Vector2f getPosition();

    void show(sf::RenderWindow &);
};


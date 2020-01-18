//
// Created by bylaew on 19.01.2020.
//

#ifndef SFMLTRAFFICLIGHTER_CAR_H
#define SFMLTRAFFICLIGHTER_CAR_H

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
        float inWHeelAngle;
    } car;
    float speed;

    void setPosition(sf::Vector2f);

    void update();

public:
    bool canRide{};

    Car();

    explicit Car(sf::Vector2f);

    void moveForward();

    void moveBack();

    sf::Vector2f getPosition();

    void show(sf::RenderWindow *);
};

#endif
#pragma once

#include <SFML/Graphics.hpp>

class Lighter {
private:
    sf::Vector2f pos;
    struct TrafficLight {
        sf::RectangleShape box;
        sf::RectangleShape stick;
        sf::CircleShape green;
        sf::CircleShape yellow;
        sf::CircleShape red;
    } lighter;

    void update();

    void setPosition(sf::Vector2f);

public:
    enum Active {
        GREEN = 1,
        YELLOW,
        RED
    } active;

    Lighter();

    explicit Lighter(sf::Vector2f);

    void updateLight();

    sf::Vector2f getPosition();

    void show(sf::RenderWindow &);
};


//
// Created by bylaew on 19.01.2020.
//

#ifndef SFMLTRAFFICLIGHTER_WORLD_H
#define SFMLTRAFFICLIGHTER_WORLD_H

#include <SFML/Graphics.hpp>
#include "Lighter.h"
#include "Car.h"

class World {
private:
    sf::RenderWindow *window;
    sf::Event event;
    Car *car;
    Lighter *lighter;
    sf::Clock clock;
    sf::Clock shortClock;
    sf::Time shortClockElapsed;
    float deltaTime;

    void initWindow();

public:
    World();

    virtual ~World();

    void eventUpdate();

    void updateDeltaTime();

    void update();

    void render();

    void create();
};


#endif //SFMLTRAFFICLIGHTER_WORLD_H

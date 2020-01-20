//
// Created by bylaew on 20.01.2020.
//

#ifndef SFMLTRAFFICLIGHTER_ENTITY_H
#define SFMLTRAFFICLIGHTER_ENTITY_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <stack>
#include <map>

class Entity {
protected:
    sf::RectangleShape shape;
    float speed;
public:
    Entity();

    ~Entity();

    void move(const float &deltaTime, const float drx, const float dry);

    void update(const float &deltaTime);

    void render(sf::RenderTarget *target);
};


#endif //SFMLTRAFFICLIGHTER_ENTITY_H

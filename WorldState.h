//
// Created by bylaew on 20.01.2020.
//

#ifndef SFMLTRAFFICLIGHTER_WORLDSTATE_H
#define SFMLTRAFFICLIGHTER_WORLDSTATE_H


#include "State.h"

class WorldState : public State {
private:
    Entity tmp;
public:
    WorldState(sf::RenderWindow *);

    ~WorldState();

    void end();

    void update(const float &deltaTime);

    void updateKeyBinds(const float &deltaTime);

    void render(sf::RenderTarget *target);
};


#endif //SFMLTRAFFICLIGHTER_WORLDSTATE_H

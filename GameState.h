//
// Created by bylaew on 20.01.2020.
//

#ifndef SFMLTRAFFICLIGHTER_GAMESTATE_H
#define SFMLTRAFFICLIGHTER_GAMESTATE_H


#include "State.h"

class GameState : public State {
private:
    Entity tmp;
public:
    GameState(sf::RenderWindow *);

    ~GameState();

    void end();

    void update(const float &deltaTime);

    void updateKeyBinds(const float &deltaTime);

    void render(sf::RenderTarget *target);
};


#endif //SFMLTRAFFICLIGHTER_GAMESTATE_H

//
// Created by bylaew on 20.01.2020.
//

#ifndef SFMLTRAFFICLIGHTER_STATE_H
#define SFMLTRAFFICLIGHTER_STATE_H

#include <SFML/Graphics/RenderTarget.hpp>
#include "Entity.h"

class State {
private:
    bool exit;
protected:
    sf::RenderWindow *window;
public:
    State(sf::RenderWindow *);

    virtual ~State();

    const bool &getExit() const;

    virtual void checkForExit();

    virtual void end() = 0;

    virtual void updateKeyBinds(const float &deltaTime) = 0;

    virtual void update(const float &deltaTime) = 0;

    virtual void render(sf::RenderTarget *target = NULL) = 0;

};


#endif //SFMLTRAFFICLIGHTER_STATE_H

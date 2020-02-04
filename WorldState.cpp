//
// Created by bylaew on 20.01.2020.
//

#include "WorldState.h"

WorldState::WorldState(sf::RenderWindow *window) : State(window) {

}

WorldState::~WorldState() {

}

void WorldState::updateKeyBinds(const float &deltaTime) {

}

void WorldState::update(const float &deltaTime) {
    updateKeyBinds(deltaTime);
    tmp.update(deltaTime);
}

void WorldState::render(sf::RenderTarget *target) {
    if (!target)
        target = window;
    tmp.render(window);
}

void WorldState::end() {

}


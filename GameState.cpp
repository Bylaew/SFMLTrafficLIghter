//
// Created by bylaew on 20.01.2020.
//

#include "GameState.h"

GameState::GameState(sf::RenderWindow *window) : State(window) {

}

GameState::~GameState() {

}

void GameState::updateKeyBinds(const float &deltaTime) {

}

void GameState::update(const float &deltaTime) {
    updateKeyBinds(deltaTime);
    tmp.update(deltaTime);
}

void GameState::render(sf::RenderTarget *target) {
    if (!target)
        target = window;
    tmp.render(window);
}

void GameState::end() {

}


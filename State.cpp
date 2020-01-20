//
// Created by bylaew on 20.01.2020.
//

#include "State.h"

State::State(sf::RenderWindow *window) {
    this->window = window;
    exit = false;
}

State::~State() {

}

void State::checkForExit() {
    if (sf::Keyboard::isKeyPressed((sf::Keyboard::Escape))) {
        exit = true;
    }
}

const bool &State::getExit() const {
    return exit;
}

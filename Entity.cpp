//
// Created by bylaew on 20.01.2020.
//

#include "Entity.h"

Entity::Entity() {
    shape.setSize(sf::Vector2f(100.f, 100.f));
    shape.setFillColor(sf::Color::White);
}

Entity::~Entity() {

}

void Entity::move(const float &deltaTime, const float drx, const float dry) {
    shape.move(drx * deltaTime * speed, dry * deltaTime * speed);
}

void Entity::update(const float &deltaTime) {

}

void Entity::render(sf::RenderTarget *target) {
    target->draw(shape);
}



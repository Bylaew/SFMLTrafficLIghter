#include "Lighter.h"


void Lighter::update() {
    lighter.box.setFillColor(sf::Color::Transparent);
    lighter.box.setOutlineColor(sf::Color::White);
    lighter.box.setOutlineThickness(10);
    lighter.box.setSize(sf::Vector2f(80, 240));
    lighter.box.setPosition(pos);

    lighter.stick.setFillColor(sf::Color::White);
    lighter.stick.setPosition(sf::Vector2f(pos.x + 35.f, pos.y + 260.f));
    lighter.stick.setSize(sf::Vector2f(5, 170));
    lighter.stick.setOutlineThickness(10);
    lighter.green.setRadius(40);

    lighter.red.setRadius(40);
    if (active == RED)
        lighter.red.setFillColor(sf::Color::Red);
    else
        lighter.red.setFillColor(sf::Color(74, 45, 45, 127));
    lighter.red.setPosition(sf::Vector2f(pos.x, pos.y));

    lighter.yellow.setRadius(40);
    if (active == YELLOW)
        lighter.yellow.setFillColor(sf::Color::Yellow);
    else
        lighter.yellow.setFillColor(sf::Color(74, 60, 45, 127));
    lighter.yellow.setPosition(sf::Vector2f(pos.x, pos.y + 80.f));

    if (active == GREEN)
        lighter.green.setFillColor(sf::Color::Green);
    else
        lighter.green.setFillColor(sf::Color(62, 74, 45, 127));
    lighter.green.setPosition(sf::Vector2f(pos.x, pos.y + 160.f));
}


Lighter::Lighter() {
    pos = sf::Vector2f(0.f, 0.f);

    active = RED;

    update();
}

Lighter::Lighter(sf::Vector2f position) {
    pos = position;

    active = RED;

    update();
}


void Lighter::setPosition(sf::Vector2f newPos) {
    pos = newPos;

    update();
}


void Lighter::updateLight() {
    if (active == RED) {
        active = YELLOW;
    } else if (active == YELLOW) {
        active = GREEN;
    } else {
        active = RED;
    }
    update();
}


sf::Vector2f Lighter::getPosition() {
    return pos;
}


void Lighter::show(sf::RenderWindow *window) {
    window->draw(lighter.green);
    window->draw(lighter.yellow);
    window->draw(lighter.red);
    window->draw(lighter.box);
    window->draw(lighter.stick);
}


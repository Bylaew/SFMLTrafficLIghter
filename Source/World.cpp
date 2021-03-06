#include "../Headers/World.h"

void World::initWindow() {
    window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Traffic Lighter");
}

void World::initStates() {
    states.push(new WorldState(window));
}

World::World() {
    initWindow();
    initStates();
    shortClockElapsed = shortClock.getElapsedTime();
    car = new Car(sf::Vector2f(560.f, 600.f));
    lighter = new Lighter(sf::Vector2f(1400.f, 250.f));
}

World::~World() {
    delete window;
    while (!states.empty()) {
        delete states.top();
        states.pop();
    }
}

void World::eventUpdate() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window->close();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (shortClockElapsed.asSeconds() > 1.f / 2.f)
            lighter->updateLight();
        shortClock.restart();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        car->moveForward();
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        car->moveBack();
    }
}

void World::updateDeltaTime() {
    deltaTime = clock.getElapsedTime().asSeconds();
    shortClockElapsed = shortClock.getElapsedTime();
}

void World::update() {
    eventUpdate();
    if (!states.empty())
        states.top()->update(deltaTime);
    car->moveForward();
    car->canRide = !(lighter->active != 1 && car->getPosition().x + 450 ==
                                             lighter->getPosition().x);
    if (shortClockElapsed.asSeconds() > 10 &&
        lighter->active != 2) {
        lighter->updateLight();
        shortClock.restart();
    } else if (lighter->active == 2 && shortClockElapsed.asSeconds() > 3) {
        lighter->updateLight();
    }
}

void World::render() {
    window->clear(sf::Color::Black);
    if (!states.empty())
        states.top()->render();
    lighter->show(window);
    car->show(window);
    window->display();
}

void World::create() {
    while (window->isOpen()) {
        updateDeltaTime();
        update();
        render();
    }
}

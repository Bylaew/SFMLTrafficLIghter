#include <SFML/Graphics.hpp>
#include "Lighter.h"
#include "Car.h"

//var active: 1 is GREEN, 2 is YELLOW and 3 is RED

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "TrafficLighter");
    Lighter tLighter(sf::Vector2f(1400.f, 250.f));
    Car car(sf::Vector2f(560.f, 600.f));
    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event{};
        sf::Time elapsed = clock.getElapsedTime();
        car.moveForward();
        car.canRide = !(tLighter.active != 1 && car.getPosition().x + 450 ==
                                                tLighter.getPosition().x);
        if (elapsed.asSeconds() > 10 &&
            tLighter.active != 2) {
            tLighter.updateLight();
            clock.restart();
        } else if (tLighter.active == 2 && elapsed.asSeconds() > 3) {
            tLighter.updateLight();
        }
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (elapsed.asSeconds() > 1.f / 2.f)
                tLighter.updateLight();
            clock.restart();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            car.moveForward();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            car.moveBack();
        }
        window.clear(sf::Color::Black);
        tLighter.show(window);
        car.show(window);
        window.display();
    }

    return 0;
}
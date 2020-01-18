#include "Car.h"

void Car::update() {

    car.corpse.setPosition(position);
    car.corpse.setFillColor(sf::Color::Magenta);
    car.corpse.setOutlineColor(sf::Color::Cyan);
    car.corpse.setOutlineThickness(1);
    car.corpse.setSize(sf::Vector2f(450, 120));

    car.head.setPosition(sf::Vector2f(position.x + 200, position.y - 151.f));
    car.head.setFillColor(sf::Color::Magenta);
    car.head.setOutlineColor(sf::Color::Cyan);
    car.head.setOutlineThickness(1);
    car.head.setSize(sf::Vector2f(170.f, 150.f));

    car.wheelOne.setPosition(sf::Vector2f(position.x + 320, position.y + 70));
    car.wheelOne.setRadius(50);

    car.inWheelOne.setPosition(sf::Vector2f(position.x + 370, position.y + 120));
    car.inWheelOne.setRadius(35);
    car.inWheelOne.setPointCount(4);
    car.inWheelOne.setFillColor(sf::Color::Blue);
    car.inWheelOne.setRotation(car.inWHeelAngle);
    car.inWheelOne.setOrigin(sf::Vector2f(35.f, 35.f));

    car.wheelTwo.setPosition(sf::Vector2f(position.x + 60, position.y + 70));
    car.wheelTwo.setRadius(50);

    car.inWheelTwo.setOrigin(sf::Vector2f(35.f, 35.f));
    car.inWheelTwo.setPosition(sf::Vector2f(position.x + 110, position.y + 120));
    car.inWheelTwo.setRadius(35);
    car.inWheelTwo.setPointCount(4);
    car.inWheelTwo.setFillColor(sf::Color::Blue);
    car.inWheelTwo.setRotation(car.inWHeelAngle);
}


Car::Car() {
    car.inWHeelAngle = 0.f;
    position = sf::Vector2f(0.f, 0.f);
    speed = 0.5f;
    update();
}


Car::Car(sf::Vector2f pos) {
    car.inWHeelAngle = 0.f;
    position = pos;
    speed = 0.5f;
    update();
}


void Car::setPosition(sf::Vector2f nPos) {
    position = nPos;
    if (position.x > 1900) {
        position.x = -500;
    } else if (position.x < -501) {
        position.x = 1900;
    }
    update();
}


void Car::moveForward() {
    if (canRide) {
        setPosition(sf::Vector2f(position.x + 0.5f, position.y));
        car.inWHeelAngle += speed;
    }
}

void Car::moveBack() {
    if (canRide) {
        setPosition(sf::Vector2f(position.x - 1, position.y));
        car.inWHeelAngle -= speed * 2;
    }
}

sf::Vector2f Car::getPosition() {
    return position;
}


void Car::show(sf::RenderWindow *window) {
    window->draw(car.corpse);
    window->draw(car.head);
    window->draw(car.wheelOne);
    window->draw(car.wheelTwo);
    window->draw(car.inWheelOne);
    window->draw(car.inWheelTwo);
}

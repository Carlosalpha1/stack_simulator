#include "button.h"

void Button::createButton()
{
    color_not_pressed_ = sf::Color(0, 255, 0);
    color_pressed_ = sf::Color(98, 147, 98);
    setFillColor(color_not_pressed_);
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(2);
    is_pressed_ = false;
}

Button::Button(float radius)
    : sf::CircleShape(radius)
{
    setRadius(radius);
    setPosition(0, 0);
    createButton();
}

Button::Button(int x, int y, float radius)
    : sf::CircleShape(radius)
{
    setRadius(radius);
    setPosition(x, y);
    createButton();
}

void Button::set_pressed(bool status)
{
    is_pressed_ = status;
    if (is_pressed_)
        setFillColor(color_pressed_);
    else
        setFillColor(color_not_pressed_);
}

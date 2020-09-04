#include "button.h"

void Button::createButton()
{
    color_not_pressed_ = sf::Color(0, 255, 0);
    color_pressed_ = sf::Color(98, 147, 98);
    setFillColor(color_not_pressed_);
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(2);
    is_pressed_ = false;
    setPosition(x_, y_);
}

Button::Button(float radius)
    : sf::CircleShape(radius)
{
    x_ = y_ = 0;
    radius_ = radius;
    createButton();
}

Button::Button(int x, int y, float radius)
    : sf::CircleShape(radius)
{
    x_ = x;
    y_ = y;
    radius_ = radius;
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

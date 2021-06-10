#include "cell.h"

Cell::Cell(int x, int y, int base, int height)
    : sf::RectangleShape(sf::Vector2f(base, height))
{
    x_ = x;
    y_ = y;
    base_ = base;
    height_ = height;
    setFillColor(sf::Color::White);
    setOutlineColor(sf::Color::Black);
    setOutlineThickness(2);
    font_.loadFromFile(font_route);
    updatePositions();
}

void Cell::adjustCell(sf::RenderWindow & rw, bool op)
{
    int increment;

    if (op == 0) {
        int mid_base = x_ + getBase()/2;
        int mid_window_base = rw.getSize().x / 2;
        increment = mid_base - mid_window_base;
        x_ -= increment;
    }
    else {
        int mid_height = y_ + getHeight()/2;
        int mid_window_height = rw.getSize().y / 2;
        increment = mid_height - mid_window_height;
        y_ -= increment;
    }
    updatePositions();
}

void Cell::setText(const std::string & str, unsigned int characterSize)
{
    text_.setString(str);
    text_.setFont(font_);
    text_.setCharacterSize(characterSize);
    text_.setFillColor(sf::Color::Black);
}

void Cell::updatePositions()
{
    setPosition(x_, y_);
    text_.setPosition(x_ + 15, y_ + 10);
}

std::ostream & operator<<(std::ostream & os, const Cell & c)
{
    std::string strtext = c.text_.getString();
    os << "(" << c.x_ << "," << c.y_ << "," << strtext << ")";
    return os;
}

#ifndef CELL_H_
#define CELL_H_
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

static const std::string font_route = "../font/textcell.TTF";

class Cell : public sf::RectangleShape
{
private:
    int x_;
    int y_;
    int base_;
    int height_;
    sf::Text text_;
    sf::Font font_;

    void updatePositions();

public:
    Cell(int x = 0, int y = 0, int base = 50, int height = 50);
    int getBase() const { return base_; }
    int getHeight() const { return height_; }
    int getX() const { return x_; }
    int getY() const { return y_; }
    void adjustCell(sf::RenderWindow & rw, bool op = 0);
    void setText(const std::string & str, unsigned int characterSize=30);
    sf::Text & getText() {return text_;}

    friend std::ostream & operator<<(std::ostream & os, const Cell & c);
};

#endif

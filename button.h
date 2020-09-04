#ifndef BUTTON_H_
#define BUTTON_H_
#include <SFML/Graphics.hpp>

class Button : public sf::CircleShape
{
private:
    sf::Color color_not_pressed_;
    sf::Color color_pressed_;
    bool is_pressed_;
    int x_, y_;
    float radius_;

    void createButton();

public:
    Button(float radius);
    Button(int x, int y, float radius);
    void set_pressed(bool status);
    int getX() const { return x_; }
    int getY() const { return y_; }
    int getRadius() const { return radius_; }
};

#endif

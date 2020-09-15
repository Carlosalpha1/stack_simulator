#ifndef BUTTON_H_
#define BUTTON_H_
#include <SFML/Graphics.hpp>

class Button : public sf::CircleShape
{
private:
    sf::Color color_not_pressed_;
    sf::Color color_pressed_;
    bool is_pressed_;

    void createButton();

public:
    Button(float radius);
    Button(int x, int y, float radius);
    void set_pressed(bool status);
    int getX() const { return getPosition().x; }
    int getY() const { return getPosition().y; }
};

#endif

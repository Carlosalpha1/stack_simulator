#include "cell.h"   // include <SFML/Graphics.hpp> and <iostream>
#include "cellstack.h"
#include "button.h"

const int WIDTH = 600;
const int HEIGHT = 600;

bool is_clicked(Button & b);

sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "STACK SIMULATION");

int main()
{
    using std::cout;
    using std::endl;

    cout << "Button Left: Push\n";
    cout << "Button Right: Pop" << endl;

    Button button_push(420, 60, 20);
    Button button_pop(420, 120, 20);

    sf::Font font;
    font.loadFromFile("../font/textcell.TTF");
    sf::Text text_push("PUSH", font, 22);
    sf::Text text_pop("POP", font, 22);
    text_push.setFillColor(sf::Color(18, 229, 239));
    text_pop.setFillColor(sf::Color(18, 229, 239));
    text_push.setPosition(button_push.getX() + 50, button_push.getY() + 5);
    text_pop.setPosition(button_pop.getX() + 50, button_pop.getY() + 5);

    sf::Text text_sizelist("SIZE", font, 30);
    sf::Text text_numelems;
    sf::RectangleShape wnd_sizelist(sf::Vector2f(100, 140));
    wnd_sizelist.setPosition(sf::Vector2f(60, 60));
    wnd_sizelist.setOutlineColor(sf::Color::Black);
    wnd_sizelist.setOutlineThickness(2);
    text_sizelist.setFillColor(sf::Color::Black);
    text_numelems.setFillColor(sf::Color::Black);
    text_numelems.setFont(font);
    text_numelems.setCharacterSize(40);
    text_sizelist.setPosition(wnd_sizelist.getPosition().x + 15, wnd_sizelist.getPosition().y + 15);
    text_numelems.setPosition(text_sizelist.getPosition().x + 25, text_sizelist.getPosition().y + 50);

    std::string text_objeto = "objeto #";

    CellStack cst(window);

    int cont = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || is_clicked(button_push)) {
                if (cst.getSize() < 10) {
                    text_objeto = "objeto #" + std::to_string(++cont);
                    cst.push(text_objeto);
                }
                button_push.set_pressed(true);
            } else
                button_push.set_pressed(false);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || is_clicked(button_pop)) {
                if (!cst.isEmpty())
                    --cont;
                cst.pop();
                button_pop.set_pressed(true);
            } else
                button_pop.set_pressed(false);
        }

        text_numelems.setString(std::to_string(cst.getSize()));

        window.clear(sf::Color(252, 144, 144));
        cst.draw();
        window.draw(button_push);
        window.draw(button_pop);
        window.draw(text_push);
        window.draw(text_pop);
        window.draw(wnd_sizelist);
        window.draw(text_sizelist);
        window.draw(text_numelems);
        window.display();
    }

    return 0;
}

bool is_clicked(Button & b)
{
    if (sf::Mouse::getPosition(window).x > b.getX() &&
        sf::Mouse::getPosition(window).x < (b.getX() + 2*b.getRadius()) &&
        sf::Mouse::getPosition(window).y > b.getY() &&
        sf::Mouse::getPosition(window).y < (b.getY() + 2*b.getRadius()) &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left))
        return true;
    else
        return false;
}

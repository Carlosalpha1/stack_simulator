#ifndef CELLSTACK_H_
#define CELLSTACK_H_
#include <SFML/Graphics.hpp>
#include "cell.h"

class CellStack
{
private:
    struct Node
    {
        Cell * cell;
        Node * next;
    };

    int elems;
    int xinit_, yinit_;
    int increment_;

    Node * top;
    sf::RenderWindow * wnd;

public:
    CellStack(sf::RenderWindow & window);
    ~CellStack();
    bool isEmpty() { return elems == 0; }
    int getSize() { return elems; }
    void push(const std::string & name);
    std::string pop();
    void draw() const;

    friend std::ostream & operator<<(std::ostream & os, const CellStack & cst);
};

#endif

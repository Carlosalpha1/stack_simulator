#include "cellstack.h"

CellStack::CellStack(sf::RenderWindow & window)
{
    top = NULL;
    elems = 0;
    wnd = &window;
    xinit_ = wnd->getSize().x / 2;
    yinit_ = wnd->getSize().y - 80;
    increment_ = 51;
}

CellStack::~CellStack()
{
    Node * current = top;
    Node * temp;
    while(current != NULL)
    {
        temp = current;
        current = current->next;
        delete temp->cell;
        delete temp;
        temp = NULL;
    }
}

void CellStack::push(const std::string & name)
{
    Cell * cell = new Cell(xinit_, yinit_, 150, 50);
    cell->adjustCell(*wnd);
    cell->setText(name, 22);

    if (isEmpty()) {
        top = new Node();
        top->cell = cell;
        top->next = NULL;
    } else {
        Node * aux = new Node();
        aux->cell = cell;
        aux->next = top;
        top = aux;
    }
    elems++;
    yinit_ -= increment_;
}

std::string CellStack::pop()
{
    if (isEmpty())
        return "Empty";
    std::string return_str = top->cell->getText().getString();
    Node * temp = top;
    top = top->next;
    delete temp->cell;
    delete temp;
    elems--;
    yinit_ += increment_;
    return return_str;
}

void CellStack::draw() const
{
    Node * current = top;
    int cont = 0;
    while (current != NULL)
    {
        wnd->draw(*(current->cell));
        wnd->draw(current->cell->getText());
        current = current->next;
    }
}

std::ostream & operator<<(std::ostream & os, const CellStack & cst)
{
    CellStack::Node * current = cst.top;
    while (current != NULL) {
        os << *current->cell << " -> ";
        current = current->next;
    }
    return os;
}

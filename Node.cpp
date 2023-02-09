#include "Node.hpp"

Node::Node(){
};


Node::Node(unsigned int row, unsigned int col, double g): Cell(row, col), g{g}{
};

Node::Node(Cell c, double g, double h){
    this->row = c.row;
    this->col = c.col;
    this->g = g;
    this->h = h;
    this->f = g + h;
};

Node::Node(const Cell * c, double g, double h): Node(*c, g, h){
};

bool Node::operator<(Node const &n) const{
    return this->f < n.f;
};

bool Node::operator>(Node const &n) const{
    return this->f > n.f;
};

bool Node::operator==(Node const &n) const{
    return this->f == n.f;
};

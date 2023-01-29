#include "Node.hpp"

Node::Node(){
};


Node::Node(unsigned int row, unsigned int col, double f): Cell(row, col), f{f}{
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

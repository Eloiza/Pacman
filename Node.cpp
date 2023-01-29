#include "Node.hpp"

Node::Node(){
};

Node::Node(unsigned int x, unsigned int y): x{x}, y{y}{
};

Node::Node(unsigned int x, unsigned int y, double f): x{x}, y{y}, f{f}{
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

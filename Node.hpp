#ifndef NODE_HPP
#define NODE_HPP
#include "Cell.hpp"

class Node : public Cell{
    public:
        Node();
        Node(unsigned int row, unsigned int col, double g);
        Node(Cell c, double g, double h);
        Node(const Cell * c, double g, double h);

        virtual ~Node() = default;

        bool operator<(Node const &n) const;
        bool operator>(Node const &n) const;
        bool operator==(Node const &n) const;

        Node * parent;
        bool open;
        bool closed;
        double f;
        double g;
        double h;
};
#endif
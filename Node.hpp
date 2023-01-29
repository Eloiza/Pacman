#ifndef NODE_HPP
#define NODE_HPP
#include "Cell.hpp"

class Node : public Cell{
    public:
        Node();
        Node(unsigned int row, unsigned int col, double f);

        virtual ~Node() = default;

        bool operator<(Node const &n) const;
        bool operator>(Node const &n) const;
        bool operator==(Node const &n) const;

        double f;
};
#endif
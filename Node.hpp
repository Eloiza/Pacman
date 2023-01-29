#ifndef NODE_HPP
#define NODE_HPP
#include "Cell.hpp"

class Node : public Cell{
    public:
        Node();
        Node(unsigned int x, unsigned int y);
        Node(unsigned int x, unsigned int y, double f);
        Node(unsigned int x, unsigned int y, double f, char direction);

        virtual ~Node() = default;

        bool operator<(Node const &n) const;
        bool operator>(Node const &n) const;
        bool operator==(Node const &n) const;

        double f;
};
#endif
#ifndef INVALID_POSITION_EXCEPTION_HPP
#define INVALID_POSITION_EXCEPTION_HPP

#include <stdexcept>
#include "Cell.hpp"

class InvalidPositionException : public std::invalid_argument{
    public:
        const Cell * position;
        InvalidPositionException(const Cell * position);
        virtual ~InvalidPositionException() = default;
};

#endif
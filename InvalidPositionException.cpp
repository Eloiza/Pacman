#include "InvalidPositionException.hpp"

InvalidPositionException::InvalidPositionException(
    const Cell * position)
    : std::invalid_argument{"Tried to set argument to an invalid position"}, position{position}{
}
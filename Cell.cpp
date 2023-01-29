#include "Cell.hpp"

Cell::Cell(){
};

Cell::Cell(unsigned int row, unsigned int col): row{row}, col{col}{
};

void Cell::setCell(unsigned int row, unsigned int col){
    this->row = row;
    this->col = col;
};

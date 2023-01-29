#ifndef CELL_HPP
#define CELL_HPP

class Cell{
    public:
        Cell();
        Cell(unsigned int row, unsigned int col);

        virtual ~Cell() = default;

        void setCell(unsigned int row, unsigned int col);
        unsigned int row; 
        unsigned int col; 
};

#endif
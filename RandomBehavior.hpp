#include "Behavior.hpp"

class RandomBehavior: public Behavior{
    public:
        virtual ~RandomBehavior() = default;
        virtual std::list<Cell *> generateTarget() = 0;
        
};
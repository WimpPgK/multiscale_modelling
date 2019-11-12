#ifndef NEIGHBOURHOOD_H
#define NEIGHBOURHOOD_H
#include "Id.h"
#include "Grain.h"

class Neighbourhood
{
    public:

        Neighbourhood();
        Id* getBestNeighbour(int, int, int, Grain*** );
        virtual ~Neighbourhood();

    protected:

    private:
        int tab[26];
};

#endif // NEIGHBOURHOOD_H

#ifndef NEIGHBOURHOOD_H
#define NEIGHBOURHOOD_H
#include "Id.h"
#include "Grain.h"
#include "iostream"

class Neighbourhood
{
    public:
		Id* pom[28];
        Neighbourhood();
        Id* getBestNeighbour(int, int, int, Grain*** );
        Id* mostFrequentValue_NaiveAlgorithm(Id**);
        virtual ~Neighbourhood();

    protected:

    private:

        void mostFrequentValue_NaiveAlgorithm();
};

#endif // NEIGHBOURHOOD_H

#ifndef GRAINGROWTH_H
#define GRAINGROWTH_H
#include "Grain.h"
#include "Id.h"


class GrainGrowth
{
    public:
        int x;
        int y;
        int z;
        int number_of_inclusioin;
        Id* id;
        Grain*** matrix;

        void printMatrix();
        GrainGrowth(int, int, int, int);
        void randomizeGrain();
        virtual ~GrainGrowth();

    protected:

    private:
};

#endif // GRAINGROWTH_H

#ifndef GRAINGROWTH_H
#define GRAINGROWTH_H
#include "Grain.h"
#include "Id.h"
#include "Neighbourhood.h"
#include "FileOperator.h"


class GrainGrowth
{
    public:
        int x;
        int y;
        int z;
        int number_of_inclusioin;
        Id* id;
        Grain*** matrix01;
        Grain*** matrix02;

        void printMatrix();
        GrainGrowth(int, int, int, int);
        void startGrowth();
        void randomizeGrain();
		void saveToFile();
        virtual ~GrainGrowth();

    protected:

    private:
};

#endif // GRAINGROWTH_H

#include "Neighbourhood.h"

Neighbourhood::Neighbourhood()
{
    int i;
    for(i = 0 ; i < 26 ; i++)
    {
        tab[i] = -1;
    }
}


Id* getBestNeighbour(int x, int y, int z, Grain*** matrix)
{
    int licznik;
    //MOORE

    if(x!= 0 && y!= 0 && z!=0)
    {
       //over the grain
        matrix[x+1][y+1][z+1].getId();
        /*matrix[x+1][y][z+1]
        matrix[x+1][y-1][z+1]
        matrix[x][y+1][z+1]
        matrix[x][y][z+1]
        matrix[x][y-1][z+1]
        matrix[x-1][y+1][z+1]
        matrix[x-1][y][z+1]
        matrix[x-1][y-1][z+1]

        // on the same level
        matrix[x+1][y+1][z]
        matrix[x+1][y][z]
        matrix[x+1][y-1][z]
        matrix[x][y+1][z]
        matrix[x][y-1][z]
        matrix[x-1][y+1][z]
        matrix[x-1][y][z]
        matrix[x-1][y-1][z]


        // under the grain
        matrix[x+1][y+1][z-1]
        matrix[x+1][y][z-1]
        matrix[x+1][y-1][z-1]
        matrix[x][y+1][z-1]
        matrix[x][y][z-1]
        matrix[x][y-1][z-1]
        matrix[x-1][y+1][z-1]
        matrix[x-1][y][z-1]
        matrix[x-1][y-1][z-1] */
        }

        return 0;
}



Neighbourhood::~Neighbourhood()
{
    //dtor
}

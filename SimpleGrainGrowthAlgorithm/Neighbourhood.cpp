#include "Neighbourhood.h"
using namespace std;

Neighbourhood::Neighbourhood()
{
    int i;
    for(i = 0 ; i < 26 ; i++)
    {

    }
}
void mostFrequentValue_NaiveAlgorithm(Id**);



Id* Neighbourhood::getBestNeighbour(int x, int y, int z, Grain*** matrix)
{

    int licznik;
    //MOORE
    Id** pom = new Id*[26];

    if(x != 0 && y != 0 && z!=0)
    {

       //over the grain
        pom [0] = matrix[x+1][y+1][z+1].getId();
        pom [1] = matrix[x+1][y][z+1].getId();
        pom [2] = matrix[x+1][y-1][z+1].getId();
        pom [3] = matrix[x][y+1][z+1].getId();
        pom [4] = matrix[x][y][z+1].getId();
        pom [5] = matrix[x][y-1][z+1].getId();
        pom [6] = matrix[x-1][y+1][z+1].getId();
        pom [7] = matrix[x-1][y][z+1].getId();
        pom [8] = matrix[x-1][y-1][z+1].getId();

        // on the same level
        pom [9] = matrix[x+1][y+1][z].getId();
        pom [10] = matrix[x+1][y][z].getId();
        pom [11] = matrix[x+1][y-1][z].getId();
        pom [12] = matrix[x][y+1][z].getId();
        pom [13] = matrix[x][y-1][z].getId();
        pom [14] = matrix[x-1][y+1][z].getId();
        pom [15] = matrix[x-1][y][z].getId();
        pom [16] = matrix[x-1][y-1][z].getId();


        // under the grain
        pom [17] = matrix[x+1][y+1][z-1].getId();
        pom [18] = matrix[x+1][y][z-1].getId();
        pom [19] = matrix[x+1][y-1][z-1].getId();
        pom [20] = matrix[x][y+1][z-1].getId();
        pom [21] = matrix[x][y][z-1].getId();
        pom [22] = matrix[x][y-1][z-1].getId();
        pom [23] = matrix[x-1][y+1][z-1].getId();
        pom [24] = matrix[x-1][y][z-1].getId();
        pom [25] = matrix[x-1][y-1][z-1].getId();
        return mostFrequentValue_NaiveAlgorithm(pom);

    }



    //cout << mostFrequentValue_NaiveAlgorithm(pom)  << "  ";
    return 0;
}


Id* Neighbourhood::mostFrequentValue_NaiveAlgorithm(Id** tab)
{
    int i,j;
    int counter = 0;
    int maxValue = 0;
    Id* mostFrequent = 0;
    Id* pom = 0;

    /*
    for (i = 0 ; i < 26 ; i++)
    {
        cout << "s" << tab[i] ;
    }
    cout << endl;
    */

    for(i = 0 ; i < 26 ; i++)
    {
        pom = tab[i];
        for (j = 0 ; j < 26 ; j++)
        {
            if(pom == tab[j] && tab[j] != 0)
            {
                //cout <<"counter dziala" << endl;
                counter++;
            }
        }
        if(counter > maxValue)
        {
            maxValue = counter;
            mostFrequent = pom;
        }
        counter = 0;

    }

    if(mostFrequent == 0)
    {
        //cout << mostFrequent << "AAA" << endl;
        return 0;

    }


    return mostFrequent;
}



Neighbourhood::~Neighbourhood()
{
    //dtor
}

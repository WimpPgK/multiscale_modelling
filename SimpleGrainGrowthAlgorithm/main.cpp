#include "GrainGrowth.h"
#include <iostream>

//potrzebuje: pozycjax, pozycjay, pozycjaz, kolorR, kolorG, kolorB, alpha
using namespace std;

int main()
{
    int x = 3;
    int y = 10;
    int z = 10;
    int number_of_inclusioin = 20;
    GrainGrowth g1 = GrainGrowth(x,y,z,number_of_inclusioin);
    g1.randomizeGrain();
    g1.printMatrix();
    g1.startGrowth();


    cout <<"***********************************" << endl;
    cout << endl;
    g1.printMatrix();


    cout << "Hello world!" << endl;
    return 0;
}

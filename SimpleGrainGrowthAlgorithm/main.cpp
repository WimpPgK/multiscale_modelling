#include "GrainGrowth.h"
#include <iostream>

//potrzebuje: pozycjax, pozycjay, pozycjaz, kolorR, kolorG, kolorB, alpha
using namespace std;

int main()
{
    int x = 100;
    int y = 100;
    int z = 100;
    int number_of_inclusioin = 5000;
    GrainGrowth g1 = GrainGrowth(x,y,z,number_of_inclusioin);
    g1.randomizeGrain();
    //g1.printMatrix();
        cout <<"***********************************" << endl;
    cout << endl;

    g1.startGrowth();
    //g1.printMatrix();



    cout << "Hello world!" << endl;
    return 0;
}

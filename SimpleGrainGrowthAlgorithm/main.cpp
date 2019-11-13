#include "GrainGrowth.h"
#include <iostream>

//potrzebuje: pozycjax, pozycjay, pozycjaz, kolorR, kolorG, kolorB, alpha
using namespace std;

int main()
{
    int x = 50;
    int y = 50;
    int z = 50;
    int number_of_grains = 10;
    GrainGrowth g1 = GrainGrowth(x+2,y+2,z+2,number_of_grains);
    g1.randomizeGrain();
    //g1.printMatrix();
        cout <<"***********************************" << endl;
    cout << endl;

    g1.startGrowth();
	g1.saveToFile();
    //g1.printMatrix();



    cout << "Hello world!" << endl;
    return 0;
}

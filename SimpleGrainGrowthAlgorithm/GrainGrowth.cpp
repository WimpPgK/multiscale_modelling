#include "GrainGrowth.h"
#include "Grain.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

GrainGrowth::GrainGrowth(int x, int y, int z, int number_of_inclusioin)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->number_of_inclusioin = number_of_inclusioin;

    int i = 0;
    int j = 0;
    int k = 0;

    id = new Id[number_of_inclusioin];
    matrix = new Grain**[x];

    for(i = 0 ; i < x ; i++)
    {
        matrix[i] = new Grain*[y];
        for(j = 0 ; j < y ; j++)
        {
            matrix[i][j] = new Grain[z];
        }
    }
    //double licznik = 0;
    for(i = 0 ; i < x ; i++)
    {
        for(j = 0 ; j < y ; j++)
        {
            for(k = 0 ; k < z ; k++)
            {
                matrix[i][j][k].setPosition(i,j,k);
            }
        }
    }
}

void GrainGrowth::randomizeGrain()
{
    srand(time(NULL));
    int i;
    // initialization of id tab for inclusion
    for(i = 0 ; i < number_of_inclusioin ; i++)
    {
        id[i].SetColor((double)rand()/(RAND_MAX), (double)rand()/(RAND_MAX), (double)rand()/(RAND_MAX), 1);
        //cout << &id[i] << endl;
        //cout << id[i].color_r << "  " << id[i].color_g << "   " <<  id[i].color_b <<"  " << id[i].alpha<< endl;

    }
    // set random position for inclusion
    for(i = 0 ; i < number_of_inclusioin ; i++)
    {
        int random_x_position = rand()%x;
        int random_y_position = rand()%y;
        int random_z_position = rand()%z;
        //cout << random_x_position << endl;
        matrix[random_x_position][random_y_position][random_z_position].setId(&id[i]);
    }
}


void GrainGrowth::startGrowth()
{


}








//********************************************************************************************************/

void GrainGrowth::printMatrix()
{
    int i,j,k;
    for(i = 0 ; i < x ; i++)
    {
        for(j = 0 ; j < y ; j++)
        {
            for(k = 0 ; k < z ; k++)
            {
                if(matrix[i][j][k].id != 0)
                {
                    cout << "A" << " ";
                }
                else
                {
                    cout << matrix[i][j][k].id << " ";
                }

            }
            cout << endl;
        }

        cout << endl << endl <<endl;
    }
}

GrainGrowth::~GrainGrowth()
{
    //dtor
}

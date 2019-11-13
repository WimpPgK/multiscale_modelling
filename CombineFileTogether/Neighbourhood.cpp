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
	Id* returnValue;
    //MOORE
    //pom = new Id*[26];

	//create moore tab
	//check neighbour
	//chance of change
	
	/*
	Moore m1 = Moore();
	pom = m1.GetNeighborTab(x, y, z, matrix);
	returnValue = mostFrequentValue_NaiveAlgorithm(pom,26, 0);
	if (returnValue != 0)
	{
		return returnValue;
	}
	*/



	//create nearest moore
	//check neighbour
	//chance of change
	NearestMoore n1 = NearestMoore();
	pom = n1.GetNeighborTab(x, y, z, matrix);
	returnValue = mostFrequentValue_NaiveAlgorithm(pom, 6, 0);
	if (returnValue != 0)
	{
		return returnValue;
	}




	//create futher moore
	//check neighbour
	//chance of change


  

       

    



    //cout << mostFrequentValue_NaiveAlgorithm(pom)  << "  ";
    return 0;
}


Id* Neighbourhood::mostFrequentValue_NaiveAlgorithm(Id** tab, int n, int minFreq)
{
    int i,j;
    int counter = 0;
    int maxValue = 0;
    Id* mostFrequent = 0;
    Id* pom = 0;


    for(i = 0 ; i < n ; i++)
    {
        pom = tab[i];
        for (j = 0 ; j < n ; j++)
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

	delete[] tab;

    if(mostFrequent == 0 && maxValue < minFreq)
    {
        //cout << mostFrequent << "AAA" << endl;
        return 0;

    }


    return mostFrequent;
}



Neighbourhood::~Neighbourhood()
{
	cout << "kasuje" << endl;
}

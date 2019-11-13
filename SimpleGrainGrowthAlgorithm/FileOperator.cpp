#include "FileOperator.h"
#include<iostream>
#include<fstream>

using namespace std;


FileOperator::FileOperator()
{

}

void FileOperator::saveToFile(Grain*** matrix, int x, int y, int z)
{
	ofstream file("color.txt");
	int i,j,k;
	for (i = 1; i + 1 < x; i++)
	{
		for (j = 1; j + 1 < y; j++)
		{
			for (k = 1;k + 1 < z; k++)
			{
				file << matrix[i][j][k].id->color_r << " ";
				file << matrix[i][j][k].id->color_g << " ";
				file << matrix[i][j][k].id->color_b << " ";
				file << matrix[i][j][k].id->alpha <<endl;

			}
		}
	}


	/*
	for (i = 0; i < n; i++)
	{
		file << vertices[i] << " ";
		if ((i + 1) % 4 == 0)
		{
			file << endl;
		}
	}
	file.close();
	*/
}

FileOperator::~FileOperator()
{

}

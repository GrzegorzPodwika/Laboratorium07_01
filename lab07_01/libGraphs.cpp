#include "libTables.h"
#include "libExceptions.h"
#include "libFiles.h"
#include "libGraphs.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void loadNumberOfVertexes(fstream& inFile, int& wierzcholki, int& krawedzie)
{
	int tmp{}, tmp2{};
	inFile >> krawedzie;

	for (int i = 0; i < krawedzie; i++)
	{
		inFile >> tmp >> tmp2;
		if (tmp > wierzcholki)
			wierzcholki = tmp;
		if (tmp2 > wierzcholki)
			wierzcholki = tmp2;
	}

	inFile.seekg(0);
}

void fillIncidenceMatrix(fstream& inFile, int** tabI, int wierzcholki, int krawedzie)
{
	int firstW{}, secW;
	inFile >> krawedzie;

	fillTable2DWithNulls(tabI, wierzcholki + 1, krawedzie + 1);

	for (int i = 1; i <= krawedzie; i++)
	{
		try
		{
			inFile >> firstW >> secW;

			if (firstW <= 0 || secW <= 0)
				throw EXCEPTION_CODE::notNaturalNumber;

			tabI[firstW][i]++;
			tabI[secW][i]--;
		}
		catch (EXCEPTION_CODE error)
		{
			seeExceptions(error);
			getchar();
			getchar();
			exit(0);
		}
	}
}

void fillAdjacencyMatrix(int** tabI, int** tabS, int wierzcholki, int krawedzie)
{
	fillTable2DWithNulls(tabS, wierzcholki + 1, wierzcholki + 1);

	for (int i = 1; i <= wierzcholki; i++)
	{
		for (int j = 1; j <= krawedzie; j++)
		{
			if (tabI[i][j] == 1) {
				for (int k = 1; k <= wierzcholki; k++)
				{
					if (tabI[k][j] == -1) {
						tabS[i][k] = 1;
						tabS[k][i] = 1;
					}
				}
			}
		}
	}
}

void fillIncidenceMatrix(fstream& inFile, vector<vector<int>>& vec, int wierzcholki, int krawedzie)
{
	int firstW{}, secW;
	inFile >> krawedzie;

	for (int i = 1; i <= krawedzie; i++)
	{
		try
		{
			inFile >> firstW >> secW;

			if (firstW <= 0 || secW <= 0)
				throw EXCEPTION_CODE::notNaturalNumber;

			vec[firstW][i]++;
			vec[secW][i]--;
		}
		catch (EXCEPTION_CODE error)
		{
			seeExceptions(error);
			getchar();
			getchar();
			exit(0);
		}
	}
}

void fillAdjacencyMatrix(vector<vector<int>>& vecIncydencji, vector<vector<int>>& vecSasiedztwa, int wierzcholki, int krawedzie)
{
	for (int i = 1; i <= wierzcholki; i++)
	{
		for (int j = 1; j <= krawedzie; j++)
		{
			if (vecIncydencji[i][j] == 1) {
				for (int k = 1; k <= wierzcholki; k++)
				{
					if (vecIncydencji[k][j] == -1) {
						vecSasiedztwa[i][k] = 1;
						vecSasiedztwa[k][i] = 1;
					}
				}
			}
		}
	}
}


void showVector2D(vector<vector<int>> vec, int rIterator, int cIterator)
{
	cout << "\t";
	for (int i = cIterator; i < vec[0].size(); i++)
	{
		cout << i << "\t";
	}
	cout << endl << endl;

	for (int i = rIterator; i < vec.size(); i++)
	{
		cout << i << "\t";
		for (int j = cIterator; j < vec[i].size(); j++)
		{
			cout << vec[i][j] << "\t";
		}
		cout << endl;
	}
}
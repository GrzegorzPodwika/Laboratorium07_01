#include "libGraphs.h"
#include "libFiles.h"
#include "libTables.h"
#include <iostream>
using namespace std;


int main() {

	int numberOfVertexes{}, numberOfEdges{};		
	fstream inFile = createInputFile();

	loadNumberOfVertexes(inFile, numberOfVertexes, numberOfEdges);

	int choise{};
	cout << "********MENU*************\n"
		"1. Macierz incydencji i sasiedztwa za pomoca tablicy dynamicznej dwuwymiarowej\n"
		"2. Vector vectorow\n"
		"Inne. Koniec programu\n"
		"Twoj wybor  ";
	cin >> choise;

	switch (choise)
	{
	case 1:
	{
		int** incidenceMatrix = createTable2D(numberOfVertexes + 1, numberOfEdges + 1);
		fillIncidenceMatrix(inFile, incidenceMatrix, numberOfVertexes, numberOfEdges);
		showTable2D(incidenceMatrix, numberOfVertexes + 1, numberOfEdges + 1, 1, 1);

		cout << endl << endl;
		int** adjacencyMatrix = createTable2D(numberOfVertexes + 1, numberOfVertexes + 1);
		fillAdjacencyMatrix(incidenceMatrix, adjacencyMatrix, numberOfVertexes, numberOfEdges);
		showTable2D(adjacencyMatrix, numberOfVertexes + 1, numberOfVertexes + 1, 1, 1);

		delete[] incidenceMatrix;
		delete[] adjacencyMatrix;
	}
		break;
	
	case 2:
	{
		const unsigned int numbOfRows = numberOfVertexes + 1;
		const unsigned int numbOfColumns = numberOfEdges + 1;

		vector <vector <int> > vecIncydencji{
		(numbOfRows),
		vector <int>(numbOfColumns) };

		fillIncidenceMatrix(inFile, vecIncydencji, numberOfVertexes, numberOfEdges);
		showVector2D(vecIncydencji, 1, 1);
		cout << endl << endl;

		vector < vector <int> > vecSasiedztwa{
			numbOfRows,
			vector <int>(numbOfRows)
		};

		fillAdjacencyMatrix(vecIncydencji, vecSasiedztwa, numberOfVertexes, numberOfEdges);
		showVector2D(vecSasiedztwa, 1, 1);
	}
		break;
	default:
		break;
	}

	inFile.close();
	getchar();
	getchar();
	return 0;

}







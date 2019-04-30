#ifndef LIBGRAPHS_H
#define LIBGRAPHS_H
#include <fstream>
#include <vector>

/*
Funkcja pomocnicza poszukujaca najwiekszej wartosci wierzcholka w pliku

@param inFile plik, w ktorym znajduja sie definicje krawedzi grafy nieskierowanego
@param numberOfVertexes maksymalna liczba wierzcholkow do uzupelnienia, poprzez referencje
@param numberOfEdges krawedzie do wczytania z pliku, poprzez referencje
*/
void loadNumberOfVertexes(std::fstream& inFile, int& numberOfVertexes, int& numberOfEdges);

/*
Funkcja wypelniajaca tablice dwuwymiarowa wartosciami z pliku, czyli tworzaca macierz incydencji

@param inFile plik, w ktorym znajduja sie definicje krawedzi grafy skierowanego
@param tabI tablica dwuwymiarowa incydencji do wypelnienia
@param numberOfVertexes liczba wierzcholkow
@param numberOfEdges liczba krawedzii
*/
void fillIncidenceMatrix(std::fstream& inFile, int** tabI, int numberOfVertexes, int numberOfEdges);

/*
Funkcja wypelniajaca tablice dwuwymiarowa przy pomocy macierzy incydencji, tworzaca macierz sasiedztwa

@param tabI tablica dwuwymiarowa incydencji
@param tabS tablica dwuwymiarowa sasiedztwa do wypelnienia
@param numberOfVertexes liczba wierzcholkow
@param numberOfEdges liczba krawedzii
*/
void fillAdjacencyMatrix(int** tabI, int** tabS, int numberOfVertexes, int numberOfEdges);

/*
Funkcja wypelniajaca vector dwuwymiarowy wartosciami z pliku, czyli tworzaca vector2D incydencji

@param inFile plik, w ktorym znajduja sie definicje krawedzi grafy skierowanego
@param incidenceVec vector2D incydencji do wypelnienia
@param numberOfVertexes liczba wierzcholkow
@param numberOfEdges liczba krawedzii
*/
void fillIncidenceMatrix(std::fstream& inFile, std::vector< std::vector <int> > &incidenceVec, int numberOfVertexes, int numberOfEdges);

/*
Funkcja wypelniajaca vector dwuwymiarowy przy pomocy macierzy incydencji, tworzaca vector2D sasiedztwa

@param incidenceVec vector2D incydencji
@param adjacencyVec vector2D sasiedztwa do wypelnienia
@param numberOfVertexes liczba wierzcholkow
@param numberOfEdges liczba krawedzii
*/
void fillAdjacencyMatrix(std::vector < std::vector <int> >& incidenceVec, std::vector < std::vector <int> > &adjacencyVec, int numberOfVertexes, int numberOfEdges);

/*
Funkcja pokazujaca vector2D na ekran

param vec vector2D do pokazania na ekran
@param rIterator iterator pomocniczy, od jakiego wiersza vectora chcemy pokazywac zawartosc, domyslnie 0
@param cIterator iterator pomocniczy, od jakiej kolumny vectora chcemy pokazywac zawartosc, domyslnie 0
*/
void showVector2D(std::vector< std::vector <int> > vec, int rIterator = 0, int cIterator = 0);


#endif // !LIBGRAPHS_H


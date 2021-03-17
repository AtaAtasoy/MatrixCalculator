#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
//Functions
void printMatrix(const vector<vector<double> >matrix, int numberOfRows, int numberOfColumns);
void takeInput(vector<vector<double> > &matrix, int a_numberOfRows, int a_numberOfColumns);
void addMatrices(vector<vector<double> >&a, vector<vector<double> > &b, int numberOfRows, int numberOfColumns);
void substractMatrices(vector<vector<double> > &a, vector<vector<double> >&b, int numberOfRows, int numberOfColumns);
void multiplyMatrices( vector<vector<double> >a, vector<vector<double> >b, int a_numberOfRows, int a_numberOfColumns,
    int b_numberOfRows, int b_numberOfColumns);
void displayMenu(vector<vector<double> > &matrixA, int a_numberOfRows, int a_nubmerOfColumns);
void processChoice(string choice, vector<vector<double> > &matrixA, int a_numberOfRows, int a_nubmerOfColumns);
void getRowEchelonForm(vector<vector<double> > &matrix, int numberOfRows, int numberOfColumns);
double findDeterminant(vector<vector<double> > &matrixA, int numberOfRows);
void getCofactor(vector<vector <double> > matrix, vector<vector <double> > &temp, int p, int q, int numberOfRows);
void displayTranspose(vector <vector <double> > matrix);
void findAdjointMatrix(vector <vector <double> > matrix);
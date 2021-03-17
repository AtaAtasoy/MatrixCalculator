#include "matrix.h"
int main(){
    int a_numberOfRows;
    int a_numberOfColumns;
    cout << "Enter the number of rows for the 1st matrix ";
    cin >> a_numberOfRows;
    cout << "\nEnter the number of columns for the 1st matrix ";
    cin >> a_numberOfColumns;
    vector<vector<double> > matrixA(a_numberOfRows, vector<double>(a_numberOfColumns, 0.0)); 
    takeInput(matrixA, a_numberOfRows, a_numberOfColumns);
    displayMenu(matrixA, a_numberOfRows, a_numberOfColumns);
    return 0;
}
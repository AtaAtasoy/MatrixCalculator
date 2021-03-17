#include "matrix.h"

void displayMenu(vector<vector<double> > &matrixA, int a_numberOfRows, int a_numberOfColumns){
    string choice;
    cout << "Congrats you just created " << a_numberOfRows << "x" 
        << a_numberOfColumns << " matrix\n";
    do{
        cout << "To perform matrix addition enter: \"A\"\nTo perform matrix subtraction enter: \"S\"\n";
        cout << "To perform matrix multiplication enter: \"M\"\n";
        cout << "To get the row echelon of a matrix enter: \"R\"\n";
        cout << "To print matrix #1 enter \"P\"\n";
        cout << "To find the determinant enter \"D\"\n";
        cout << "To find the transpose of the matrix, enter \"T\"\n";
        cout << "To exit enter: 'E'\n";
        cin >> choice;
        processChoice(choice, matrixA, a_numberOfRows, a_numberOfColumns);
    } while (choice != "E" ); 
}

void processChoice(string choice, vector<vector<double> > &matrixA, int a_numberOfRows, int a_numberOfColumns){
    int b_numberOfRows = 0;
    int b_numberOfColumns = 0;
    if( choice == "A" || choice == "B" || choice == "M") {
        //Do this if needed.
        cout << "Enter the number of rows for the 2nd matrix : ";
        cin >> b_numberOfRows;
        cout << "\nEnter the number of columns for the 2nd matrix ";
        cin >> b_numberOfColumns;
    }

    vector<vector<double> > matrixB(b_numberOfRows, vector<double> (b_numberOfColumns, 0));
    takeInput(matrixB, b_numberOfRows, b_numberOfColumns);
    if(choice == "P"){
        printMatrix(matrixA, a_numberOfRows, a_numberOfColumns);
    }
    if(choice == "A"){
        if(a_numberOfRows != b_numberOfRows || a_numberOfRows != b_numberOfColumns){
            cout << "You cannot perform matrix addition on matrices of different sizes\n";
        }
        addMatrices(matrixA, matrixB, a_numberOfRows, a_numberOfColumns);
    }        
    if(choice == "S"){
        if(a_numberOfRows != b_numberOfRows || a_numberOfRows != b_numberOfColumns){
            cout << "You cannot perform matrix subtraction on matrices of different sizes\n";
        }
        substractMatrices(matrixA, matrixB, a_numberOfRows, b_numberOfColumns);
    } 
    if(choice == "M"){
         if(a_numberOfColumns != b_numberOfRows){
            cout << "You cannot perform matrix multiplication\n";
        }
        else{
            multiplyMatrices(matrixA, matrixB, a_numberOfRows, a_numberOfColumns,
                    b_numberOfRows, b_numberOfColumns);
        }
    }
    if(choice == "D"){
        if(a_numberOfRows != a_numberOfColumns){
            cout << "Determinant is only defined for square matrices.\n";
        } 
        else{
            double result = findDeterminant(matrixA, a_numberOfRows);
            cout << "Determinant of the matrix is  : " << result << endl;
        }
    }
    if(choice == "T"){
        displayTranspose(matrixA);
    }        
}

void takeInput(vector<vector<double> > &matrix, int numberOfRows, int numberOfColumns){
    for(int i = 0; i < numberOfRows; i++){
        for(int j = 0; j < numberOfColumns; j++){
            cout << "The " << i+1 << ". row and " << j+1 << ". column = ";
            cin>> matrix[i][j];
        }
    }
}

void printMatrix(const vector<vector<double> > matrix, int numberOfRows, int numberOfColumns){
    for(int i = 0; i < numberOfRows; i++){
        for(int j = 0; j < numberOfColumns; j++){
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void addMatrices(vector<vector<double> > &matrixA, vector<vector<double> > &matrixB, int numberOfRows, int numberOfColumns){
    for(int i = 0; i < numberOfRows; i++){
        for(int j = 0; j < numberOfColumns; j++){
            matrixA[i][j] += matrixB[i][j];
        }
    }
    cout << "Addition complete\n";
}
 
void substractMatrices(vector<vector<double> > &matrixA, vector<vector<double> > &matrixB, int numberOfRows, int numberOfColumns){
    for(int i = 0; i < numberOfRows; i++){
        for(int j = 0; j < numberOfColumns; j++){
            matrixA[i][j] -= matrixB[i][j];
        }
    }
    cout << "Subtraction complete\n";
}

void multiplyMatrices(vector<vector<double> > matrixA, vector<vector<double> > matrixB, int a_numberOfRows, int a_numberOfColumns,int b_numberOfRows, int b_numberOfColumns){
    //Create the resulting array
    vector<vector<double> > result(a_numberOfColumns, vector<double>(b_numberOfRows, 0)); 
    int result_numberOfColumns = a_numberOfRows;
    int result_numberOfRows = b_numberOfColumns;

    //Multiplying matrices
    for(int i = 0; i < a_numberOfRows; i++){
        for(int j = 0; j < b_numberOfColumns; j++){
            for(int k = 0; k < a_numberOfColumns; k++){
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
    printMatrix(result, result_numberOfRows, result_numberOfColumns);
}  

void getRowEchelonForm(vector<vector<double> > &matrix, int numberOfRows, int numberOfColumns){
    
}

double findDeterminant(vector<vector<double> > &matrix, int numberOfRows){
   double determinant = 0;
   if (numberOfRows == 1){
       return matrix[0][0];
   }
    // temporary vector to use while calculating the cofactor 
    vector<vector<double> > temp(numberOfRows, vector<double> (numberOfRows, 0));
    int sign = 1;

    for(int i = 0; i < numberOfRows; i++){
        //Getting the cofactors of each row
        getCofactor(matrix, temp, 0, i, numberOfRows);
        //Calculating the determinant by adding the cofactors of the matrix
        determinant += sign * matrix[0][i] * findDeterminant(temp, numberOfRows-1);
        sign = -sign;
    }
    return determinant;
}

// the cofactor of the matrix's pth rows qth elements corresponds to temp[i][j]
void getCofactor(vector<vector <double> > matrix, vector<vector <double> > &temp, int p, int q, int numberOfRows){
    int i = 0;
    int j = 0;
    for(int row = 0; row < numberOfRows; row++){
        for(int col = 0; col < numberOfRows; col++){
            if(row != p && col != q){
                temp[i][j++] = matrix[row][col];

                // row is filled, move to the next row and reset the column index
                if(j == numberOfRows - 1){
                    j = 0;
                    i++;
                }
            }
        }
    }
}

void displayTranspose(vector<vector <double> > matrix){
    for(int row = 0; row < matrix.size(); row++){
        for(int i = 0; i < matrix.size(); i++){
            cout << matrix[i][row] << " ";
        }
        cout << endl;
    }
}
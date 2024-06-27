#include<iostream.h>
#include<conio.h>

void inputElement(int **matrix, int row, int col, int& evenSum, int& oddSum);
void printMatrix(int **matrix, int row, int col);
void sumCol(int **matrix, int row, int col);
void rowProd(int **matrix, int row, int col);
void sumDiag(int **matrix, int row, int col);
void aveDiag(int **matrix, int row, int col);
void highlowNum(int **matrix, int row, int col);
void eoNum(int **matrix, int row, int col);

int main()
{
    clrscr();
    int row, col, evenSum = 0, oddSum = 0;
    cout << "Enter Row: ";
    cin >> row;
    cout << "Enter Column: ";
    cin >> col;
    cout << "\nEnter " << row * col << " Elements of Matrix: " << endl;

    int **matrix = new int *[row];
    for (int a = 0; a < row; a++) {
        matrix[a] = new int[col];
    }

    inputElement(matrix, row, col, evenSum, oddSum);

    clrscr();
    cout << endl;
    printMatrix(matrix, row, col);

    cout << endl;
    sumCol(matrix, row, col);

    cout << endl;
    rowProd(matrix, row, col);

    cout << endl;
    sumDiag(matrix, row, col);

    cout << endl;
    aveDiag(matrix, row, col);

    cout << endl;
    highlowNum(matrix, row, col);

    cout << endl;
    cout << "Sum of Even Numbers in the Matrix: " << evenSum << endl;
    cout << "Sum of Odd Numbers in the Matrix: " << oddSum << endl;

    cout << endl;
    eoNum(matrix, row, col);

    getch();
    return 0;
}

void inputElement(int **matrix, int row, int col, int& evenSum, int& oddSum)
{
    for (int b = 0; b < row; b++) {
        for (int c = 0; c < col; c++) {
            cout << "Input Elements [" << b << "][" << c << "] of Matrix: ";
            cin >> matrix[b][c];
            if (matrix[b][c] % 2 == 0) {
                evenSum += matrix[b][c];
            } else {
                oddSum += matrix[b][c];
            }
        }
    }
}

void printMatrix(int **matrix, int row, int col)
{
    cout << "The Matrix is: " << endl;
    for (int d = 0; d < row; d++) {
        for (int e = 0; e < col; e++) {
            cout << matrix[d][e] << "  ";
        }
        cout << endl;
    }
}

void sumCol(int **matrix, int row, int col)
{
    for (int f = 0; f < col; f++) {
        int sum = 0;
        for (int g = 0; g < row; g++) {
            sum += matrix[g][f];
        }
        cout << "The Sum of Column " << f << ": " << sum << endl;
    }
}

void rowProd(int **matrix, int row, int col)
{
    for (int h = 0; h < row; h++) {
        double prod = 1;
        for (int i = 0; i < col; i++) {
            prod *= matrix[h][i];
        }
        cout << "The Product of Row " << h << ": " << prod << endl;
    }
}

void sumDiag(int **matrix, int row, int col)
{
    int sum = 0;
    cout << "Sum of First Diagonal: ";
    for (int j = 0; j < row && j < col; j++) {
        sum += matrix[j][j];
    }
    cout << sum << endl;

    sum = 0;
    cout << "Sum of Second Diagonal: ";
    for ( j = 0; j < row && j < col; j++) {
        sum += matrix[j][col - 1 - j];
    }
    cout << sum << endl;
}

void aveDiag(int **matrix, int row, int col)
{
    int avg = 0;
    cout << "Average of First Diagonal: ";
    for (int k = 0; k < row && k < col; k++) {
        avg += matrix[k][k];
    }
    cout << (double)avg / col << endl;

    avg = 0;
    cout << "Average of Second Diagonal: ";
    for (k = 0; k < row && k < col; k++) {
        avg += matrix[k][col - 1 - k];
    }
    cout << (double)avg / col << endl;
}

void highlowNum(int **matrix, int row, int col)
{
    int highnum = matrix[0][0], lownum = matrix[0][0], arraysum = 0;
    for (int l = 0; l < row; l++) {
        for (int m = 0; m < col; m++) {
            if (matrix[l][m] > highnum)
                highnum = matrix[l][m];
            if (matrix[l][m] < lownum)
                lownum = matrix[l][m];
            arraysum += matrix[l][m];
        }
    }
    cout << "Highest Number in the Matrix: " << highnum << endl;
    cout << "Lowest Number in the Matrix: " << lownum << endl;
    cout << "Sum of all Numbers in the Matrix: " << arraysum << endl;
}

void eoNum(int **matrix, int row, int col)
{
    cout << "Even Numbers: ";
    for (int d = 0; d < row; d++) {
        for (int e = 0; e < col; e++) {
            if (matrix[d][e] % 2 == 0) {
                cout << matrix[d][e] << "  ";
            }
        }
    }
    cout << endl;

    cout << "Odd Numbers: ";
    for (int x = 0; x < row; x++) {
        for (int y = 0; y < col; y++) {
            if (matrix[x][y] % 2 != 0) {
                cout << matrix[x][y] << "  ";
            }
        }
    }
    cout << endl;
}

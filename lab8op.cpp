#include<iostream>
#include<iomanip>
using namespace std;

const int n = 7;

int* column_generate();
int** matrix_generate(int*);
void matrix_output(int**);
void column_swap(int*);
void array_output(int*);

int main()
{
    int **matrix,
        *column;
    
    column = column_generate();
    array_output(column);
    matrix = matrix_generate(column);
    matrix_output(matrix);
    return 0;
}

int* column_generate()
{
    int *column = new int [n];
    for (int i=0; i<n; i++)
    {
        column[i] = i+1;
    }
    return column;
}

void column_swap(int* column)
{
    int temp = column[0];
    for (int i=0; i<n-1; i++)
        column[i] = column[i+1];
    column[n-1] = temp;
}

int** matrix_generate(int* column)
{
    int **matrix = new int *[n];
    for (int i=0; i<n; i++)
        matrix[i] = new int [n];
        
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            matrix[i][j] = column[j];
        column_swap(column);
    }
    return matrix;
}

void matrix_output(int** matrix)
{
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << setw(4) << matrix[i][j];
        cout << '\n';
    }
}

void array_output(int *array)
{
    for (int i=0; i<n; i++)
        cout<< setw(4) << array[i];
    cout << "\n\n";
}

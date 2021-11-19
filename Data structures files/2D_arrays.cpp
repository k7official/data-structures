#include<iostream>
using namespace std;

int main()
{
    int A[3][4] = {{1, 2, 3, 4}, {2, 4, 6, 8}, {1, 3, 5, 7}};
    for (int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    
    int *B[3]; // array of pointers in stack
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];
    int k = 1;
    for (int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            B[i][j] = j*k*10;
        }
    }
    for (int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    int **C;//store the address of the second pointer
    C = new int* [3]; //arrays of pointers in heap
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];


    return 0;
}
//
//  main.cpp
//  Matrix Multiplication
//
//  Created by Muhle Musa Khumalo on 2022/4/14.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 2;
    
    int A[2][2] = {{1, 3},
                    {5, 2}};
    int B[2][2] = {{2, 3},
                    {6, 1}};
    int C[2][2] = {{0, 0},
                    {0, 0}};
    
    int i,j,k;
    
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            for(k=0;k<n;k++)
                C[i][j] = C[i][j]+A[i][k]*B[k][j];
        }
    }
    for (i=0;i<n;i++){
        for(j=0;j<n;j++)
            cout << C[i][j]<<" ";
        cout << endl;
    }
    return 0;
}

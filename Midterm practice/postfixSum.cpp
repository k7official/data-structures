#include<iostream>
using namespace std;

int main(){
    int size = 5;
    int A[] = {1, 2, 3, 4, 5};
    int B[size];
    B[size-1] = A[size-1];
    //post fix sum of A in B
    for (int i=size-2; i>=0; i--){
        B[i] = A[i] + B[i+1];
    }
    //postfix sum of A in A itself
    for (int i=size-2; i>=0; i--){
        A[i] = A[i] + A[i+1];
    }

    for(int i=0; i<5; i++){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
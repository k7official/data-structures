#include<iostream>
using namespace std;

void prefixSum(int A[], int B[], int n)
{
    B[0] = A[0]; 
    for(int i=1; i<n; i++)
    {
        B[i] = B[i-1] + A[i];
    }
}
void prefixSum(int A[], int n)
{
    for(int i=1; i<n; i++)
    {
        A[i] = A[i] + A[i-1];
    }
}

int main()
{
    int n=5;
    int A[] ={1,2,3,4,5};
    int B[n];
    prefixSum(A, B, n);
    prefixSum(A, n);
    for(int i=0; i<n; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}
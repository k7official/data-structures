#include<iostream>
using namespace std;

int *PostfixPrefixSum(int A[], int B[], int m, int n)
{
    int biggest = (m > n ? m : n);
    int *C = new int[biggest];
    int i, j, k;
    i = k = 0;
    j = n-1;
    
    while(i<m && j >= 0)
    {
        C[k++] = A[i++] + B[j--];
    }
    for(;i<m;i++)
        C[k++] = A[i];
    for(;j>=0;j--)
        C[k++] = B[j];
        
    return C;
}
int main()
{
    int m = 5;
    int n =3;
    int B[] = {1,2,3,4,5};
    int A[]  = {6,7,8};
    int *C = PostfixPrefixSum(A, B, n, m);
    int c_size = (m > n ? m : n);
    for(int i=0;i<c_size;i++)
        cout << C[i] << " ";
    cout << endl;

    return 0;
}


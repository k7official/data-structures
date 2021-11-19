#include<iostream>
using namespace std;

int r_fact(int n){
    if(n == 0)
        return 1;
    return r_fact(n-1)*n;
}
int nCr(int n, int r){
    int num = r_fact(n);
    int denom = r_fact(r) * r_fact(n-r);
    return num/denom;
}

int r_nCr(int n, int r){   //this method makes use of the Pascal triangle
    if(n==r || r==0)
        return 1;
    else
        return r_nCr(n-1, r-1) + r_nCr(n-1, r);//adding previous two terms
}

int main(){
    cout << r_nCr(5, 3);
    return 0;
}
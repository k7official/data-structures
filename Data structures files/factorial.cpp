#include<iostream>
using namespace std;

int r_fact(int n){
    if(n == 0)
        return 1;
    return r_fact(n-1)*n;
}
int fact(int n){
    int f = 1;
    for(int i=1; i<=n; i++){
        f = f*i;
    }
    return f;
}

int main(){
    cout << fact(3) << endl;
    return 0;
}
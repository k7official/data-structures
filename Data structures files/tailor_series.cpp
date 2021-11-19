#include <iostream>
#include<iomanip>
using namespace std;
double e(int x, int n);
double e_recursive(int x, int n);

int main(){
    int x_value = 1;
    int n_terms = 10;
    cout << fixed << setprecision(6);
    cout << e(x_value, n_terms) << endl;
    cout << e_recursive(x_value, n_terms) << endl;

    return 0;
}

double e(int x, int n){/*using loop(iterative)*/
    double sum = 1;
    for(; n > 0; n--){
        sum = 1 + sum*x/n;
    }
    return sum;
}
double e_recursive(int x, int n){/*recursive*/
    static double sum   ;
    if(n == 0){
        return sum;
    }
    else{
        sum = 1 + sum * x/n;
        return e_recursive(x, n - 1);
    }

}
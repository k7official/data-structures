#include<iostream>

using namespace std;

void calculate(char &operator_, int a, int b){
    if(operator_ == '+')
        cout <<  a + b << endl;
    else if(operator_ == '-')
        cout << a - b << endl;
    else if(operator_ == '*')
        cout << a * b << endl;
    else if(operator_ == '/'){
        char* exception__ = &operator_;
        if(b == 0)
            throw exception__;
        cout << a / b << endl;
    }
    else{
        throw operator_;
    }
}

int main(){

    char operator_;
    int a, b;
    while(true){
        cin >> a >> operator_ >> b;
        try{
            calculate(operator_, a, b);
        }
        catch(char &ex){
            cout << ex << " is an unknown operator" << endl;
        }
        catch(char* ex){
            cout << *ex << " : You cannot divide by zero" << endl;
        }
    }

    return 0;
}


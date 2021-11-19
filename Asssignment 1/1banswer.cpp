// DSHomework_1b.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <vector>
using namespace std;
void TOH(int n, vector<int> *A, vector<int> *B, vector<int> *C)
{
    if (n > 0)
    {
        static vector<int> *addressA = A;
        static vector<int> *addressB = B;
        static vector<int> *addressC = C;
        TOH(n - 1, A, C, B);
        //check which address A & C are pointing to
        char a{}, b{};  
        if (A == addressA) {
            addressA->pop_back();
            a = 'A';
        }
        if (A == addressB) {
            addressB->pop_back();
            a = 'B';
        }
        if (A == addressC) {
            addressC->pop_back();
            a = 'C';
        }
        if (C == addressA) {
            addressA->push_back(n);
            b = 'A';
        }
        if (C == addressB) {
            addressB->push_back(n);
            b = 'B';
        }
        if (C == addressC) {
            addressC->push_back(n);
            b = 'C';
        }
        cout << "Move "<<n << " from "<< a <<" to " <<b<<endl;
        cout << 'A';
        for (auto num : *addressA) {
            cout << num;
        }
        cout << endl;
        cout << 'B';
        for (auto num : *addressB) {
            cout << num;
        }
        cout << endl;
        cout << 'C';
        for (auto num : *addressC) {
            cout << num;
        }
        cout << endl;
        TOH(n - 1, B, A, C);
    }
}

int main()
{
    vector<int> A;
    vector<int> B;
    vector<int> C;
    int num{};
    cout << "Enter number of disks : ";
    cin >> num;
    for (int i = 0; i < num; i++) {
        A.push_back(num - i);
    }
    cout << 'A';
    for (int i = 0; i < num; i++) {
        cout << A.at(i);
    }
    cout<<endl;
    cout << 'B';
    cout << endl;
    cout << 'C';
    cout << endl;
    TOH(num, &A, &B, &C);
    return 0;
}






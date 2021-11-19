#include<iostream>
#include<vector>
using namespace std;
void initialize(int n, vector<int> &a);
void display_all(vector<int> a, vector<int> b, vector<int> c);

void TOH(int n, int A, int B, int C, vector<int> &a, vector<int> &b, vector<int> &c)
{
    if(n > 0)
    {   
        static vector<int> a_address = a;
        static vector<int> b_address = b;
        static vector<int> c_address = c;
        TOH(n-1, A, C, B, a, c, b);
        cout << "Move disk " << n << " from peg " <<  A << " to peg " <<  C << endl;
        if(a == a_address)
            a_address.pop_back();
        if(a == b_address)
            b_address.pop_back();
        if(a == c_address)
            c_address.pop_back();
        if(c == a_address)
            a_address.push_back(n);
        if(c == b_address)
            b_address.push_back(n);
        if(c == c_address)
            c_address.push_back(n);
        display_all(a_address, b_address, c_address);
        TOH(n-1, B, A, C, b, a, c);
    }   
}



void display_all(vector<int> a, vector<int> b, vector<int> c){
    int disk;
    cout << "A";
    if(a.size()!=0)
    for (int disk = 0; disk < a.size(); disk++)
        cout << a[disk];
    cout << endl;
    cout << "B" ;
    for (disk = 0; disk < b.size(); disk++)
        cout << b[disk];
    cout << endl;
    cout << "C";
    
    for (disk = 0; disk < a.size(); disk++)
        cout << c[disk];
    cout << endl;
}

int main()
{
    int n = 3;
    vector<int> a;
    vector<int> b;
    vector<int> c;
    for(int i = n; i > 0; i--)  
    {
        a.push_back(i);
    }
    cout << "A";
	for (int disk = 0; disk < a.size(); disk++)
        cout << a[disk];
    cout << endl;
    cout << 'B';
    cout << endl;
    cout << 'C';
    cout << endl;
    
    //display_all(a, n);
    TOH(3, 1, 2, 3, a, b, c);   
    return 0;   
}
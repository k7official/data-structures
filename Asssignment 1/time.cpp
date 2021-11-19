#include<iostream>
#include<ctime>
using namespace std;

clock_t start, stop;
int main()
{
    start = clock();// set start to current time in millisecond     
    //cout << start << endl;
    long counter;
    do{
        counter++; 
        for(int i=0; i<100; i++)
            cout << "Hello\n";
        stop = clock(); // set stop to current time
    }while(stop - start < 10);
    double elapsedTime = (stop - start);
    double timeToPrint = elapsedTime/counter;

    //double runTime = stop - start; 
    cout << timeToPrint << endl; 
}


#include <iostream>
#include <ctime>
using namespace std;

void magic (int n)
// create a magic square of size n, n is odd
{
  const int MaxSize = 51; // maximum square size
  int square[MaxSize][MaxSize], k, l;

  // check correctness of n
  if ((n > MaxSize) || (n < 1)) {cerr << "Error!..n out of range \n"; return;}
  else if (!(n%2)) {cerr << "Error!..n is even \n"; return;}

  // n is odd. Coxeter's rule can be used
  for (int i = 0; i < n; i++){ // initialize square to 0
     for (int j = 0; j < n; j++)
        square[i][j] = 0;
    square[0][(n-1)/2] = 1; // middle of first row
  }
  // i and j are current position
  int key = 2;
  int i = 0;
  int j = (n-1)/2;
  while (key <= n*n) {
  // move up and left
     if (i-1 < 0)  k = n-1; else k = i-1;
     if (j-1 < 0)  l = n-1; else l = j-1;
     if (square[k][l])  i = (i+1)%n;
     else { // square[k][l] is unoccupied
	i = k;
	j = l;
     }
     square[i][j] = key;
     key++;
  } // end of while

  // output the magic square
  cout << "magic square of size " << n << endl;
  for ( i = 0; i < n; i++) {
     for ( j = 0; j < n; j++)
        cout << square[i][j] << " ";
     cout << endl;
  }
  cout << endl;

}

void Timer(int size_)
{
    double run_time = 0;
    double total_time = 0;
    for(int i=5; i <= 50; i+=5){
        clock_t start, stop;
        start = clock();
        for(int k=0; k<i; k++){
            magic(size_);
        }
        stop = clock();
        auto total_time = (double)(stop - start) / CLOCKS_PER_SEC;
        run_time = total_time/double(i);
        cout << "Total runtime for " << i << ": " << total_time << endl;
        cout << "Average runtime for " << i << ": " << run_time << endl;
        cout << "Times are in seconds." << endl;
        cout << endl;

    }
}

int main()
{
    int sizes[] = {5, 7, 9, 11};
    for(int i=0; i<4; i++)
        Timer(sizes[i]);
}

#include<iostream>
#include<chrono>
#include<thread>
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

struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;
    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        float ms = duration.count() * 1000.0f;
        std::cout << "Timer took " << ms << "ms" << std::endl;
    }
};
int main() 
{
    
    using namespace std::literals::chrono_literals;

    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(1s);
    magic(3);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    std::cout << duration.count() << "s" << std::endl;

    std::cin.get();
}
#include<iostream>
using namespace std;

void allocArray(int ***p, int m, int n)
{
    *p = new int*[m];//allocating memory dynamically for array of pointers to the rows of the 2D array..**p will point to this allocated memory
    int size = m*n;
    int *new_array = new int[size];//allocate memory for 2D array so they are continuous
    int counter = 0;
    for(int i=0; i<m; i++)
    {   
      for(int j=0; j<n; j++)
      {
        (*p)[i] = &new_array[counter++];//offset the pointer until the column is complete
                                        //each pointer in *p will point to the end of each columns of the 2D array
      }
    }
    /*no need for two for loops, can do it as follows
    for(int i=0; i<m; i++){
      (*p)[i] = &new_array[i*n];
    }*/

    //how to free this memory?
    //delete []new_array;
    //delete []*p;
    //p = NULL;
}

int main()
{
  int **array, *a;
  int j, k;
  allocArray(&array, 5, 10);
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      array[j][k] = j * 10 + k;
  for(j = 0;j < 5;j ++)
    for(k = 0;k < 10;k ++)
      printf("%p ", &(array[j][k]));

//may free memory in main
  
}   
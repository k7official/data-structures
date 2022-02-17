#include <iostream>

using namespace std;

struct Array{
    int A[10];
    int length;
    int size;
};

void display(struct Array arr){
    for(int i=0; i<arr.length; i++){
        cout << arr.A[i] << " ";
    }
    cout << endl;
}
bool isSorted(struct Array arr){
    for (int i=0; i<arr.length-1; i++){
        if(arr.A[i] > arr.A[i+1])
            return false;
    }
    return true;
}

void sort(struct Array &arr){
    int i, j, temp;
    for(i=0; i<arr.length; i++){
        for(j=i+1; j<arr.length; j++){
            //If there is a smaller element found on right of the array then swap it.
            if(arr.A[j] < arr.A[i]){
                temp = arr.A[i];
                arr.A[i] = arr.A[j];
                arr.A[j] = temp;
            }
        }
    }
}

struct Array* setUnion(struct Array arr1, struct Array arr2){
    if(!isSorted(arr1)){
        sort(arr1);
    }
    if(!isSorted(arr2)){
        sort(arr2);
    }
    int i,j,k;
    i=j=k=0;

     struct Array *arr3= (struct Array *)malloc(sizeof(struct Array));

     while(i<arr1.length && j<arr2.length)
     {
        if(arr1.A[i]<arr2.A[j])
            arr3->A[k++]=arr1.A[i++];
        else if(arr2.A[j] < arr1.A[i])
            arr3->A[k++]=arr2.A[j++];
        else{
            arr3->A[k++] = arr1.A[i++];
            j++;
        }

     }
     //copying remaining elements
     for(;i<arr1.length;i++)
        arr3->A[k++]=arr1.A[i];
     for(;j<arr2.length;j++)
        arr3->A[k++]=arr2.A[j];

     arr3->length=k;
     arr3->size=10;
     return arr3;
}

struct Array* setIntersection(struct Array arr1, struct Array arr2){
    if(!isSorted(arr1)){
        sort(arr1);
    }
    if(!isSorted(arr2)){
        sort(arr2);
    }
    int i,j,k;
    i=j=k=0;

     struct Array *arr3= new struct Array;

     while(i<arr1.length && j<arr2.length)
     {
        if(arr1.A[i]<arr2.A[j])
            i++;
        else if(arr2.A[j] < arr1.A[i])
            j++;
        else if(arr1.A[i]==arr2.A[j])
        {
            arr3->A[k++] = arr1.A[i++];
            j++;
        }
     }
     arr3->length=k;
     arr3->size=10;
     return arr3;
}

struct Array* setDifference(struct Array arr1, struct Array arr2){
    if(!isSorted(arr1)){
        sort(arr1);
    }
    if(!isSorted(arr2)){
        sort(arr2);
    }
    int i,j,k;
    i=j=k=0;

     struct Array *arr3= (struct Array *)malloc(sizeof(struct Array));

     while(i<arr1.length && j<arr2.length)
     {
        if(arr1.A[i] < arr2.A[j])
            arr3->A[k++]=arr1.A[i++];
        else if(arr2.A[j] < arr1.A[i])
            j++;
        else{
            i++;
            j++;
        }

     }
     //copying remaining elements
     for(;i<arr1.length;i++)
        arr3->A[k++]=arr1.A[i];

     arr3->length=k;
     arr3->size=10;
     return arr3;
}

int main(){

    struct Array arr1 = {{1, 2, 5, 0, 4},5,10};
    struct Array arr2 = {{4, 9, 8, 11, 10},5,10};
    struct Array *arr3 = setUnion(arr2, arr1);
    display(*arr3);
    return 0;
}
/*
Write setUnion, setIntersection and setDifference
functions. All take two arrays of integers and
return the union, intersection and difference of
two set of integers respectively. Write main
program to test your functions.
*/

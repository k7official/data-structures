#include <iostream>
using namespace std;

struct Array{
    int A[10];
    int length;
    int size;
};

void display(struct Array arr)
{
    for(int i=0; i<arr.length; i++){
        cout << arr.A[i] << " ";
    }
    cout << endl;
}

void append(struct Array *arr, int x)//should be call by address since we want to change the array
{
    if(arr->length < arr->size)//check for free space
    {
        arr->A[arr->length++] = x;
    }
}

void insert(struct Array *arr, int index, int x)//by address because it is going to modify an array
{
    if(index >= 0 && index <= arr->length)
    {
        for(int i=arr->length; i > index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x = 0;
    if(index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (int i=index; i<arr->length-1; i++)//shifting the elements
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--; // we have removed  an element from the array
    }
    return x;
}    

int LinearSearch(struct Array &arr, int key)
{
    for(int i=0; i<arr.length; i++)
    {
        if(key == arr.A[i])
        {
            swap(arr.A[i], arr.A[0]);
            return i; 
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key)
{
    int left = 0;
    int right = arr.length-1;
    while(left <= right)
    {
        int middle = (left+right)/2;
        if(key == arr.A[middle])
            return middle;
        else if(key < arr.A[middle]){
            right = middle - 1;
        }       
        else{
            left = middle + 1; 
        }
    }
    return -1;

}

int get(struct Array arr,int index)
{
    if(index >= 0 && index < arr.length)//check if index is valid or not
        return arr.A[index];
    return -1;
}
void set(struct Array &arr, int index, int x)
{
    if(index >= 0 && index < arr.length)
    {
        arr.A[index] = x;
    }
}

int max(struct Array arr)
{
    int max =  arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
} 

int min(struct Array arr)
{
    int min =  arr.A[0];
    for(int i=1; i<arr.length; i++)
    {
        if(arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
} 
int sum(struct Array arr)
{
    int sum = 0;
    for(int i=0; i<arr.length; i++)
    {
        sum += arr.A[i];
    }
    return sum;
}
double average(struct Array arr)
{
    double average = double(sum(arr))/arr.length;
    return average;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b; 
    *b = temp;
}

void reverse(struct Array &arr)
{
    for(int i=0, j=arr.length-1; i<j; i++, j--){
        swap(&arr.A[i], &arr.A[j]);
    }
}

void rotate(struct Array &arr)
{
    int el = arr.A[0];
    int i;
    for(i=1; i<arr.length; i++){
        arr.A[i-1] = arr.A[i]; 
    }
    //cout << i << endl;
    arr.A[i-1] = el;
}

//check if an array is sorted or not
bool isSorted(struct Array arr)
{
    for (int i=0; i<arr.length-1; i++){
        if(arr.A[i] > arr.A[i+1])
            return false;
    }
    return true;
}
//inserting an element in a sorted array
void sorted_insert(struct Array &arr, int x)
{
    int i = arr.length -1;
    if(arr.length == arr.size)
        return;
    while (i >= 0 && x < arr.A[i])//as long as x is less than the element
    {
        arr.A[i+1] = arr.A[i];//shifting the element
        i--;
    }
    arr.A[i+1] = x;
    arr.length++;

}
void group_negative(struct Array &arr)
{
    int i = 0;//;look for positive 
    int j = arr.length-1;//look for negative
    while(i < j)
    {
        while(arr.A[i] < 0){i++;}
        while(arr.A[j] >= 0){j--;}
        if(i < j)
            swap(arr.A[i], arr.A[j]);
    }

}
struct Array* Merge(struct Array *arr1,struct Array *arr2)
{
 int i,j,k;
 i=j=k=0;

 struct Array *arr3=(struct Array *)malloc(sizeof(struct
Array));

 while(i<arr1->length && j<arr2->length)
 {
 if(arr1->A[i]<arr2->A[j])
 arr3->A[k++]=arr1->A[i++];
 else
 arr3->A[k++]=arr2->A[j++];
 }
 for(;i<arr1->length;i++)
 arr3->A[k++]=arr1->A[i];
 for(;j<arr2->length;j++)
 arr3->A[k++]=arr2->A[j];
 arr3->length=arr1->length+arr2->length;
 arr3->size=10;

 return arr3;
}
int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8}, 8, 10};
    ///append(&arr, 6);
    //insert(&arr, 0, 99);
    //cout << Delete(&arr, 0) << " deleted from array." << endl;
    //cout << BinarySearch(arr, 4) << endl;
    //set(arr, 4, 70);
    cout << get(arr, 4) << endl;
    cout << max(arr) << endl;
    cout << min(arr) << endl;
    cout << sum(arr) << endl;
    cout << average(arr) << endl;
    display(arr);
    sorted_insert(arr, 49);
    display(arr);
    //reverse(arr);
    //display(arr);
    //rotate(arr);
    //display(arr);
    cout << boolalpha
         << isSorted(arr)<< endl;

     //array with negative and positive numbers
    struct Array arr1={{2,9,21,28,35},10,5};
    struct Array arr2={{2,3,16,18,28},10,5};
    struct Array *arr3; 
    arr3=Merge(&arr1,&arr2);
    display(*arr3);

    return 0;
}
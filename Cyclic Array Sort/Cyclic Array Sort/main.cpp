//
//  main.cpp
//  Cyclic Array Sort
//
//  Created by Muhle Musa Khumalo on 2021/12/8.
//

#include <iostream>

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int arr[] = {3,4,6,2,1,5};
    int n = 6;
    int i = 0;
    while(i < n){
        if(arr[i] != i+1){
            int index = arr[1]-1;
            swap(arr[i], arr[index]);
        }
        else i++;
    }
    for(int i=0; i<6; i++){
        std::cout << arr[i] << " ";
    }
    return 0;
}

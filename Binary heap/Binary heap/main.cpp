//
//  main.cpp
//  Binary heap
//
//  Created by Muhle Musa Khumalo on 2022/1/7.
//

#include <iostream>

void Insert(int A[], int n){
    int i=n,temp;
    temp=A[i];
    
    while(i>1 && temp>A[i/2]){
        A[i]=A[i/2];//i should be moved to pararent
        i=i/2;
    }
    A[i]=temp;
}

int Delete(int A[], int n){
    int i, j, x,temp, val;
    val=A[1];
    x=A[n];
    A[1]=A[n];
    A[n]=val;//stores deleted element at the last place
    i=1;
    j=i*2;//left child of i
    
    while(j<n-1){//already reduced by 1 element
        if(A[j+1]>A[j])
            j=j+1;
        if(A[i]<A[j]){
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            i=j;
            j=2*j;//should move into left chid
        }
        else //properly adjusted
            break;
    }
    return val;
}

int main(int argc, const char * argv[]) {
    int H[] = {0,10,20,30,25,5,40,35};
    //40,25,35,10,5,20,30
    int i;
    for(i=2;i<=7;i++){
        Insert(H, i);
    }
    for(i=7;i>1;i--){
        Delete(H, i);
    }
    //std::cout<<"Deleted value is: " << Delete(H, 7)     << std::endl;
    //std::cout<<"Deleted value is: " << Delete(H, 6)     << std::endl;

    for(i=1;i<=7;i++){
        std::cout<<H[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}

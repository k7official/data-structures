//
//  main.cpp
//  Kruskal's Algorithm
//
//  Created by Muhle Musa Khumalo on 2022/1/2.
//

#include <iostream>
#define I INT_MAX

using namespace std;

int set[8]={-1,-1,-1,-1,-1,-1,-1,-1};

void my_union(int u, int v){
    if(set[u] < set[v]){
        set[u] += set[v];//set[u] is the parent in this case
        set[v] = u;
    }
    else{
        set[v] += set[u];//increase the number of vertices i am parent to
        set[u] = v;//have the value of my parent
    }
}
int find(int u){
    int x = u, v=0;
    while(set[x] > 0){
        x = set[x];
    }
    while(u!=x){//collapsing find...connection all vertices directly to parent
        v=set[u];
        set[u]=x;
        u=v;
    }
    return x;
}
int edges[3][9]={{1,1,2,2,3,4,4,5,5},
                {2,6,3,7,4,5,6,7},
                {25,5,12,10,8,16,14,20,18}};

int included[9]={0};
int t[2][6];//solution matrix

int main(int argc, const char * argv[]) {
    int i=0, j, k = 0, u = 0 , v = 0, min=I, n=7, e=9;
    while(i<n-1){
        min=I;
        for(j=0;j<e;j++){
            if(included[j]==0 && edges[2][j]<min){
                min=edges[2][j];
                u=edges[0][j];
                v=edges[1][j];
                k=j;//record it
            }
        }
        if(find(u) != find(v)){
            t[0][i] = u;
            t[1][i] = v;
            my_union(find(u), find(v));
            i++;
        }
        included[k]=1;
    }
    for(i=0;i<n-1;i++)
        cout<<"("<<t[0][i]<<","<<t[1][i] << ")"<<endl;
    return 0;
}

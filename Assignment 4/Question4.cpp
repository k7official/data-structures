#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 100;
struct node{
	int v,w;    //Record (next to the directed edge) vertex, edge weight
};

//Topological sequence, placed in the stack, popping the stack is reverse topological sorting
stack<int>toporder;
vector<node>G[maxn];   //adjacency list stored graph
int n,m,ve[maxn],vl[maxn],indegree[maxn];  //n is the number of vertices, m is the number of edges

bool topologicalsort(){
	queue<int>q;
	for(int i = 0;i <n;i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u = q.front();
		cout << u << " ";
		q.pop();
		toporder.push(u);    //Add u to the topological sequence
		for(int i = 0;i <G[u].size();i++){
			int v = G[u][i].v;
			indegree[v]--;
			if(indegree[v] == 0){
				q.push(v);
			}
			if(ve[u] + G[u][i].w >ve[v]){
				ve[v] = ve[u] + G[u][i].w;
			}
		}
	}
	//printf("%d ",toporder.size());
	if(toporder.size() == n) return true;
	else return false;
}

int criticalpath(){
	memset(ve,0,sizeof(ve));
	if(topologicalsort() == false){
		return -1;
	}
	cout << endl;;
	fill(vl,vl+n,ve[n-1]);    //vl array initialization, the initial value is the ve value of the sink
	while(!toporder.empty()){      //pop, reverse topological sort
		int u = toporder.top();
		toporder.pop();
		for(int i = 0;i <G[u].size();i++){
			int v = G[u][i].v;
			if(vl[v] - G[u][i].w<vl[u]){
				vl[u] = vl[v] - G[u][i].w;
			}
		}
	}
	//Traverse all the edges of the adjacency list and calculate the earliest start time e and latest start time l of the activity
	for(int u = 0;u <n;u++){
		for(int i = 0;i <G[u].size();i++){
			int v = G[u][i].v,w = G[u][i].w;
			int e = ve[u],l = vl[v] - w;
			if(e == l){
				cout << u << "->" << v << "\n";
			}
		}
	}
	return ve[n-1];    //Returns the critical path length
}

int main(){
	cin >> n >> m;
	int s,t,weight;
	for(int i = 0;i <m;i++){
        cin >> s >> t >> weight;
		node pt;   //Pre-store data with a temporary node
		pt.v = t;
		pt.w = weight;
		G[s].push_back(pt);   //Pay attention to the storage method of the adjacency list
	}
	for(int i = 0;i < n;i++){
		cin >> indegree[i]; //record in degree
	}
	//topologicalsort();
	cout << "The topological sort sequence is: \n";
	int ans = criticalpath();
	cout << ans;
}

//Test case 1

// 9 12 0 1 2 0 2 1 1 3 3 2 4 4 3 6 2 3 5 2 4 5 1 4 7 5 5 6 3 5 7 1 6 8 3 7 8 6 0 1 1 1 1 2 2 2 2

//Test case 2

//7 10 0 1 3 0 2 2 0 3 6 1 3 2 1 4 8 2 3 1 2 5 3 3 4 1 4 6 3 5 6 4 0 1 1 3 2 1 2

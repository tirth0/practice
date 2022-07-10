#include<bits/stdc++.h> 
using namespace std; 

bool DFSRec(vector<int> adj[], int s,bool visited[], bool recursionStack[]) 
{ 	
    visited[s]=true;
    recursionStack[s]=true;
    for(int u:adj[s]){
        if(visited[u]==false){
            if(DFSRec(adj,u,visited,recursionStack)==true)
                {return true;}}
        else if(recursionStack[u])
            {return true;}
    }
    recursionStack[s] = false;
    return false;
}

bool DFS(vector<int> adj[], int V){
    bool visited[V];
    bool recursionStack[V]; 
	for(int i=0;i<V; i++) {
		visited[i] = false;
        recursionStack[i] = false;    
    }
		
    for(int i=0;i<V;i++){
        if(visited[i]==false)
            if(DFSRec(adj,i,visited,recursionStack)==true)
                return true;
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() 
{ 
	int V=6;
	vector<int> adj[V];
	addEdge(adj,0,1); 
	addEdge(adj,1,2); 
	addEdge(adj,2,4); 
	addEdge(adj,4,5); 
	addEdge(adj,1,3);
	addEdge(adj,2,3);

	if(DFS(adj,V))
	    cout<<"Cycle found";
	else
	    cout<<"No cycle found";

	return 0; 
} 
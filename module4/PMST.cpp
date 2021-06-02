#include<iostream>
#include<vector>
#include<climits>
using namespace std;
#define V 6

int selectMinVertex(vector<int>& value, vector<bool>& setMST){
    //  Does an O(N) comparison to find Mimum cost vertex post relaxation
    int minimum = INT_MAX;
    int vertex;
    for (int i=0;i<V;i++){
        if (setMST[i]==false && value[i]<minimum){
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}

void findMST(int graph[V][V]){

    int parent[V];//Stores the Final MST
    vector<int> value(V,INT_MAX);//weight of each node will be infinity at first except source
    vector<bool> setMST(V,false);//has node been visited

    //Assuming starting point is 0
    parent[0] = -1;
    value[0] = 0;

    //Here we go
    for (int i=0;i<V-1;++i){
        //Select best Vertex using greedy taknik
        int U = selectMinVertex(value,setMST);
        setMST[U] = true;

        //Relax vertices adjacent to U
        for (int j=0;j<V;++j){
            /* 3 constraints to relax:-
			      1.Edge is present from U to j.
			      2.Vertex j is not included in MST
			      3.Edge weight is smaller than current edge weight
			*/
            if (graph[U][j]!=0 && setMST[j]==false && graph[U][j]<value[j]){
                value[j] = graph[U][j];
                parent[j] = U;
            }
        }
    }
//Print MST
	for(int i=1;i<V;++i)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  wt = "<<graph[parent[i]][i]<<"\n";
}

int main()
{
	int graph[V][V] = { {0, 4, 6, 0, 0, 0},
						{4, 0, 6, 3, 4, 0},
						{6, 6, 0, 1, 8, 0},
						{0, 3, 1, 0, 2, 3},
						{0, 4, 8, 2, 0, 7},
						{0, 0, 0, 3, 7, 0} };

	findMST(graph);	
	return 0;
}

//TIME COMPLEXITY: O(V^2)
/********************************
 * if trying to understand code start with main
 * keeping in mind just the input and output
 *  of each function and class in main 
*****************************/

#include <stdio.h>
#include <vector>
using namespace std;
#define xyto1d(i,j) (((i - 1) * M) + j - 1)		// map 2d location to position in 1d array

// object keeps track of elements that are connected to each other,
// with path compression (for more details on compression see find method)
class WeightedQuickUnion{
    public:
    //// method declarations

    //constructor
    WeightedQuickUnion(int n){
		N = n;                                          //initialising N
		tree.resize(n);          // allocating space to tree array
		size.resize(n,1);       // allocating space to size array
		for (int i = 0; i < n; i++){        // initializing both arrays
			tree[i] = i;
		}
	}

    // method to find tree of tree which contains node
	int find(int node){
		int i=node;
		while(tree[i] != i){      //loop iterating node by node to reach root
			i = tree[i];

			//compressing path to top from bottom, each find calls halves path.
			tree[i] = tree[tree[i]]; 		
		}
		return i;
	}

    //method to join(take union) of two nodes 
    void join(int p, int q){

		int rp = find(p);           //rp is root of node p
		int rq = find(q);           //rq is root of node q

		if (rp==rq) return; // if root is same do nothing

		//comparing size of both trees and attaching tree with lower size 
		// tree of bigger size
		if(size[rp]>=size[rq]) {
			tree[rq]=rp;
			size[rp] += size[rq];
		}
		else {
			tree[rp] = rq;
			size[rq] += size[rp];
		}

	}

    //checks if 2 nodes are connected by comparing root of their trees
    bool connected(int p, int q){

		return find(p) == find(q);
	}
    

    private:
    //// class variables
    
    int N;      // N stores count of total nodes
    vector<int> tree;   //tree array stores node just above index(i) in tree
                                // meaning if tree[2] = 1 then node '2' is branched to '1'
    vector<int> size;   //size array stores the tree size whose root is i(index)
};

struct query_holder{
	bool type1;
	int  x1, x2, y1, y2;
};

// construct union from bool array of cyberverse state for non disabled chips
void make_connections(vector<bool>& cyberverse, WeightedQuickUnion& cyberunion, int M, int N){
	for (int i = 1; i < N; i++){
		for (int j = 1; j < M; j++){
			if ( !cyberverse[xyto1d(i, j)] ) continue;		// skip non working chips

            if (cyberverse[xyto1d(i + 1, j)])	cyberunion.join(xyto1d(i,j), xyto1d(i + 1,j));
			if (cyberverse[xyto1d(i, j + 1)])	cyberunion.join(xyto1d(i,j), xyto1d(i,j + 1));
			
		}
	}

	for (int i = 1; i < N; i++){					// handling last column
		if ( !cyberverse[xyto1d(i, M)] ) continue;		// skip non working chips

		if (cyberverse[xyto1d(i + 1, M)])	cyberunion.join(xyto1d(i, M), xyto1d(i + 1, M));
	}

	for (int i = 1; i < M; i++){					// handling last row
		if ( !cyberverse[xyto1d(N, i)] ) continue;		// skip non working chips

		if (cyberverse[xyto1d(N, i + 1)])	cyberunion.join(xyto1d(N, i), xyto1d(N, i + 1));
	}

}

// disabling chips and making union of corresponding rectangle
void disableRect(vector<bool>& cyberverse,WeightedQuickUnion& cyberunion, query_holder& q, int M){
	int x1 = q.x1, x2 = q.x2, y1 = q.y1, y2 = q.y2;

	// disabling corresponding chips and making their union
	for(int j = y1; j < y2; j++ ){					
		cyberverse[xyto1d(x1,j)] = false;
		cyberunion.join(xyto1d(x1, j), xyto1d(x1, j + 1));
		cyberverse[xyto1d(x2,j)] = false;
		cyberunion.join(xyto1d(x2, j), xyto1d(x2, j + 1));
	}

	// disabling corresponding chips and making their union
	for (int k = x1; k < x2; k++){					
		cyberverse[xyto1d(k,y1)] = false;
		cyberunion.join(xyto1d(k, y1), xyto1d(k + 1, y1));
		cyberverse[xyto1d(k,y2)] = false;
		cyberunion.join(xyto1d(k, y2), xyto1d(k + 1, y2));
	}

	//disabling a chip left in above loops
	cyberverse[xyto1d(x2, y2)] = false;
}

// enabling and making union of corresponding rectangle with others
void enableRect(vector<bool>& cyberverse,WeightedQuickUnion& cyberunion, query_holder& q, int M, int N){
	int x1 = q.x1, x2 = q.x2, y1 = q.y1, y2 = q.y2;

	// enabling corresponding chips and making their union
	for(int j = y1; j <= y2; j++ ){					
		cyberverse[xyto1d(x1, j)] = true;
		cyberverse[xyto1d(x2, j)] = true;

		if (x1 < N) if (cyberverse[xyto1d(x1 + 1, j)])	cyberunion.join(xyto1d(x1, j), xyto1d(x1 + 1, j));
		if (x1 > 1)	if (cyberverse[xyto1d(x1 - 1, j)])	cyberunion.join(xyto1d(x1, j), xyto1d(x1 - 1, j));
		
		if (x2 > 1) if (cyberverse[xyto1d(x2 - 1, j)])	cyberunion.join(xyto1d(x2 - 1, j), xyto1d(x2, j));
		if (x2 < N)	if (cyberverse[xyto1d(x2 + 1, j)])	cyberunion.join(xyto1d(x2 + 1, j), xyto1d(x2, j));
	}

	// enabling corresponding chips and making their union
	for (int k = x1; k < x2; k++){					
		cyberverse[xyto1d(k, y1)] = true;
		cyberverse[xyto1d(k, y2)] = true;

		if (y1 < M) if (cyberverse[xyto1d(k, y1 + 1)])	cyberunion.join(xyto1d(k, y1), xyto1d(k, y1 + 1));
		if (y1 > 1)	if (cyberverse[xyto1d(k, y1 - 1)])	cyberunion.join(xyto1d(k, y1), xyto1d(k, y1 - 1));
		
		if (y2 > 1) if (cyberverse[xyto1d(k, y2 - 1)])	cyberunion.join(xyto1d(k, y2), xyto1d(k, y2 - 1));
		if (y2 < M)	if (cyberverse[xyto1d(k, y2 + 1)])	cyberunion.join(xyto1d(k, y2), xyto1d(k, y2 + 1));
	}
}

int main(){
	int Q, N, M, type2Q;
	int type,x1,x2,y1,y2;
	scanf("%d%d%d", &N, &M, &Q);
	type2Q = Q;			// will reduce afterwards

	// To keep track of chip's connected state
	vector<bool> cyberverse =  vector<bool>(M * N ,true);

	// to track queries
	vector<query_holder> queries =  vector<query_holder>(Q);

	WeightedQuickUnion cyberunion = WeightedQuickUnion(M * N); 	// union to track connectivity

	for (int i = 0; i < Q; i++){
		scanf("%d%d%d%d%d", &type, &x1, &y1, &x2, &y2);

		queries[i].type1 = (type == 1);
		queries[i].x1 = x1;
		queries[i].x2 = x2;
		queries[i].y1 = y1;
		queries[i].y2 = y2;

		if(type == 1){
			disableRect(cyberverse, cyberunion, queries[i], M);
			//decrementing type 2 query count by 1 as initialized to Q
			type2Q--;
			//printf("1");
		}
		//printf("2");
	}

	make_connections(cyberverse, cyberunion, M, N);
	//printf("3");

	int ansind = (type2Q - 1);
	// array to store answers of queries of type 2
	vector<bool> ans = vector<bool>(type2Q,true);

	//printf("4");
	//iterating through queries in reverse order and find answer to queries of type 2
	for(int i = Q - 1; i >= 0; i--){

		// if query of type 1 
		if(queries[i].type1){
			enableRect(cyberverse, cyberunion, queries[i], M, N);
			continue;
		}
	
		ans[ansind] = cyberunion.connected(xyto1d(queries[i].x1, queries[i].y1),
												 xyto1d(queries[i].x2, queries[i].y2));
		ansind--;
	}
	
	//printf("5");
	//printing answers
	for(bool yes : ans){
		yes? printf("YES\n"): printf("NO\n");
	}
}
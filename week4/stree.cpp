#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<map>
#include<climits>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

// Segment Tree for Minimum in Range Query

class SegmentTree{
    public:
    int * stree;
    int * arr;
    int size,nodes;
    SegmentTree(int n){
        this->size = n+1;
        this->nodes = 4*n+1;
        stree = new int[nodes];
        arr = new int[size];
    }

    //Construction of Tree and Parameters
    //Segment Index:si
    //Segment Start:ss
    //Segment End: se
    void build(int si,int ss,int se){

        if (ss==se){
            stree[si] = arr[ss];
            return;
        }

        int mid = ss + (se-ss)/2;
        build(2*si,ss,mid);
        build(2*si+1,mid+1,se);

        stree[si] = min(stree[2*si],stree[2*si+1]);
    }

    //Querying and Parameters
    //Segment Index: si
    //Segment Start: ss
    //Segment End: se
    //Query Start: qs
    //Query End: qe
    int query(int si,int ss,int se,int qs,int qe){

        if (qe<ss || qs>se){
            return INT_MAX;
        }

        if (ss>=qs && se<=qe){
            return stree[si];
        }

        int mid = ss+(se-ss)/2;
        int l = query(2*si , ss , mid , qs , qe);
	    int r = query(2*si+1 , mid+1 , se , qs , qe);

        return min(l,r);
    }

    //Point Updation
    //Query Index : qi
    void update(int si,int ss,int se,int qi){
        if (ss==se){
            //arr[ss] is already updated
            stree[si] = arr[ss];
            return;
        }

        int mid = ss+(se-ss)/2;
        if (qi <= mid) update(2*si,ss,mid,qi);
        else update(2*si+1,mid+1,se,qi);

        stree[si] = min(stree[2*si],stree[2*si+1]);
    }
};
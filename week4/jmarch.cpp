#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<string>
#include<bitset>
#include<map>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define endl "\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long int ll;

//Select Leftmost & Bottom Most Point
//Keep selecting most clockwise point using cross product
//Most negative cross product is most clockwise
//cross product reduces precision errors because angles
//in computational geometry have precision issues(float,double etc)
//GFG approach uses difference in slope to find orientation
//no division used hence precision isn't an issue

struct Point{
    int x,y;
};

int orientation(Point p, Point q, Point r) 
{ 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
} 

void convexHull(vector<Point>& points,int n){
    if (n<3) return;

    vector<Point> hull;

    //take any leftmost point
    int l = 0;
    for (int i=1;i<n;i++)
        if (points[i].x < points[l].x)
            l=i;
    
    int p = l,q;
    //find the most clockwise point and store in q(wrt to q)
    do{
        hull.push_back(points[p]);
        //check the next point in the list, revert to base at p+1=n
        q = (p+1)%n;
        for (int i=0;i<n;i++){
            //if i is more clockwise from q, update q
            if (orientation(points[p],points[i],points[q])==2)
                q=i;
        }
        p=q;

    }while(p!=l);

    for (auto i:hull){
        cout << "(" << i.x << "," << i.y << ")" << endl;
    }
}

int main() 
{ 
    vector<Point> points= {{0, 3}, {2, 2}, {1, 1}, {2, 1}, 
                      {3, 0}, {0, 0}, {3, 3}}; 
    int n = 7;
    convexHull(points, n); 
    return 0; 
} 
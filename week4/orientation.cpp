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

//program to orientation of an ordered triplet
/*If orientation of (p1, p2, p3) is collinear, then orientation of (p3, p2, p1) is also collinear.
If orientation of (p1, p2, p3) is clockwise, then orientation of (p3, p2, p1) is counterclockwise
 and vice versa is also true.
 calculation using slope of 2 lines
*/

/*from gfg*/
struct Point{
    int x,y;
};

int orientation(Point p1,Point p2,Point p3){
    int val = (p2.y - p1.y)*(p3.x - p2.x) - (p2.x - p1.x)*(p3.y - p2.y);
    if (val == 0) return 0;//collinear
    return (val>0)?1:2;//1 clockwise,2 anticlockwise
}

int main(){
    Point p1={0,0}, p2={4,40}, p3 = {1,2};
    int o = orientation(p1,p2,p3);
    if (o=0) cout << "Collinear";
    else if(o=1) cout << "Clockwise";
    if (o=2) cout << "Anticlockwise";
    return 0;
}


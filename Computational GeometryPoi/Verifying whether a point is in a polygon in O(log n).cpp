Useful articles---
https://cp-algorithms.com/geometry/point-in-convex-polygon.html

Question----
https://codeforces.com/problemsets/acmsguru/problem/99999/253

Implementation
// 005 - 008
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;

// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#define ll long long int
#define ld long double
#define pb push_back
#define F first
#define S second
#define MOD 1000000007
#define mod1 1187278649
#define mod2 1149736019
#define ioi cout<<"\n------------ioi------------\n"
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

const ld PI=3.14159265358979323;
ll linf=(ll)2e18;
const int inf=1011111111;
const int N=100005;
// global variables...
int n, m, k;
struct point{
    ll x;
    ll y;
    point(){

    }
    point(ll _x, ll _y) : x(_x), y(_y){

    }
    point operator+(const point &pt) const {
        return point(x + pt.x, y + pt.y);
    }
    point operator-(const point &pt) const {
        return point(x - pt.x, y - pt.y);
    }
    ll cross(const point &pt) const {
        return x*pt.y - y*pt.x;
    }
    ll dot(const point &pt) const {
        return x*pt.x + y*pt.y;
    }
    ll cross(const point & pt1, const point & pt2) const {
        return (pt1 - *this).cross(pt2 - *this);
    }
    ll dot(const point &pt1, const point &pt2) const {
        return (pt1 - *this).dot(pt2 - *this);
    }
    ll sqrlen(){
        return this->dot(*this);
    }

};
point poly_vert[N], rocket_exp[N], arr[N], seq[N];

//functions...

void input(){
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i].x>>arr[i].y;
        arr[i].x += (ll)1e10;
        arr[i].y += (ll)1e10;
    }
    for(int i=0;i<m;i++){
        cin>>rocket_exp[i].x>>rocket_exp[i].y;
        rocket_exp[i].x += (ll)1e10;
        rocket_exp[i].y += (ll)1e10;
    }
    return;
}

bool sgn(ll val){
    return val>0 ? true : false;
}

bool point_in_triangle(point a, point b, point c, point d){
    ll s1 = abs(a.cross(b, c));
    ll s2 = abs(d.cross(a, b)) + abs(d.cross(b, c)) + abs(d.cross(c, a));
    return s1==s2;
}

bool point_in_convex_polygon(point pt){
    pt = pt - poly_vert[0];
    if(seq[0].cross(pt)!=0 and sgn(seq[0].cross(pt))!=sgn(seq[0].cross(seq[n-1])))
        return false;
    if(seq[n-1].cross(pt)!=0 and sgn(seq[n-1].cross(pt))!=sgn(seq[n-1].cross(seq[0])))
        return false;
    if(seq[0].cross(pt)==0)
        return seq[0].sqrlen() >= pt.sqrlen();
    int start = 0, end = n-1;
    while(end - start > 1){
        int mid = (start+end)/2;
        if(seq[mid].cross(pt)>=0)
            start = mid;
        else
            end = mid;
    }
    return point_in_triangle(seq[start], seq[start+1], point(0, 0), pt);
}

int main(){
    // #ifndef ONLINE_JUDGE
    //     freopen("inputf.txt", "r", stdin);
    //     freopen("outputf.txt", "w", stdout);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test=1;
    // cin>>test;
    while(test--){
        input();
        // at first we need to find the leftmost vertex(minimum x coordinate).
        // and if there is are many points with minimum x, then we take the one with minimum y.
        int pos = 0;    // initializing that point to be at index 0
        for(int i=1;i<n;i++){
            if(arr[i].x<arr[pos].x)
                pos = i;
            else if(arr[i].x==arr[pos].x){
                if(arr[i].y<arr[pos].y)
                    pos = i;
            }
        }
        // cout<<pos<<"\n";
        for(int i=0;i<n;i++){
            poly_vert[i].x = arr[(i+pos)%n].x;
            poly_vert[i].y = arr[(i+pos)%n].y;
        }
        n--;
        for(int i=0;i<n;i++)
            seq[i] = poly_vert[i+1] - poly_vert[0];

        // for(int i=0;i<n;i++)
        //     cout<<poly_vert[i].x<<" "<<poly_vert[i].y<<"\n";
        int ans = 0;
        for(int i=0;i<m;i++){
            if(point_in_convex_polygon(rocket_exp[i])){
                // cout<<i<<" yaaha\n";
                ans++;
            }
        }
        if(ans>=k)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

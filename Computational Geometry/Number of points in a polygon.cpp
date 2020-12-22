https://www.codechef.com/problems/CHEFPOLY

Here we need to find the number of points in a convex polygon whose vertices are given to us in a clockwise order.

Useful blogposts
https://discuss.codechef.com/t/chefpoly-editorial/12230

Code

// 004 - 007
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
const int N=200005;
// global variables...
struct point{                       // struct to store a 2D point
    int x;
    int y;
};
int n, m;
point red[105], black[3005], zero;  // global variables to store the data
int cnt[105][105], ord[105];        
// here cnt[i][j] stores the number of points inside the triangle formed by the vertices i, j, zero.
// so we have total n^2 pairs of i, j.

//functions...

void input(){
    cin>>n>>m;
    zero.x = 0;
    zero.y = 0;
    for(int i=0;i<n;i++){
        cin>>red[i].x>>red[i].y;
        red[i].x += 10005;          // adding an extra buffer to make all points positive.
        red[i].y += 10005;          // its basically shifting the co-ordinate system
    }
    for(int i=0;i<m;i++){
        cin>>black[i].x>>black[i].y;
        black[i].x += 10005;
        black[i].y += 10005;
    }
    return;
}

int func(point a, point b, point c){// finding the area of traingle a, b, c
    return (a.x - b.x)*(c.y - b.y) - (c.x - b.x)*(a.y - b.y);
}

bool check(point a, point b, point c, point d){ // utility function to check if point d lies inside traingle abc
    int abc = abs(func(a, b, c));
    int abd = abs(func(a, b, d));
    int bcd = abs(func(b, c, d));
    int cad = abs(func(c, a, d));
    if(abc == (abd + bcd + cad))            // condition for point that lies inside
        return true;
    else
        return false;
}

void precomp(){                             // here we precompute the number of points that lie in traingle i, j, zero
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(func(red[i], zero, red[j]) > 0){
                for(int k=0;k<m;k++){
                    if(check(red[i], zero, red[j], black[k]))
                        cnt[i][j]++;
                }
                cnt[j][i] = -cnt[i][j];     // necesarry condition.
            }
        }
    }
    return;
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
        int nq;
        cin>>nq;
        precomp();
        while(nq--){
            int k;
            cin>>k;
            for(int i=0;i<k;i++){
                cin>>ord[i];
                ord[i]--;
            }
            int ans = 0;            // variable that stores tha answer
            for(int i=0;i<k;i++){
                int ni = (i==k-1 ? 0 : i+1);
                ans += cnt[ord[i]][ord[ni]];
            }
            cout<<abs(ans)<<"\n";
        }
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

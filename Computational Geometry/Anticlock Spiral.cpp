Question ----
https://www.codechef.com/problems/COTH003

Implementation----
// 008 - 015
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
int n;
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
point arr[55];
bool vis[55];
vector <point> ans;

//functions...

void input(){
    ans.clear();
    cin>>n;
    for(int i=0;i<=n;i++){
        vis[i] = false;
    }
    for(int i=1;i<=n;i++)
        cin>>arr[i].x>>arr[i].y;
}

bool func2(point ref, point oldpt, point newpt){
    point v1 = oldpt - ref;
    point v2 = newpt - ref;
    if(v1.cross(v2)<0)
        return true;
    return false;
}

int func(point curr){
    int npos = 1;
    while(vis[npos])
        npos++;
    point var1 = arr[npos];
    int ans = npos;
    for(int i=npos+1;i<=n;i++){
        if(vis[i])
            continue;
        if(func2(curr, var1, arr[i])){
            var1 = arr[i];
            ans = i;
        }
    }
    return ans;
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
    cin>>test;
    while(test--){
        input();
        int pos = 0;
        point pmax = {0, -105};
        for(int i=1;i<=n;i++){
            if(arr[i].y>pmax.y){
                pos = i;
                pmax.x = arr[i].x;
                pmax.y = arr[i].y;
            }
        }
        ans.pb(pmax);
        vis[pos] = true;
        while(sz(ans)!=n){
            int next = func(pmax);
            ans.pb(arr[next]);
            vis[next] = true;
            pmax = arr[next];
        }
        for(int i=0;i<sz(ans);i++)
            cout<<ans[i].x<<" "<<ans[i].y<<" ";
        cout<<"\n";
    }

    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

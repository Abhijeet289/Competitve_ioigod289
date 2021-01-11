Question----
https://codeforces.com/contest/1468/problem/G

Solution----
// 010 - 016
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
const ld EPS = 1e-9;
// global variables...
int n;
int xrr[N], yrr[N], H;
long double ans = 0;
struct point{
    ld x;
    ld y;
    point(){

    }
    point(ld _x, ld _y) : x(_x), y(_y){

    }
    point operator+(const point &pt) const {
        return point(x + pt.x, y + pt.y);
    }
    point operator-(const point &pt) const {
        return point(x - pt.x, y - pt.y);
    }
    bool operator<(const point &pt) const {
        return (x < pt.x - EPS) or (abs(x - pt.x) < EPS and y < pt.y - EPS);
    }
    ld cross(const point &pt) const {
        return x*pt.y - y*pt.x;
    }
    ld dot(const point &pt) const {
        return x*pt.x + y*pt.y;
    }
    ld cross(const point & pt1, const point & pt2) const {
        return (pt1 - *this).cross(pt2 - *this);
    }
    ld dot(const point &pt1, const point &pt2) const {
        return (pt1 - *this).dot(pt2 - *this);
    }
    ld sqrt_dist(const point &pt) const {
        return (ld)sqrt((pt.x - x)*(pt.x - x) + (pt.y - y)*(pt.y - y));
    }
    ld sqrlen(){
        return this->dot(*this);
    }
    void show(){
        cout<<x<<" "<<y<<"\n";
        return;
    }
};

struct line{
    // ax + by + c = 0 line
    double a;
    double b;
    double c;
    line() {}
    line(point p, point q){
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a*p.x - b*p.y;
        norm();
    }
    void norm(){
        ld z = (ld)sqrt(a*a + b*b);
        if(abs(z) > EPS){
            a/=z;
            b/=z;
            c/=z;
        }
    }
    ld dist(point p) const {
        return a*p.x + b*p.y + c;
    }
};
point arr[N], eye, peak;


//functions...

void input(){
    cin>>n>>H;
    for(int i=0;i<n;i++)
        cin>>xrr[i]>>yrr[i];
    eye = {(ld)xrr[n-1], (ld)yrr[n-1]+H};
    peak = {(ld)xrr[n-1], (ld)yrr[n-1]};
}

double deter(double a, double b, double c, double d){
    return a*d - b*c;
}

inline bool betw(ld l, ld r, ld x){
    return min(l, r) <= x + EPS && x <= max(l, r) + EPS;
}

inline bool intersect_1d(ld a, ld b, ld c, ld d){
    if(a > b)
        swap(a, b);
    if(c > d)
        swap(c, d);
    return max(a, c) <= min(b, d) + EPS;
}

bool inter_line_and_seg(line m, point a, point b, point &lf, point &rg){
    line n(a, b);
    ld den = deter(m.a, m.b, n.a, n.b);
    if(abs(den) < EPS){         // two cases here when den ~ 0
        if(abs(m.dist(a)) > EPS)
            return false;       // parellel lines
        ans += a.sqrt_dist(b);  // the complete line is visible now.
        return true;            // same lines
    }
    else{
        lf.x = rg.x = -1*(deter(m.c, m.b, n.c, n.b))/den;
        lf.y = rg.y = -1*(deter(m.a, m.c, n.a, n.c))/den;
        if(betw(a.x, b.x, lf.x) and betw(a.y, b.y, lf.y)){
            ans += lf.sqrt_dist(a);
            return true;
        }
        else{
            return false;
        }
    }
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
        cout<<fixed<<setprecision(9);
        for(int i=n-2;i>=0;i--){
            point la(xrr[i], yrr[i]);
            point lb(xrr[i+1], yrr[i+1]);
            // check if we can see the point la from eye where is peak is the largest hindrance,
            point vec1 = peak - eye;
            point vec2 = la - eye;
            if(vec1.cross(vec2) > 0)   // case where we cannot see any part of line.
                continue;
            point int_left, int_right;
            line ln1(eye, peak);
            if(!inter_line_and_seg(ln1, la, lb, int_left, int_right))
                continue;
            peak = la;
        }
        cout<<ans<<"\n";
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

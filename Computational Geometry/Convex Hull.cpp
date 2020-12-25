useful resources----
http://wcipeg.com/wiki/Convex_hull_trick

Question----
https://codeforces.com/problemset/problem/319/C

Implementation----
// 007 - 012
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
int n;
ll arr[N], brr[N], dp[N];

struct convex_hull_dynamic{
    static const ll INF = 1e18;
    struct Line{
        ll a, b; // y = ax + b
        double xleft; // stores the intersection with the previous line in convex hull. First line has -INF
        enum Type {line, maxQuery, minQuery} type;
        ll val;
        explicit Line(ll aa=0, ll bb=0): a(aa), b(bb), xleft(-INF), type(Type::line), val(0) {}
        ll valueAt(ll x) const {
            return a*x+b;
        }
        friend bool isParallel(const Line &l1, const Line &l2){
            return l1.a==l2.a;
        }
        friend double intersectX(const Line &l1, const Line &l2){
            return isParallel(l1, l2) ? INF : 1.0*(l2.b - l1.b)/(l1.a - l2.a);
        }
        bool operator<(const Line& l2) const {
            if(l2.type==line)
                return this->a < l2.a;
            if(l2.type==maxQuery)
                return this->xleft < l2.val;
            if(l2.type==minQuery)
                return this->xleft > l2.val;
        }
    };
    bool isMax;
    set <Line> hull;
    bool hasPrev(set <Line> :: iterator it){
        return it!=hull.begin();
    }
    bool hasNext(set <Line> :: iterator it){
        return it!=hull.end() and next(it)!=hull.end();
    }
    bool irrelevant(const Line &l1, const Line &l2, const Line &l3){
        return intersectX(l1, l3) <= intersectX(l1, l2);
    }
    bool irrelevant(set <Line> :: iterator it){
        return hasPrev(it) and hasNext(it) and 
        ((isMax and irrelevant(*prev(it), *it, *next(it))) or (!isMax and irrelevant(*next(it), *it, *prev(it))));
    }
    set <Line> :: iterator updateLeftBorder (set <Line> :: iterator it){
        if(isMax and !hasPrev(it) or !isMax and !hasNext(it))
            return it;
        double val = intersectX(*it, isMax ? (*prev(it)) : (*next(it)));
        Line tmp(*it);
        it = hull.erase(it);
        tmp.xleft = val;
        it = hull.insert(it, tmp);
        return it;
    }
    explicit convex_hull_dynamic(bool isMax): isMax(isMax) {}
    void addLine(ll a, ll b){ // add line ax+b in logN time
        Line l3 = Line(a, b);
        auto it = hull.lower_bound(l3);
        // if parallel line is already in the set, one of the lines becomes irrelevant
        if(it!=hull.end() and isParallel(*it, l3)){
            if(isMax and it->b < b or !isMax and it->b > b)
                it = hull.erase(it);
            else
                return;
        }
        it = hull.insert(it, l3);
        if(irrelevant(it)){
            hull.erase(it);
            return;
        }

        // Remove the lines which become irrelevant after adding l3
        while(hasPrev(it) and irrelevant(prev(it)))
            hull.erase(prev(it));
        while(hasNext(it) and irrelevant(next(it)))
            hull.erase(next(it));

        // Update xLine
        it = updateLeftBorder(it);
        if(hasPrev(it))
            updateLeftBorder(prev(it));
        if(hasNext(it))
            updateLeftBorder(next(it));
    }
    ll getBest(ll x){
        Line q;
        q.val = x;
        q.type = isMax ? Line :: Type :: maxQuery : Line :: Type :: minQuery;
        auto bestLine = hull.lower_bound(q);
        if(isMax)
            --bestLine;
        return bestLine->valueAt(x);
    }
};
convex_hull_dynamic hull(0); // 0 for minimum convexhull

//functions...

void input(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<=n;i++)
        cin>>brr[i];
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
        dp[1] = 0; // trivial case
        hull.addLine(brr[1], dp[1]);
        for(int i=2;i<=n;i++){
            dp[i] = hull.getBest(arr[i]);
            hull.addLine(brr[i], dp[i]);
        }
        cout<<dp[n]<<"\n";
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

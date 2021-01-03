Question----
https://open.kattis.com/problems/convexhull

Implementation----
// 002 - 001
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
point arr[N];
struct stt1{
    ld slope;
    ld len;
    int idx;
};

//functions...

void input(){               // function to input the points
    cin>>n;
    if(n==0)
        exit(0);            // condition to end the input
    for(int i=0;i<n;i++)
        cin>>arr[i].x>>arr[i].y;
}

int func(point a, point b, point c){
    point ca = a - c;
    point cb = b - c;
    ll val = ca.cross(cb);
    if(val == 0){
        return 0;
    }
    else if(val > 0){
        return 1;
    }
    else{
        return -1;
    }
}

bool cmp(const stt1 &a, const stt1 &b){
    if(a.slope==b.slope)
        return a.len > b.len;
    return a.slope < b.slope;
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
    while(1){
        input();
        int idx_bottom_left = 0;        // it will store the index of bottommost left point

        for(int i=1;i<n;i++)
            if((arr[i].y < arr[idx_bottom_left].y) or ((arr[i].y == arr[idx_bottom_left].y)  and  (arr[i].x < arr[idx_bottom_left].x)))
                idx_bottom_left = i;

        deque <point> dq1;
        dq1.push_back(arr[idx_bottom_left]);

        vector <stt1> vec1;             // this will store all the remaining points
                                        // and then we sort the points according to their polar angles
        for(int i=0;i<n;i++){
            if(arr[i].x == arr[idx_bottom_left].x and arr[i].y == arr[idx_bottom_left].y)
                continue;
            ld slope = atan2((arr[i].y - arr[idx_bottom_left].y), (arr[i].x - arr[idx_bottom_left].x));
            ld len = (arr[i] - arr[idx_bottom_left]).sqrlen();
            vec1.pb({slope, len, i});
        }

        sort(all(vec1), cmp);           // sorting according to cmp function

        int m = sz(vec1);

        if(m==0){                       // just a trivial case.
            cout<<"1\n";
            cout<<dq1.back().x<<" "<<dq1.back().y<<"\n";
            continue;
        }

        vector <stt1> vec2;             // this vector stores the distinct slopes from vec1
        vec2.pb(vec1[0]);
        stt1 prev = vec1[0];
        for(int i=1;i<m;i++){
            if(vec1[i].slope == prev.slope)
                continue;
            else{
                vec2.pb(vec1[i]);
                prev = vec1[i];
            }
        }
        m = sz(vec2);

        if(m<=2){                       // another trivial case
            for(int i=0;i<m;i++)
                dq1.push_back(arr[vec2[i].idx]);
            cout<<m+1<<"\n";
            while(!dq1.empty()){
                cout<<dq1.front().x<<" "<<dq1.front().y<<"\n";
                dq1.pop_front();
            }
            continue;
        }

        dq1.push_back(arr[vec2[0].idx]);
        dq1.push_back(arr[vec2[1].idx]);
        int cur_idx = 2;
        while(cur_idx < m){
            point last1 = dq1.back();
            dq1.pop_back();
            point last2 = dq1.back();
            dq1.push_back(last1);
            int res = func(last1, last2, arr[vec2[cur_idx].idx]);
            if(res < 0){
                dq1.push_back(arr[vec2[cur_idx].idx]);
                cur_idx++;
            }
            else{
                dq1.pop_back();
            }
        }
        cout<<sz(dq1)<<"\n";
        while(!dq1.empty()){
            cout<<dq1.front().x<<" "<<dq1.front().y<<"\n";
            dq1.pop_front();
        }
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

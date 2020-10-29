https://www.spoj.com/problems/POSTERS/


#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#define ll long long int
#define ld long double
#define pb push_back
#define F first
#define S second
#define MOD 998244353
#define mod1 1187278649
#define mod2 1149736019
#define ioi cout<<"\n------------ioi------------\n"
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

const ld PI=3.14159265358979323;
ll linf=(ll)2e18;
const int inf=1011111111;
const int N=10000005;
// global variables...
int n, m;
int sgt[N], lazy[4*N];
vector < pair <int,int> > vec;
vector <int> v1;
set <int> st1;

//functions...
void input(){
    cin>>n;
    for(int i=0;i<=4*n;i++)
        lazy[i] = 0;
    vec.clear();
    v1.clear();
    st1.clear();
    for(int i=0;i<n;i++){
        int i1, i2;
        cin>>i1>>i2;
        vec.pb({i1, i2});
        st1.insert(i1);
        st1.insert(i2);
    }
    for(auto it:st1)
        v1.pb(it);
    m = sz(v1);
    st1.clear();
    // sort(all(v1));
}

void propogate(int idx, int start, int end){
    if(start!=end){
        lazy[2*idx+1] = lazy[idx];
        lazy[2*idx+2] = lazy[idx];
    }
    lazy[idx] = 0;
    return;
}

void update(int idx, int start, int end, int l, int r, int color){
    if(start>r or end<l)
        return;
    if(start>=l and end<=r){
        lazy[idx] = color;
        return;
    }
    if(lazy[idx])
        propogate(idx, start, end);
    int mid = (start+end)/2;
    update(2*idx+1, start, mid, l, r, color);
    update(2*idx+2, mid+1, end, l, r, color);
}

void query(int idx, int start, int end){
    if(lazy[idx]!=0){
        st1.insert(lazy[idx]);
        return;
    }
    int mid = (start+end)/2;
    query(2*idx+1, start, mid);
    query(2*idx+2, mid+1, end);
    return;
}

int main()
{
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
        // for(auto i:v1)
        //     cout<<i<<" ";
        // cout<<"\n";
        for(int i=0;i<n;i++){
            int lp = vec[i].F;
            int rp = vec[i].S;
            int lpos = lower_bound(all(v1), lp) - v1.begin();
            int rpos = lower_bound(all(v1), rp) - v1.begin();
            // cout<<lpos<<" "<<rpos<<"\n";
            update(0, 0, m-1, lpos, rpos, i+1);
        }
        // for(int i=0;i<=14;i++)
        //     cout<<lazy[i]<<" ";
        // cout<<"\n";
        query(0, 0, m-1);
        cout<<sz(st1)<<"\n";
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

//https://codeforces.com/contest/380/problem/C

//https://codeforces.com/contest/380/submission/96492175

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
const int N=1000005;
// global variables...
int n;
string str;
struct abhi{
    int open;
    int close;
    int ans;
};
abhi segtree[4*N];

//functions...
void input(){
    cin>>str;
    n = sz(str);
}

void build(int node, int start, int end){
    if(start==end){
        abhi tmp1;
        tmp1.open = 0;
        tmp1.close = 0;
        tmp1.ans = 0;
        segtree[node] = tmp1;
        if(str[start]=='('){
            segtree[node].open = 1;
        }
        else{
            segtree[node].close = 1;
        }
        return;
    }
    int mid = (start+end)/2;
    build(2*node+1, start, mid);
    build(2*node+2, mid+1, end);
    abhi tmp2;
    int tmp3 = min(segtree[2*node+1].open, segtree[2*node+2].close);
    tmp2.ans = segtree[2*node+1].ans + segtree[2*node+2].ans + 2*tmp3;
    tmp2.open = segtree[2*node+1].open + segtree[2*node+2].open - tmp3;
    tmp2.close = segtree[2*node+1].close + segtree[2*node+2].close - tmp3;
    segtree[node] = tmp2;
    return;
}

abhi query(int node, int start, int end, int l, int r){
    if(l>end or r<start){
        abhi tmp5;
        tmp5.open = 0;
        tmp5.close = 0;
        tmp5.ans = 0;
        return tmp5;
    }
    if(start>=l and end<=r){
        return segtree[node];
    }
    int mid = (start+end)/2;
    abhi q1 = query(2*node+1, start, mid, l, r);
    abhi q2 = query(2*node+2, mid+1, end, l, r);
    abhi q3;
    int tmp6 = min(q1.open, q2.close);
    q3.ans = q1.ans + q2.ans + 2*tmp6;
    q3.open = q1.open + q2.open - tmp6;
    q3.close = q1.close + q2.close - tmp6;
    return q3;
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
    // cin>>test;
    while(test--){
        input();
        build(0, 0, n-1);
        int q;
        cin>>q;
        while(q--){
            int l, r;
            cin>>l>>r;
            l--;
            r--;
            abhi tmp4 = query(0,0,n-1,l,r);
            cout<<tmp4.ans<<"\n";
        }
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

// 058
// april 19th, 2021
// true
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
ll MOD = 1000000007;
double eps = 1e-12;
#define forsn(i,s,e) for(ll i = s; i <= e; i++)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define tcend "------------\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
const int N=1e5+7, LGN=log2(N)+1;

// global variables
int n, m, ct=0, num=0;
int arr[N], root[N], sgt[21*N], lc[21*N], rc[21*N];
map <int,int> mp1, rmp1;

int build(int start, int end){
    int node = ++ct;
    if(start==end) return node;
    int mid = (start+end)/2;
    lc[node] = build(start, mid);
    rc[node] = build(mid+1, end);
    return node;
}

int update(int onode, int start, int end, int pos){
    int node = ++ct;
    if(start==end){
        sgt[node] = sgt[onode] + 1;
        return node;
    }
    int mid = (start+end)/2;
    lc[node] = lc[onode];
    rc[node] = rc[onode];
    if(pos <= mid) lc[node] = update(lc[onode], start, mid, pos);
    else rc[node] = update(rc[onode], mid+1, end, pos);
    sgt[node] = sgt[lc[node]] + sgt[rc[node]];
    return node;
}

int query(int lnode, int rnode, int start, int end, int pos){
    if(start==end) return start;
    int mid = (start+end)/2;
    int lcnt = sgt[lc[rnode]] - sgt[lc[lnode]];
    int rcnt = sgt[rc[rnode]] - sgt[rc[lnode]];
    if(lcnt >= pos) return query(lc[lnode], lc[rnode], start, mid, pos);
    else return query(rc[lnode], rc[rnode], mid+1, end, pos-lcnt);
}

void solve(){
    cin>>n>>m;
    forsn(i, 1, n){
        cin>>arr[i];
        mp1[arr[i]];
    }
    for(auto &it:mp1){
        it.se = ++num;
        rmp1[num] = it.fi;
    }
    forsn(i, 1, n) arr[i] = mp1[arr[i]];
    // forsn(i, 1, n) cout<<arr[i]<<" "; cout<<ln;
    root[0] = build(1, num);
    forsn(i, 1, n) root[i] = update(root[i-1], 1, num, arr[i]);
    forsn(i, 1, m){
        int l, r, k;
        cin>>l>>r>>k;
        int var1 = query(root[l-1], root[r], 1, num, k);
        cout<<rmp1[var1]<<"\n";
    }
    return;
}

int main(){
    fast_cin();
    ll t = 1;
    // cin >> t;
    for(int it=1;it<=t;it++){
        // cout << "Case #" << it << ": ";
        solve();
        // cout<<tcend;
    }
    return 0;
}   

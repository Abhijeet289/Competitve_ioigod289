// https://codeforces.com/gym/101147/problem/J

// https://codeforces.com/gym/101147/submission/96360886

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
const int N=500005;
// global variables...
ll n, tt = 0;
ll dist[N], sttime[N], endtime[N], arr[N], brr[N];
vector < pair <ll, ll> > g[N];
vector <ll> tree[4*N];
bool vis[N];

//functions...
void input(){
    cin>>n;
    tt = 0;
    for(int i=0;i<=n+2;i++){
        vis[i] = false;
        dist[i] = 0;
        brr[i] = 0;
        sttime[i] = 0;
        endtime[i] = 0;
        g[i].clear();
    }
    for(int i=0;i<=4*n;i++){
        tree[i].clear();
    }
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    for(ll i=0;i<n-1;i++){
        ll u, v, w;
        cin>>u>>v>>w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
}

void dfs(ll node){
    vis[node] = true;
    sttime[node] = ++tt;
    for(auto it:g[node]){
        ll v = it.F;
        ll w = it.S;
        if(vis[v])
            continue;
        dist[v] = dist[node] + w;
        dfs(v);
    }
    endtime[node] = tt;
}

vector <ll> merge(vector<ll>& v1, vector<ll>& v2) 
{ 
    ll i = 0, j = 0; 
    vector<ll> v; 
    while (i < v1.size() && j < v2.size()) { 
        if (v1[i] <= v2[j]) { 
            v.push_back(v1[i]); 
            i++; 
        } 
        else { 
            v.push_back(v2[j]); 
            j++; 
        } 
    } 
    for (ll k = i; k < v1.size(); k++) 
        v.push_back(v1[k]); 
    for (ll k = j; k < v2.size(); k++) 
        v.push_back(v2[k]); 
    return v; 
} 

void build(ll node, ll start, ll end){
    if(start==end){
        tree[node].pb(brr[start]);
        return;
    }
    ll mid = (start+end)/2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    tree[node] = merge(tree[2*node], tree[2*node+1]);
}

ll query(ll node, ll start, ll end, ll l, ll r, ll k){
    if(start>r or end<l)
        return 0;
    if(start>=l and end<=r){
        return (tree[node].size() - (lower_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin()));
    }
    ll mid = (start+end)/2;
    return query(2*node, start, mid, l, r, k) + query(2*node+1, mid+1, end, l, r, k);
}

int main()
{
    // #ifndef ONLINE_JUDGE
        freopen("car.in", "r", stdin);
    //     freopen("outputf.txt", "w", stdout);
    // #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll test=1;
    cin>>test;
    while(test--){
        input();
        dfs(1);
        // for(ll i=1;i<=n;i++)
        //     cout<<dist[i]<<" ";
        // cout<<"\n";
        // for(ll i=1;i<=n;i++)
        //     cout<<sttime[i]<<" ";
        // cout<<"\n";
        // for(ll i=1;i<=n;i++)
        //     cout<<endtime[i]<<" ";
        // cout<<"\n";
        for(ll i=1;i<=n;i++){
            brr[sttime[i]] = arr[i] - dist[i];
        }
        // for(int i=1;i<=n;i++)
        //     cout<<brr[i]<<" ";
        // cout<<"\n";
        build(1, 1, n);
        for(ll i=1;i<=n;i++){
            ll l = sttime[i];
            ll r = endtime[i];
            ll k = dist[i];
            ll ans = query(1, 1, n, l, r, -k);
            cout<<ans-1<<" ";
        }
        cout<<"\n";
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

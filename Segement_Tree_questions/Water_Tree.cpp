// https://codeforces.com/problemset/problem/343/D
// 7
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
int n, tim;
int sttime[N], endtime[N], segtree[4*N], lazy[4*N], papa[N];
vector <int> g[N];
bool vis[N];

//functions...
void input(){
    cin>>n;
    for(int i=0;i<n-1;i++){
    	int u, v;
    	cin>>u>>v;
    	g[u].pb(v);
    	g[v].pb(u);
    }
    tim = 0;
}

void dfs(int node){
	vis[node] = true;
	sttime[node] = tim++;
	for(int v:g[node]){
		if(vis[v])
			continue;
		papa[v] = node;
		dfs(v);
	}
	endtime[node] = tim-1;
}

void lazy_update(int node, int start, int end){
	if(lazy[node]==0)
		return;
	segtree[node] = lazy[node];
	if(start!=end){
		lazy[2*node+1] = lazy[node];
		lazy[2*node+2] = lazy[node];
	}
	lazy[node] = 0;
}

void build(int node, int start, int end){
	if(start==end){
		segtree[node] = 1;
		return;
	}
	int mid = (start+end)/2;
	build(2*node+1, start, mid);
	build(2*node+2, mid+1, end);
	segtree[node] = min(segtree[2*node+1], segtree[2*node+2]);
	return;
}

int query(int node, int start, int end, int ql, int qr){
	lazy_update(node, start, end);
	if(ql>end or qr<start)
		return inf;
	if(start>=ql and end<=qr)
		return segtree[node];
	int mid = (start+end)/2;
	int q1 = query(2*node+1, start, mid, ql, qr);
	int q2 = query(2*node+2, mid+1, end, ql, qr);
	return min(q1, q2);
}

void update(int node, int start, int end, int ql, int qr, int val){
	lazy_update(node, start, end);
	if(ql>end or qr<start)
		return;
	if(start>=ql and end<=qr){
		segtree[node] = val;
		if(start!=end){
			lazy[2*node+1] = val;
			lazy[2*node+2] = val;
		}
		return;
	}
	int mid = (start+end)/2;
	update(2*node+1, start, mid, ql, qr, val);
	update(2*node+2, mid+1, end, ql, qr, val);
	segtree[node] = min(segtree[2*node+1], segtree[2*node+2]);
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
    // cin>>test;
    while(test--){
        input();
        // now alloting the start and the end times.
        papa[1] = 1;
        dfs(1);
        // priting the intervals;
        // for(int i=1;i<=n;i++){
        // 	cout<<sttime[i]<<" "<<endtime[i]<<"\n";
        // }
        // ioi;
        // cout<<tim<<"\n";
        build(0, 0, tim-1);
        int q;
        cin>>q;
        while(q--){
        	int type, num;
        	cin>>type>>num;
        	int cur = query(0, 0, tim-1, sttime[num], endtime[num]);
        	if(type==1){
        		update(0, 0, tim-1, sttime[num], endtime[num], 2);
        		if(cur==1){
        			if(num!=papa[num])
        				update(0, 0, tim-1, sttime[papa[num]], sttime[papa[num]], 1);
        		}
        	}
        	else if(type==2)
        		update(0, 0, tim-1, sttime[num], sttime[num], 1);
        	else if(type==3)
        		cout<<query(0, 0, tim-1, sttime[num], endtime[num])-1<<"\n";
        }
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

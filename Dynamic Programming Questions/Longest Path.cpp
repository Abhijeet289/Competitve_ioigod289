// https://atcoder.jp/contests/dp/tasks/dp_g

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
const int N=100005;
// global variables...
int n, m;
int path[N];
vector <int> g[N];
bool vis[N];

//functions...
void input(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	int u, v;
    	cin>>u>>v;
    	g[u].pb(v);
    }
}

void dfs(int node){
	vis[node] = true;
	path[node] = 0;
	for(int v:g[node]){
		if(vis[v]){
			path[node] = max(path[node], 1+path[v]);
		}
		else{
			dfs(v);
			path[node] = max(path[node], 1+path[v]);
		}
	}
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
        for(int i=1;i<=n;i++){
        	if(vis[i])
        		continue;
        	dfs(i);
        }
        int ans = 0;
        for(int i=1;i<=n;i++)
        	ans = max(ans, path[i]);
        cout<<ans<<"\n";
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

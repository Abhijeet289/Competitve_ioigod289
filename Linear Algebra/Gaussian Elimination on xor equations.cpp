Useful resources----
https://math.stackexchange.com/questions/169921/how-to-solve-system-of-linear-equations-of-xor-operation?rq=1

Question-----
https://codeforces.com/gym/102861/problem/K

Implementation----
// 006 - 011
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
const int N=105;
// global variables...
int n, m;
int matrix[N][N], arr[N];
vector <int> g[N];

//functions...

void input(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void gausian_elimination_on_xors(){
    for(int i=1;i<=n;i++){
        int idx = i;
        while(matrix[idx][i]==0 and idx<=n)
            idx++;
        if(idx==n+1)
            continue;
        if(idx!=i)
            swap(matrix[i], matrix[idx]);
        for(int j=1;j<=n;j++){
            if(i==j)
                continue;
            int pivot = matrix[i][i];
            int lower = matrix[j][i];
            if(lower==1){
                for(int k=1;k<=n+1;k++)
                    matrix[j][k] = matrix[j][k] ^ matrix[i][k];
            }
        }
    } 
    return;
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

        for(int i=1;i<=n;i++){
            int len = sz(g[i]);
            if(len%2==0){
                for(auto v:g[i])
                    matrix[i][v] = 1;
                matrix[i][n+1] = 1;
            }
            else{
                for(auto v:g[i])
                    matrix[i][v] = 1;
                matrix[i][i] = 1;
            }
        }
        gausian_elimination_on_xors();
        bool ok = true;
        for(int i=n;i>=1;i--){
            if(matrix[i][n+1]!=0 and matrix[i][i]==0){
                ok = false;
                break;
            }
        }
        if(ok)
            cout<<"Y\n";
        else
            cout<<"N\n";
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

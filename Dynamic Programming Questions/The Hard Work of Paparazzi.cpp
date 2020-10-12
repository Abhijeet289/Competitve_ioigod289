//https://codeforces.com/contest/1427/problem/C

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
int r, n;
int arr[N][3], dp[N], mdp[N];

//functions...
void input(){
    cin>>r>>n;
    arr[0][0] = 0, arr[0][1] = 1, arr[0][2] = 1;
    for(int i=1;i<=n;i++)
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];

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
        for(int i=0;i<=n;i++)
            dp[i] = -inf;
        dp[0] = 0;
        mdp[0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=1000;j++){
                if((i-j)<0)
                    break;
                if(dp[i-j]==-inf)
                    continue;
                int diff1 = abs(arr[i][1]-arr[i-j][1]) + abs(arr[i][2]-arr[i-j][2]);
                int diff2 = arr[i][0] - arr[i-j][0];
                if(diff1<=diff2)
                    dp[i] = max(dp[i-j]+1, dp[i]);
            }
            if(i-1000>0)
            	dp[i] = max(dp[i], mdp[i-1001]+1);
            mdp[i] = max(mdp[i-1], dp[i]);
        }
        // for(int i=0;i<=n;i++)
        //  cout<<dp[i]<<" ";
        // ioi;
        int ans = 0;
        for(int i=0;i<=n;i++)
            ans = max(ans, dp[i]);
        cout<<ans<<"\n";
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

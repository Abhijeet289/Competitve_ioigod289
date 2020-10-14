// https://codeforces.com/contest/1426/problem/F


#include <bits/stdc++.h>
using namespace std;
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
const int N=200005;
// global variables...
ll n;
ll dp[N][5];
string str;

//functions...
void input(){
    cin>>n>>str;
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
        ll num = 1;
        for(int i=1;i<=n;i++){
        	if(str[i-1]=='?'){
        		dp[i][0] = ((dp[i-1][0]*3)%MOD + num)%MOD;
        		num = (num*3)%MOD;
        		dp[i][1] = ((dp[i-1][1]*3)%MOD + dp[i-1][0])%MOD;
        		dp[i][2] = ((dp[i-1][2]*3)%MOD + dp[i-1][1])%MOD;
        	}
        	else if(str[i-1]=='a'){
        		dp[i][0] = (dp[i-1][0] + num)%MOD;
        		dp[i][1] = dp[i-1][1];
        		dp[i][2] = dp[i-1][2];
        	}
        	else if(str[i-1]=='b'){
        		dp[i][1] = (dp[i-1][1] + dp[i-1][0])%MOD;
        		dp[i][0] = dp[i-1][0];
        		dp[i][2] = dp[i-1][2];
        	}
        	else if(str[i-1]=='c'){
        		dp[i][2] = (dp[i-1][2] + dp[i-1][1])%MOD;
        		dp[i][0] = dp[i-1][0];
        		dp[i][1] = dp[i-1][1];
        	}
        }
        cout<<dp[n][2]<<"\n";
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

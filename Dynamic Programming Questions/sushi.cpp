//Sushi - Atcodr Dp Contest.
//https://atcoder.jp/contests/dp/tasks/dp_j

//First : what really matters is the number of dishes with 0, 1, 2 and 3 sushis and not the order of the dishes.
//So answer for 2,1,0,2,1 is same as answer for 0,1,1,2,2.
//Number of dishes with 0 sushis is easily determined by N - one - two - three, where one is the number of dishes with 1 sushi and N is the total number of dishes in the input.
//Let F(x, y, z) be the expected moves needed for x dishes with 1 sushi, y with 2 and z with 3.
//Now in the next move we can pick a dish with 1 sushi with a probability of x/N or p1. we can pick a dish with 2 sushi with a probability of y/N or p2. we can pick a dish with 3 sushi with a probability of z/N or p3. we can pick a dish with 0 sushi with a probability of (N - (x + y + z))/N or p0.
//Now try to understand this :
//F(x,y,z) = 1 + p0F(x,y,z) + p1F(x-1,y,z) + p2F(x+1,y-1,z) + p3F(x,y+1,z-1)
//Here we add a 1 for the current move that we are making.
//(Note : if you pick a dish with 3 sushi z decreases but y increases)
//This equation now becomes :
//(1 - p0) F(x,y,z) = 1 + p1F(x-1,y,z) + p2F(x+1,y-1,z) + p3*F(x,y+1,z-1)
//simplifies to:
//F(x,y,z) = (p1F(x-1,y,z) + p2F(x+1,y-1,z) + p3*F(x,y+1,z-1))/(1-p0)



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
const int N=305;
// global variables...
int n;
ld arr[N], dp[N][N][N];

//functions...
void input(){
    cin>>n;
    for(int i=0;i<n;i++)
    	cin>>arr[i];
}

ld func(int ct1, int ct2, int ct3){
	// cout<<ct1<<" "<<ct2<<" "<<ct3<<"\n";
	if(ct1<0 or ct2<0 or ct3<0)
		return 0;
	if(ct1==0 and ct2==0 and ct3==0)
		return 0;
	if(dp[ct1][ct2][ct3]>0)
		return dp[ct1][ct2][ct3];
	ld rem = ct1+ct2+ct3;
	return dp[ct1][ct2][ct3] = (ld)(n+ct1*func(ct1-1, ct2, ct3)+ct2*func(ct1+1, ct2-1, ct3)+ct3*func(ct1, ct2+1, ct3-1))/rem;
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
        memset(dp, 0, sizeof dp);
        int q1 = 0, q2 = 0, q3 = 0;
        for(int i=0;i<n;i++){
        	if(arr[i]==1)
        		q1++;
        	else if(arr[i]==2)
        		q2++;
        	else if(arr[i]==3)
        		q3++;
        }
        ld ans = func(q1, q2, q3);
        cout<<fixed<<setprecision(12)<<ans<<"\n";
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

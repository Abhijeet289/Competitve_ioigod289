
// T
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#define int long long int
#define ld long double
#define pii pair <int,int> 
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
int linf=(int)2e18;
const int inf=1011111111;
const int N=200005;
// global variables...
int n;
string s1;

//functions...
void input(){
    cin>>n>>s1;
}

int32_t main()
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
    int tr=1;
    while(test--){
        input();
        int ct1=0, ct2=0;
        for(int i=0;i<n;i++){
            if(s1[i]=='A')
                ct1++;
            else
                ct2++;
        }
        if(ct1<ct2)
            swap(ct1, ct2);
        int diff=ct1-ct2;
        char ans='Y';
        if(diff>1)
            ans='N';
        cout<<"Case #"<<tr++<<": "<<ans<<"\n";
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
}

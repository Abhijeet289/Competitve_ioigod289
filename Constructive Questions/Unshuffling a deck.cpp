// https://codeforces.com/contest/1427/problem/D

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
int n;
int arr[60], pos[60];
vector <int> vec[60];

//functions...
void input(){
    cin>>n;
    for(int i=0;i<n;i++)
    	cin>>arr[i];
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
        bool ok = true;
        int tr = 0;
        int tmp = 100;
        while(tmp--){
        	for(int i=0;i<n;i++)
        		pos[arr[i]] = i;
        	ok = false;
        	for(int i=1;i<=n;i++){
        		if(pos[i]!=i-1)
        			ok = true;
        	}
        	if(!ok)
        		break;
        	for(int i=2;i<=n;i++){
        		int q1 = pos[i-1];
        		int q2 = pos[i];
        		if(q1<=q2)
        			continue;
        		int tmp;
        		for(int j=q2;j<q1;j++){
        			if(arr[j]>arr[j+1]){
        				tmp = j;
        				break;
        			}
        		}
        		// cout<<q2<<" "<<tmp<<" "<<q1<<"\n";
        		if(q2>0)
        			vec[tr].pb(q2);
        		vec[tr].pb(tmp-q2+1);
        		vec[tr].pb(q1-tmp);
        		if(n-1-q1>0)
        			vec[tr].pb(n-q1-1);
        		vector <int> v1;
        		for(int j=q1+1;j<n;j++)
        			v1.pb(arr[j]);
        		for(int j=tmp+1;j<=q1;j++)
        			v1.pb(arr[j]);
        		for(int j=q2;j<=tmp;j++)
        			v1.pb(arr[j]);
        		for(int j=0;j<q2;j++)
        			v1.pb(arr[j]);
        		for(int j=0;j<n;j++)
        			arr[j] = v1[j];
        		break;
        	}
        	tr++;
        }
        cout<<tr<<"\n";
        for(int i=0;i<tr;i++){
        	cout<<sz(vec[i])<<" ";
        	for(int j=0;j<sz(vec[i]);j++){
        		cout<<vec[i][j]<<" ";
        	}
        	cout<<"\n";
        }
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

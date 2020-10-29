https://www.spoj.com/problems/KQUERYO/

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
const int N=30005;
// global variables...
int n;
int arr[N];
vector <int> sgt[4*N];


//functions...
void input(){
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
}

vector <int> merge(vector <int> &v1, vector <int> &v2){
    int len1 = sz(v1);
    int len2 = sz(v2);
    int i1 = 0, i2 = 0;
    vector <int> v3;
    while(i1<len1 and i2<len2){
        if(v1[i1]<=v2[i2]){
            v3.pb(v1[i1]);
            i1++;
        }
        else{
            v3.pb(v2[i2]);
            i2++;
        }
    }
    while(i1<len1){
        v3.pb(v1[i1]);
        i1++;
    }
    while(i2<len2){
        v3.pb(v2[i2]);
        i2++;
    }
    return v3;
}

void build(int idx, int start, int end){
    // cout<<idx<<" "<<start<<" "<<end<<"\n";
    if(start==end){
        sgt[idx].pb(arr[start]);
        return;
    }
    int mid = (start+end)/2;
    build(2*idx+1, start, mid);
    build(2*idx+2, mid+1, end);
    sgt[idx] = merge(sgt[2*idx+1], sgt[2*idx+2]);
}

int query(int idx, int start, int end, int l, int r, int k){
    if(l>end or r<start)
        return 0;
    if(start>=l and end<=r)
        return (sz(sgt[idx]) - (upper_bound(all(sgt[idx]), k) - sgt[idx].begin()));
    int mid = (start+end)/2;
    int q1 = query(2*idx+1, start, mid, l, r, k);
    int q2 = query(2*idx+2, mid+1, end, l, r, k);
    return q1+q2;
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
        build(0, 0, n-1);
        int q;
        cin>>q;
        int lastans = 0;
        while(q--){
            int l, r, k;
            cin>>l>>r>>k;
            l = lastans^l;
            r = lastans^r;
            k = lastans^k;
            
            if(l<1)
                l = 1;
            if(r>n)
                r = n;
            // cout<<l<<r<<k<<"\n";
            if(l>r){
                lastans = 0;
                cout<<lastans<<"\n";
                continue;
            }
            lastans = query(0, 0, n-1, l-1, r-1, k);
            cout<<lastans<<"\n";
        }
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

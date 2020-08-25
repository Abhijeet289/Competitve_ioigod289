#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
// #define int long long int
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
int n, q, sqlen = sqrt(N) + 1;
long long int cur = 0;
int arr[N], freq[10*N];
long long int ans[N];

struct stt1{
    int l, r, idx;
};

struct stt1 que[N];

//functions...
void input(){
    cin>>n>>q;
    sqlen = sqrt(n) + 1;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<=q;i++){
        int q1, q2;
        cin>>q1>>q2;
        que[i].l = q1;
        que[i].r = q2;
        que[i].idx = i;
    }
}

bool cmp(struct stt1 &a, struct stt1 &b){
    int b1 = a.l/sqlen;
    int b2 = b.l/sqlen;
    if(b1!=b2)
        return b1<b2;
    else{
        if(b1&1)
            return a.r<b.r;
        else
            return a.r>b.r;
    }
}

inline void add(int idx){
    cur-=(1LL*freq[idx]*freq[idx]*idx);
    freq[idx]++;
    cur+=(1LL*freq[idx]*freq[idx]*idx);
}

inline void remove(int idx){
    cur-=(1LL*freq[idx]*freq[idx]*idx);
    freq[idx]--;
    cur+=(1LL*freq[idx]*freq[idx]*idx);
}

void mo(){
    sort(que+1, que+1+q, cmp);
    int le = 1;
    int ri = 0;
    cur = 0;
    for(int i=1;i<=q;i++){
        while(le<que[i].l)
            remove(arr[le++]);
        while(le>que[i].l)
            add(arr[--le]);
        while(ri<que[i].r)
            add(arr[++ri]);
        while(ri>que[i].r)
            remove(arr[ri--]);
        ans[que[i].idx] = cur;
    }
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
    // cin>>test;
    while(test--){
        input();
        mo();
        for(int i=1;i<=q;i++)
            cout<<ans[i]<<"\n";

    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
}

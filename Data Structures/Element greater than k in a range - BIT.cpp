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
int n, q;
int arr[N], que[N][3], BIT[2*N];
struct abhi{
    int pos;
    int lp;
    int rp;
    int val;
};
abhi brr[2*N];

//functions...
void input(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    cin>>q;
    for(int i=1;i<=q;i++)
        cin>>que[i][0]>>que[i][1]>>que[i][2];
}

bool cmp(abhi a, abhi b){
    if(a.val==b.val)
        return a.lp < b.lp;
    return a.val > b.val;
}

void update(int idx){
    while(idx<=n){
        BIT[idx]++;
        idx += ((idx) & (-idx));
    }
}

int query(int idx){
    int ans = 0;
    while(idx){
        ans += BIT[idx];
        idx -= ((idx) & (-idx));
    }
    return ans;
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
        // filling the array elements
        for(int i=1;i<=n;i++){
            brr[i].pos = 0;
            brr[i].lp = 0;
            brr[i].rp = i;
            brr[i].val = arr[i];
        }

        //filling the query
        for(int i=n+1;i<=n+q;i++){
            brr[i].pos = i-n;
            brr[i].lp = que[i-n][0];
            brr[i].rp = que[i-n][1];
            brr[i].val = que[i-n][2];
        }

        sort(brr+1, brr+n+q+1, cmp);
        for(int i=1;i<=n+q;i++)
            cout<<brr[i].pos<<" "<<brr[i].lp<<" "<<brr[i].rp<<" "<<brr[i].val<<"\n";
        ioi;

        int ans[q+5];
        for(int i=1;i<=n+q;i++){
            if(brr[i].pos==0){
                update(brr[i].rp);
            }
            else{
                ans[brr[i].pos] = query(brr[i].rp) - query(brr[i].lp-1);
            }
        }
        for(int i=1;i<=q;i++)
            cout<<ans[i]<<" ";
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
    return 0;
}

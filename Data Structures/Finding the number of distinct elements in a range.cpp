Approach->
Prerequisites = Familiar with BIT.
Let's understand this with an example.
Array = {1, 2, 5, 1, 5, 7, 8}.
Maintain an array lastOccurence[] initially all set to -1.
Now start traversing the original Array[].
You may come accross two cases:
    - The current element is already present in the array. Then we need to decrease the BITarray from lastOccurence[ele]+1
      till the current index by 1.( This can be easily done in a BIT by update(lastOccurence[arr[i]]+1, -1)) and update(i+1, 1).
    - The current element has ocured for the first time. Then we need to increase the BITarray from beginning till current index. 
Finally answering the queries. Sort the queries according to their right index.
HOW THIS ACTUALLY WORKS??
    - Since you have queries sorted according to right indices, when you answer any query you only account for the recent 
      occurence of that element ignoring all the previous occurences.

IMP links->
https://www.geeksforgeeks.org/queries-number-distinct-elements-subarray/

QUESTION->
Codeforces - Messenger Simulator - https://codeforces.com/problemset/problem/1288/E


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
#define MOD 1000000007
#define mod1 1187278649
#define mod2 1149736019
#define ioi cout<<"\n------------ioi------------\n"
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

const ld PI=3.14159265358979323;
int linf=(int)2e18;
const int inf=1011111111;
const int N=300005;
// global variables...
int n, m, tr=0;
int arr[N], mini[N], maxi[N], bit[3*N], last_visit[3*N];
vector <int> v1, pos[N];

struct query{
    int l;
    int r;
    int idx;
};

vector <query> qrr;

//functions...
void input(){
    cin>>n>>m;
    for(int i=n;i>=1;i--)
        v1.pb(i);
    for(int i=1;i<=m;i++){
        cin>>arr[i];
        v1.pb(arr[i]);
    }
}

void update(int idx, int val){
    for(;idx<=sz(v1);idx+=(idx&-idx))
        bit[idx]+=val;
}

int querybit(int idx){
    int res=0;
    for(;idx>0;idx-=(idx&-idx))
        res+=bit[idx];
    return res;
}

bool cmp(struct query &a, struct query &b){
    if(a.r==b.r)
        return a.l<b.l;
    return a.r<b.r;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int test=1;
    while(test--){
        input();
        for(int i=0;i<sz(v1);i++)
            pos[v1[i]].pb(i);
        int l1=sz(v1);
        for(int i=1;i<=n;i++){
            int l2=sz(pos[i]);
            for(int j=1;j<l2;j++){
                int prev=pos[i][j-1];
                int cur=pos[i][j];
                if(cur==prev+1)
                    continue;
                struct query q1;
                q1.l=prev+1;
                q1.r=cur-1;
                q1.idx=i;
                qrr.pb(q1);
            }
            if(pos[i][l2-1]==l1-1)
                continue;
            struct query q1;
            q1.l=pos[i][l2-1]+1;
            q1.r=l1-1;
            q1.idx=i;
            qrr.pb(q1);
        }
        // let's find the minimum position for each person.
        for(int i=1;i<=n;i++)
            mini[i]=i;
        for(int i=1;i<=m;i++)
            mini[arr[i]]=1;

        // now its time for maximum position for each item.
        for(int i=1;i<=n;i++)
            maxi[i]=i;
        sort(all(qrr), cmp);
        memset(bit, 0, sizeof bit);
        memset(last_visit, -1, sizeof last_visit);
        int l3=sz(qrr);
        int qct=0;
        for(int i=0;i<sz(v1);i++){
            if(last_visit[v1[i]]!=-1){
                update(last_visit[v1[i]]+1, -1);
            }
            last_visit[v1[i]]=i;
            update(i+1, 1);
            while(qct<l3 and qrr[qct].r==i){
                int tmp1=querybit(qrr[qct].r)-querybit(qrr[qct].l-1);
                maxi[qrr[qct].idx]=max(maxi[qrr[qct].idx], tmp1+1);
                qct++;
            }
        }
        for(int i=1;i<=n;i++)
            cout<<mini[i]<<" "<<maxi[i]<<"\n";
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
}

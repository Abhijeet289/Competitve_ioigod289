// 28
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
const int N=200005;
// global variables...

vector < vector <int> > matmul(vector < vector <int> > mat1, vector <vector <int> > mat2, int m){
    vector < vector <int> > ans(m);
    for(int i=0;i<m;i++)
        ans[i].resize(m, 0);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            // here we compute the value of element [i][j].
            // ith row and jth column.
            for(int k=0;k<m;k++){
                ans[i][j] = (ans[i][j] + (mat1[i][k]*mat2[k][j])%MOD)%MOD;
            }
        }
    }
    return ans;
}

vector < vector <int> > powmat(int n, int m, vector < vector <int> > mat){
    vector < vector <int> > ans(m); // identity matrix.
    for(int i=0;i<m;i++){
        ans[i].resize(m, 0);
        ans[i][i] = 1;
    }
    // below is normal binary exponentiation
    while(n>0){
        if(n&1){
            ans = matmul(ans, mat, m);
        }
        mat = matmul(mat, mat, m);
        n/=2;
    }
    return ans;
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
        int n, m;
        cin>>n>>m;
        if(m>n){
            cout<<"1\n";
            continue;
        }
        vector < vector <int> > mat(m);
        for(int i=0;i<m;i++){
            mat[i].resize(m, 0);
            if(i==0)
                mat[i][0] = mat[i][m-1] = 1;
            else
                mat[i][i-1] = 1;
        }
        vector < vector <int> > ans = powmat(n-m+1, m, mat);
        int finans = 0;
        for(int i=0;i<m;i++)
            finans = (finans + ans[0][i])%MOD;
        cout<<finans<<"\n";
    }
    cerr<< '\n' << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms\n" ;
}

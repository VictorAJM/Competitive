
// Hasta donde tope

#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second
#define wh while
#define re return
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define watch(x) cerr<<(#x)<<"="<<(x)<<'\n'
#define forn(i,a,b) for(int i=(a);i<(b);i++)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define rofn(i,a,b) for (int i=(a);i>(b);i--) 
#define rofe(i,a,b) for (int i=(a);i>=(b);i--)

using namespace std;

typedef long long ll;
typedef pair<int,int> i2;
typedef vector<int> vi;
typedef vector<i2> vi2;
typedef vector<ll> vl;
typedef pair<ll,ll> l2;
typedef long double ld;

const int mod=0;
const int N=1e6+5;
const ld EPS = 1e-9;

void precalc()
{

}
int n,m,idk[N],f[N],q;
void solve(int Case)
{
    cin >> n >> m;
    vector<vector<char> > mat(n,vector<char>(m) );
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) cin >> mat[i][j];
    for (int j=0;j<m-1;j++) {
        for (int i=1;i<n;i++) {
            if (mat[i][j] == 'X' && mat[i-1][j+1] =='X') idk[j+1] = 1;
        }
    }
    cin >> q;
    for (int j=1;j<m;j++) f[j] = idk[j] + f[j-1];
    for (int i=0;i<q;i++) {
        int x,y;
        cin >> x >> y;
        x--; y--;
            if (f[y] - f[x] == 0) cout << "YES\n";
            else cout << "NO\n";
    }
}
int main()
{
    fast_io;
    precalc();
    int tt = 1, Case = 0;
    // cin >> tt;
    while (tt--) solve(++Case);
    return 0;
}

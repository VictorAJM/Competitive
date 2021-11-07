
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
const int N=1e5+5;
const ld EPS = 1e-9;
int n,m,a[N],b[N],c[N];
bool vs[N];
void precalc()
{

}
void solve(int Case)
{
    cin >> n >> m;
    for (int i=0;i<m;i++) cin >> a[i] >> b[i] >> c[i];
    for (int i=1;i<=n;i++) vs[i] =  false;
    for (int i=0;i<m;i++) vs[b[i]] = true;
    for (int i=1;i<=n;i++) if (!vs[i]) {
        for (int j=1;j<=n;j++) if (j != i) cout << j << " "<<i<<"\n";
        return;
    }
}
int main()
{
    fast_io;
    precalc();
    int tt = 1, Case = 0;
    cin >> tt;
    while (tt--) solve(++Case);
    return 0;
}

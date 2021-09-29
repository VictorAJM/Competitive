// Problem: B. Combinatorics Homework
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define mset(d,val) memset(d,val,sizeof(d))
#define forn(i,a,b) for(int i=(a);i<(b);i++)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define setp(x,a) cout<<fixed<<setprecision(x)<<a

#define TEST int tt,Case=0; cin >> tt; wh (tt--) solve(++Case); 
#define ALL(n) int Case=0; wh (cin >> n) solve(++Case);
#define ONLYONE int Case=0; solve(++Case);

using namespace std;

typedef long long ll;
typedef pair<int,int> i2;
typedef vector<int> vi;
typedef vector<i2> vii;
typedef vector<ll> vl;
typedef pair<ll,ll> l2;
typedef long double ld;

const int mod=0;
const int N=0;
const ld EPS = 1e-9;

int n,a,b,c,d;

void solve(int Case)
{
    cin >> a >> b >> c >> d;
    n = a+b+c-3;
    if (d > n) { cout << "NO\n"; re;}
    int x = min(min(a,b),c);
    
    if (b<c) swap(b,c);
    if (a<b) swap(a,b);
    if (b<c) swap(b,c);
    watch(a);
	watch(b);
	watch(c);
    if (a > b+c) {
    	if (d < a-b-c-1) { cout << "NO\n"; re;}
    }
    cout << "YES\n";
    re;
}

int main()
{
    fast_io;
    // ONLYONE
    TEST;
    // ALL(n);
    return 0;
}

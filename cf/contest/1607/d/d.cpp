
// Hasta donde tope

                                            
//    _____  _                  _           
//   /  __ \| |                | |          
//   | /  \/| |__    __ _  ___ | | __  __ _ 
//   | |    | '_ \  / _` |/ __|| |/ / / _` |
//   | \__/\| | | || (_| |\__ \|   < | (_| |
//    \____/|_| |_| \__,_||___/|_|\_\ \__,_|
//                                            
//                                            

#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define watch(x) cerr<<(#x)<<"="<<(x)<<'\n'
#define forn(i,a,b) for(int i=(a);i<(b);i++)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define rofn(i,a,b) for (int i=(a);i>(b);i--) 
#define rofe(i,a,b) for (int i=(a);i>=(b);i--)
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int> i2;
typedef vector<int> vi;

const int mod=0;
const int N=2e5+5;

void precalc()
{

}
int n,a[N];
string s;
vector<int> q,w;
void solve(int Case)
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    cin >> s;
    q.clear(); w.clear();
    for (int i=0;i<n;i++) {
        if (s[i] == 'B') {
            q.pb(a[i]);
        } else {
            w.pb(a[i]);
        }
    }
    sort(all(q));
    sort(all(w));
    for (int i=0;i<q.size();i++) {
        if (q[i]<=i) {
            cout << "NO\n";
            return;
        }
    }
    int p=n;
    for (int i=w.size()-1;i>=0;i--) {
        if (w[i]>p) {
            cout << "NO\n";
            return;
        }
        p--;
    }
    cout << "YES\n";
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

#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=2e5+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n,a,b,k;
char s[N];
vii g;
int cnt;
void solve()
{
    cin >> n >> a >> b >> k;
    for (int i=0;i<n;i++) cin >> s[i];
    int _i=0;
    while (_i < n) {
        while (_i < n && s[_i] == '1') _i++;
        if (_i == n) continue;
        int x = _i;
        int y = x;
        while (_i < n && s[_i] == '0') _i++;
        if (_i == n) { y = n-1;if (y-x+1 >= b) g.push_back({x,y});}
        else {y = _i-1;
        if (y-x+1 >= b) g.push_back({x,y});}
        cerr << _i <<"\n";
    }
    for (ii u : g) {
        int p = u.S-u.F+1;
        p /= (b);
        cnt += p;
    }
    for (ii u : g) cerr << u.F << " "<<u.S <<"\n";
    vi res;
    for (ii u : g) {
        while (u.S-u.F+1 >= b && cnt >= a) {
            cnt--;
            s[u.F+b-1] ='1';
            res.push_back(u.F+b-1);
            u.F += b;
        }
    }
    cout << res.size() <<"\n";
    for (int u : res) cout << u+1 << " ";
}

int main()
{
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

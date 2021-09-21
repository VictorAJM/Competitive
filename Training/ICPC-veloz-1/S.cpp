#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=2e4+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n,a[N],b[N];
vi g,h;
void solve()
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) cin >> b[i];
    g.clear(); h.clear();
    for (int i=0;i<n;i++) {
        while (a[i] > b[i]) { g.push_back(i); a[i]--;}
        while (a[i] < b[i]) { h.push_back(i); a[i]++;}
    }
    if (g.size() != h.size()) cout << "-1\n";
    else {
        cout << g.size() << "\n";
        for (int i=0;i<g.size();i++) cout << g[i]+1 << " "<<h[i]+1<<"\n";
    }
}

int main()
{
    fast_io;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

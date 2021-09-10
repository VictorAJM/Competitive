#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=4e5+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int x,y,a[N];
void solve()
{
    cin >> x >> y;
    int p = a[x-1];
    int q = p^y;
    //cerr << q << " ";
    if (p==y) cout << x << "\n";
    else if (q != x) cout << x+1 << "\n";
    else cout << x+2 <<"\n";
}

int main()
{
    fast_io;
    int t = 1;
    cin >> t;
    for (int i=1;i<=3e5;i++) {
        a[i] = a[i-1]^i;
    }
    while (t--) {
        solve();
    }
    return 0;
}

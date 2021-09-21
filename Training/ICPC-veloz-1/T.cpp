#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=0;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

void solve()
{
    int n;
    int a;
    int cnt = 0;
    cin >> n;
    for (int i=0;i<n+n;i++) {
        cin >> a;
        if (a%2==1) cnt++;
    }
    if (cnt == n) cout << "Yes\n";
    else cout << "No\n";
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

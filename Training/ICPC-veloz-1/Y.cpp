#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=550;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n,a[N];
void solve()
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    int cnt = 0;
    for (int i=0;i<n;i++) cnt += a[i];
    if (cnt < n ) cout << "1\n";
    else if (cnt ==n) cout << "0\n";
    else cout << cnt-n<<"\n";
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

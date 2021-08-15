#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=106;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n,a[N];
void solve()
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) a[0] &= a[i];
    cout << a[0] << "\n";
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

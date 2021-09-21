#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=10005;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
int n,a[N];
void solve()
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) if (a[i]<0) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    int x = *max_element(a,a+n);
    cout << x+1 << "\n";
    for (int i=0;i<=x;i++) cout << i << " ";
    cout << "\n";
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

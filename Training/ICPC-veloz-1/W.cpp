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
int n,a[N];
void solve()
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    int x = max_element(a,a+n) - a;
    int y = min_element(a,a+n) - a;
    cerr << x << " " << y << "\n";
    int A = min(x,y)+1 + n - max(x,y);
    int B = max(x,y)+1;
    int C = n - min(x,y);
    A = min(min(A,B),C);
    cout << A << "\n";
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

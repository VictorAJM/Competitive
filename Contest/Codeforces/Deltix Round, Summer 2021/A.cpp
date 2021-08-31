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
    int a,b;
    cin >> a >> b;
    if (a==b && b==0) cout << "0\n";
    else if (a==b) cout << "1\n";
    else if ((a-b)%2==0) cout << "2\n";
    else cout <<"-1\n";
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

#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second

using namespace std;

const int mod=0;
const int N=1e5+5;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
bool dat[N];
int b[N],a[N];
void solve()
{
	ll n;
	cin >> n;
	for (int i=0;i<n;i++) 
		cin >> a[i];
	for (int i=0;i<n;i++) b[a[i]] = i;
	for (int i=n;i>0;i--) {
		int p = b[i];
		bool ty = false;
		bool tx = false;
		for (int j = p-i;j>=0;j-=i)  {
			if (a[j] > i) {
				if (!dat[j]) ty = true;
				else tx = true;
			}
		}
		for (int j = p+i;j<n;j+=i)  {
			if (a[j] > i) {
				if (!dat[j]) ty = true;
				else tx = true;
			}
		}
		dat[p] = ty;
		cerr << ty << " ";
	}

	for (int i=0;i<n;i++) {
		if (dat[i]) cout << "A";
		else cout << "B";
	}
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

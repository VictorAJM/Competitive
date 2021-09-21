// Problem: D. Pair Of Lines
// Contest: Codeforces - Educational Codeforces Round 41 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/961/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define fast_io cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
#define F first
#define S second
#define EPS 1e-9
using namespace std;

const int mod=0;
const int N=2e5+5;

typedef vector<int> vi;
typedef long long ll;

ll n,a[N],b[N];
bool vs[N];


struct point {
	double x,y;
	point() { x = y = 0;}
	point(double _x,double _y) : x(_x), y(_y) {}
	bool operator < (point other) const {
		if (fabs(x-other.x) > EPS) 
			return x < other.x;
		return y < other.y;
	}
	bool operator > (point other) const {
		if (fabs(x-other.x) > EPS) 
			return x > other.x;
		return y > other.y;
	}
	bool operator == (const point &other) const {
		return (fabs(x-other.x) < EPS && fabs(y-other.y) < EPS);
	}
	point operator - (const point &b) const {
		point pt;
		pt.x = this->x - b.x;
		pt.y = this->y - b.y;
		return pt;
	}
	point operator + (const point &b) const {
		point pt;
		pt.x = this->x + b.x;
		pt.y = this->y + b.y;
		return pt;
	}
	point operator = (const point &b) const {
		point pt;
		pt.x = b.x;
		pt.y = b.y;
		return pt;
	} 
	ll operator * (const point &b) const {
		point pt;
		pt.x = this->x*b.y;
		pt.y = this->y*b.x;
		return pt.x-pt.y;
	}
} pt[N];



bool P(int q,int w)
{
	for (int i=0;i<n;i++) vs[i] = false;
	vs[q] = vs[w] = true;
	for (int i=0;i<n;i++) {
		point a = pt[q] - pt[w];
		point b = pt[i] - pt[w];
		if (a*b == 0) vs[i] = true;
	}
	vi g;
	for (int i=0;i<n;i++) if (!vs[i]) g.push_back(i);
	if (g.size() <= 2) return true;
	for (int i=2;i<(int)g.size();i++) {
		point a = pt[g[0]] - pt[g[1]];
		point b = pt[g[i]] - pt[g[0]];
		if (fabs(a*b) > EPS) return false;
	}
	return true;
}
void solve()
{
	cin >> n;
	for (int i=0;i<n;i++) cin >> a[i] >> b[i];
	for (int i=0;i<n;i++) {
		pt[i].x = a[i];
		pt[i].y = b[i];
	}
	if (n <= 3) cout << "YES\n";
	else if (P(0,1)) cout << "YES\n";
	else if (P(0,2)) cout << "YES\n";
	else if (P(1,2)) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}

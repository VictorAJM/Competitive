#include <bits/stdc++.h>
#define F first
#define S second
#define watch(x) cerr << #x << " " << x << "\n";
#define sz(a) (int)a.size()

using namespace std;

const int MOD = 0;
const int N = 0;

typedef long long ll;
typedef pair<int,int> i2;
typedef vector<int> vi;
typedef vector<i2> vi2;

void solve()
{
    string s;
    int n;
    cin >> s;
    n = s.size();
    int a = n-1;
    int b,c,d;
    b=c=d=a;
       while (a>=0 &&s[a]!='5') a--;
    a--;
    while (a>=0&&s[a]!='2')a--;
   while (b>=0 &&s[b]!='5') b--;
    b--;
    while (b>=0&&s[b]!='7')b--;
   while (c>=0 &&s[c]!='0') c--;
    c--;
    while (c>=0&&s[c]!='5')c--;
   while (d>=0 &&s[d]!='0') d--;
    d--;
    while (d>=0&&s[d]!='0')d--;
    a = max({a,b,c,d});
    cout << n - (a+2) << "\n";
}

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)  solve();
    return 0;
}

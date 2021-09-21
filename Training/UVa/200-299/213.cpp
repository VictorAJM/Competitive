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
string s;
char h[7][1005];
int P(int u)
{
    int rs=0;
    while (u>0) {
        if (u%2==1) rs++;
        u /= 2;
    }
    return rs;
}
bool t=false;
void solve()
{
    int tm,p;
    tm = 1;
    p=0;
    for (auto u : s) {
        h[tm][p] = u;
        p++;
        if (P(p)==tm) {
            p = 0;
            tm++;
        }
    }
    char a,b,c;
    int sum =0;
    if (t) cout << "\n";
    t = true;
    do {
        cin >> a >> b >> c;
        a -= '0'; b -= '0'; c -= '0';
        sum = a*4 + b*2 + c;
        int pp = 0;
        do {
            pp = 0;
            int pa = 0;
            char x;
            for (int i=0;i<sum;i++) {
                cin >> x;
                pa *= 2;
                pa += x - '0';
                if (x=='1') pp++;
            }
           if (pp < sum) cout << h[sum][pa];
        } while (pp < sum);
    } while (sum > 0);
    getline(cin,s);
}

int main()
{
    fast_io;
    while (getline(cin,s)) {
        solve();
    }
    return 0;
}

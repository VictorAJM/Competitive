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
ll n,a[N],x,y,cnt;
ll par()
{
    vector<int> ojo;
    for (int i=0;i<n;i++) if (a[i]==0) ojo.push_back(i);
    int k=0; ll res=0;
    for (int i=0;i<n;i+=2) {
        res += abs(ojo[k]-i);
        k++;
    }
    return res;
}
ll impar()
{
    vector<int> ojo;
    for (int i=0;i<n;i++) if (a[i]==1) ojo.push_back(i);
    int k=0; ll res=0;
    for (int i=0;i<n;i+=2) {
        res += abs(ojo[k++]-i);
    }
    return res;
}
void solve()
{
    cin >> n;
    for (int i=0;i<n;i++) cin >> a[i];
    for (int i=0;i<n;i++) a[i]  %= 2;
    x=y=0;
    for (int i=0;i<n;i++) if (a[i]==1) y++; else x++;
    if (n%2==1) {
        if (x > n/2 + 1 || y > n/2 + 1) {
            cout <<"-1\n";
            return ;
        }
        ll p1;
        if (x == n/2 + 1) {
            p1 = par();
        } else {
            p1 = impar();
        } 
        cout << p1 << "\n";
    } else {
        if (x > n/2 || y> n/2) {
            cout << "-1\n";
            return ;
        }
        ll p1 =par();
        ll p2 = impar();
        p1 = min(p1,p2);
                    cout << p1<<"\n";
    }
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

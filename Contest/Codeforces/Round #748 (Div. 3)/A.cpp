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



int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t,a,b,c,x;
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        x = max(b,c);
        if (a>x) cout << "0";
        else cout << x-a+1;
        cout << " ";
        x = max(a,c); 
        if (b>x) cout << "0";
        else cout << x-b+1;
        cout << " ";
            x = max(a,b);
        if (c>x) cout << "0";
        else cout << x-c+1;
        cout << "\n";
    }
    return 0;
}

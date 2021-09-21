#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a,b;
	cin >> a >> b;
	for (int i=0;i<a.size();i++) {
		a[i] = tolower(a[i]);
	}
	for (int i=0;i<b.size();i++) {
		b[i] = tolower(b[i]);
	}
	for (int i=0;i<b.size();i++) {
		if (a[i] == b[i]) continue;
		else {
			if (a[i] > b[i]) cout << "1\n";
			else cout << "-1\n";
			return 0;
		}
	}
	cout << "0";
	return 0;
}


// Hasta donde tope

#include <bits/stdc++.h>

using namespace std;

int ExtEuclid(int a,int b,int &x,int &y)
{
	int xx = y = 0;
	int yy = x = 1;
	while (b) {
		int q = a/b;
		int t = b; b = a%b; a = t;

		t = xx; xx = x - q*xx; x = t;
		t = yy; yy = y - q*yy; y = t;
	}
	return a;
}
int modInverse(int b,int m)
{
	int x,y;
	int d = ExtEuclid(b,m,x,y); // b*x + m *y = d
	if (d != 1) return -1; // Falla
	// b*x + m*y = 1, usando modulo m, b*x = 1, x es inverso de b
	return ((x%m)+m)%m;
}
int main()
{
	int x=0,y=0;
	cout << ExtEuclid(25,18,x,y) << "\n";
	cout << modInverse(4,7) << "\n";
}


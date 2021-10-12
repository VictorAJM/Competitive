#include <bits/stdc++.h>
using namespace std;

int main()
{
	int casos,n;
	cin >> casos;
	for (;casos>0;casos--) {
		cin >> n;
		int cont = 0;
		while (n != 495) {
			cont++;
			int x = 0,y=0;
			int a=0,b=0,c=0;
			int z;
			z = n;
			a = z%10; z/= 10;
			b = z%10; z /= 10;
			c = z%10; 
			if (a>b) {
				b += a;
				a = b-a;
				b -= a;
			}
			if (b > c) {
				c += b;
				b = c-b;
				c -= b;
			}
			if (a>b) {
				b += a;
				a = b-a;
				b -= a;
			}
			x = 100*a+10*b+1*c;
			y = 100*c+10*b+1*a;
			n = y-x;
		}
		cout << cont<< "\n";
	}
}
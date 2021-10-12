#include <stdio.h>

int main()
{
    char a[105],b[105],c[105];
    gets(a); gets(b); gets(c);
    if (isNumeric(a)) printf("Hi");
	return 0;
}
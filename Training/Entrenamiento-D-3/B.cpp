#include <stdio.h>
#include <string.h>
void intercambia(char *u , char *v) 
{
    char aux = *u;
    *u = *v;
    *v = aux;
    return;
}
void ordena(char* b)
{
    int n = strlen(b);
    for (int j=0;j<n;j++)
    for (int i=0;i<n-1;i++) {
    	if (b[i] > b[i+1])
        intercambia(&b[i],&b[i+1]);
    }
	return;
}
void reverse(char *c,int u,int v)
{
	int p = (u+v)/2;
	for (;u<=p;u++,v--) {
		intercambia(&c[u],&c[v]);
	}
}
int nextP(char* b,int u,int v)
{
	if (u==v) return 0;
	int i = v-1;
	while (1) {
		int p,q;
		p = i;
		if (i > 0 && b[--i] < b[p]) {
			q = v;
			while (!(b[i] < b[--q]));
			intercambia(&b[i],&b[q]);
			reverse(b,p,v-1);
			return 1;
		}
		if (i == 0) {
			reverse(b,u,v-1);
			return 0;
		}
	}
}
int cnt=0;
int main(){
    char a[15];
    gets(a);
    ordena(a);
    int n = strlen(a);
    do {
    	char *dd;
    	strcpy(dd,a);
    	printf("%s\n",dd);

    } while (nextP(a,0,n)==1);
    return 0;
}   
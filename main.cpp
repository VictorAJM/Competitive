#include <stdio.h>
#include <algorithm>
using namespace std;
int N,q;
char B[2000000];
long long C,D,M,L;
int K(int w)
{
    D=0;
    while (B[w]=='1') {
        D++;
        w++;
    }
    return D+1;
}
int J(int w)
{
    D=1;
    while (B[w]=='0') {
        D++;
        w++;
    }
    if (w==N-1) {
        D++;
    }
    return D;
}
int main()
{
    scanf("%d",&N);
    scanf("%c",&B[0]);
    for (int i=0;i<N;i++) scanf("%c",&B[i]);
    for (int i=0;i<N/2;i++) swap(B[i],B[N-1-i]);

    while (q<N-1) {
        if (B[q]=='0') {
            C++;
            q++;
        } else {
            M=K(q+1);
            L=J(q+1);
            if (M>L) {
                D=q;
                while (B[D]=='1') {
                    B[D]='0';
                    D++;
                }
                B[D]='1';
                if (D>=N) N++;
            } else {
                B[q]='0';
            }
            C++;
        }
    }
    printf("%lld",C);
    return 0;
}
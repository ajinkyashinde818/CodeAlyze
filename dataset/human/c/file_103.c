#include <stdio.h>
#include <stdlib.h>

int main (void){
long long int A,B,C,N,ans=0,tmp;
scanf("%lld %lld %lld %lld",&A,&B,&C,&N);
if (A<B) {
  tmp=A;
  A=B;
  B=tmp;
}
if (B<C) {
  tmp=B;
  B=C;
  C=tmp;
}
if (A<B) {
  tmp=A;
  A=B;
  B=tmp;
}
for (int a = 0; a*A <= N; a++) {
  for (int b = 0; (a*A+b*B) <= N; b++) {
    if ((N-(a*A+b*B))%C==0) {
    ans++;
    //printf("%lld,%lld\n",a,b );
    }
  }
}
printf("%lld\n",ans );
        return 0;
}

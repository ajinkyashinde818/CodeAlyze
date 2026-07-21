#include <stdio.h>

int main(){
int a, b, c, d;
int s1, s2;
scanf("%d%d%d%d",&a,&b,&c,&d);
s1 = a*b;
s2 = c*d;

if(s1>s2) printf("%d", s1);
if(s1<=s2) printf("%d", s2);

return 0;
}

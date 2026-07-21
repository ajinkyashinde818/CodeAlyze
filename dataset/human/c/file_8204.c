#include <stdio.h>
int main(){
int a,b,c,d;
scanf("%d%d%d%d",&a,&b,&c,&d);

int e,f;
e=a*b;
f=c*d;

if(e==f) printf("%d",e);
else
if(e<f)  printf("%d",f);
else
if(e>f)  printf("%d",e);


return 0;
}

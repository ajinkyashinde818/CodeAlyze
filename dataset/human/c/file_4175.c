#include <stdio.h>
int main (){
int a,b,i,k,s[100]={0},d=0;
  scanf ("%d%d%d",&a,&b,&k);
  for (i=1;i<a*b;i++){
if (a%i==0 && b%i==0){
s[d]=i;
d++;
}
  }
printf ("%d",s[d-k]);
return 0;
}

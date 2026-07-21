#include <stdio.h>

int main (void){
 int n,b,d,Ans=-2147483648;
 scanf("%d",&n);
 scanf("%d",&b);

  for(int i=1;i<n;i++){
 scanf("%d",&d);
 if(d-b>Ans){
 Ans=d-b;
}
if(d-b<0){
b=d;
}

}
printf("%d\n",Ans);

return 0;

}

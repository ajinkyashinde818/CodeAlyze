#include<stdio.h>
int main (void){
int a,i;
i=1;
while(i<=10000){
  scanf("%d",&a);
  if( a==0 ){
    printf("Case %d: %d\n",i,a);
  i=10001;
}
  else{
    printf("Case %d: %d\n",i,a);
  i=i+1;
}
}
return 0;



}

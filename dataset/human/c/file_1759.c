#include<stdio.h>
 
int main(){
  int n,i,j,k,sum=0;
  scanf("%d",&n);
  int a[n+1];//+1しとく
  int b[n+1];
  int c[n];
  
  for(i=1;i<=n;i++){
    scanf("%d",&a[i]);}
  
    for(i=1;i<=n;i++){
      scanf("%d",&j);
      b[i]=j;
      sum+=j;}
  
  for(i=1;i<n;i++){
    scanf("%d",&c[i]);}
  
      for(i=1;i<n;i++){
      	if(a[i]==a[i+1]-1)//そしたらエラー出ない
          sum+=c[a[i]];//ここが鬼門
      }
  
	printf("%d\n",sum);
 
 
return 0;}

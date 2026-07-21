#include<stdio.h>
int main(void){
  int n,d,x,a[100],i,j;
  scanf("%d",&n);
  scanf("%d %d",&d,&x);
  int sum=x;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    for(j=0;j<d;j++){
      if(j*a[i]+1<=d)
    	sum++;
      else
        break;
    }
  }
  printf("%d\n",sum);
  return 0;
}

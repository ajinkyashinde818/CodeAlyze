#include <stdio.h>
int main(){
  int n,i,count=0;
  int a[100000],arrive[100000]={0};

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  i=0;
  while(i!=1){
    count++;
	arrive[i]++;
    i=a[i]-1;
    if(arrive[i]>0){
      printf("-1");
      return 0;
    }
  }
  printf("%d",count);
}

#include<stdio.h>
int main(){
  int i,j,k,n;
  int a[10000],b[10000];
  //printf("a\n");
  a[0]=2;
  a[1]=3;
  for(i=2;i<10000;i++){
    for(j=a[i-1]+2;;j+=2){
      for(k=i-1;k>=0;k--){
	//printf("k%d",);
	if(j%a[k]==0)break;
      }
      if(k==-1)break;
    }
    a[i]=j;
    //printf("\n%d\n",a[i]);  
  }
  b[0]=2;
  for(i=1;i<10000;i++){
    b[i]=b[i-1]+a[i];
  }
  //printf("a\n");
  while(1){
    scanf("%d",&n);
    if(n==0)break;
    printf("%d\n",b[n-1]);
  }
  return 0;
}

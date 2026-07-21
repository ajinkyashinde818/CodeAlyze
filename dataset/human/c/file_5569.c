#include <stdio.h>

int main(void){
  int i,j,prm[1000000];
  
  for(i=0;i<1000000;i++) prm[i]=1;
  for(i=4;i<1000000;i+=2) prm[i]=0;
  prm[0]=0;
  prm[1]=0;
  for(i=3;i*i<1000000;i+=2){
    if(prm[i]==1){
      for(j=i+i;j<1000000;j+=i) prm[j]=0;
    }
  }
  
  int n;
  while((scanf("%d",&n))!=EOF){
    if(n==0)  break;
    else{
      int i=0,j=0;
      int sum=0;
      while(j<n){
	if(prm[i]==1){
	  j++;
	  sum+=i;
	}
	i++;
      }
      printf("%d\n",sum);
    }
  }
  return 0;
}

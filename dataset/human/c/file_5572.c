#include <stdio.h>
#include <math.h>

int main(void)
{
  int n,i,j,ans,no,cou;

  for(;;){
    scanf("%d", &n);
    if(!n) break;
    if(n==1){
      printf("2\n"); continue;
    }

    ans=2; no=0; cou=1;
    for(i=3;cou<n;i+=2){
      for(j=3;j<sqrt(i)+1;j++){
	if(i%j==0){
	  no=1; break;
	}
      }
      if(!no){
	ans+=i; cou++;
      }
      no=0;
    }
    printf("%d\n", ans);
  }

  return 0;
}

#include<stdio.h>

int main(){
  int n;
  int cnt;

  for(;;){
    scanf("%d",&n);
    if(n==0)
      break;

    cnt=0;
    while(1){
      if(n==1)
	break;
      if(n%2==0)
	n/=2;
      else{
	n*=3;
	n++;
      }
      cnt++;
    }
    printf("%d\n",cnt);
  }
  return 0;
}

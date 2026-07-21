#include <stdio.h>

main(){
  int n,count;

  while(1){
    scanf("%d", &n);
    if(n==0) break;
    count=0;

    while(n!=1){
      if(n%2==0){
	n/=2;
      }
      else{
	n=n*3+1;
      }
      count++;
    }

    printf("%d\n", count);
  }
  return 0;
}

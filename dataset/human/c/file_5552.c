#include <stdio.h>

int main(int argc, char *argv[]){
  int comb[1000001];
  int n,i,j;

  for(i = 2;i < 1000001;i++){
    comb[i] = 1;
  }

  comb[1] = comb[0] = 0;

  for(i = 2;i < 1001;i++){

    if(comb[i] == 0){continue;}
    
    for(j = 2;(j*i) < 1000001; j++){
      comb[j*i] = 0;
    }
  }

  while(scanf("%d",&n) != EOF){
    int sum = 0,count = 0;
    if(n == 0){break;}
    
    for(i = 2;i <= 1000000;i++){
      if(comb[i] == 1){
	count++;
	sum += i;
	if(count == n){
	  break;
	}
      }
    }

    printf("%d\n",sum);
    
  }
  
  
  return 0;    
}

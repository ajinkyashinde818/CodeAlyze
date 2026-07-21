#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 2000000
#define Gard -1000000000

int main(){
  int loop;
  int i;
  int Profits[N];
  int minPro,maxPro;
  int start=1;

  scanf("%d",&loop);

  for(i=0;i<loop;i++){
    scanf("%d",&Profits[i]);
  }

  maxPro=Gard;
  minPro=Profits[0];

  while(1){
    if(start==loop){
      break;
    }
    
    if(maxPro<Profits[start]-minPro){
      maxPro=Profits[start]-minPro;
    }
    else{
      maxPro=maxPro;
    }

    if(minPro<Profits[start]){
      minPro=minPro;
    }

    else{
      minPro=Profits[start];
    }

    start++;
  }

  printf("%d\n",maxPro);
  
  return 0;
}

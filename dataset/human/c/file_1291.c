#include <stdio.h>
#include <math.h>
int main(void){
  int p[8],not_ride[8];
  int pat[8][8]={0};
  int n=0,a=0,b=0,c,best,bestIndex,flag=0;
  int capacity[]={4,1,4,1,2,1,2,1};
  int i=0,j;

 
  while(1){
    for(i=0; i<8; i++){
      if(scanf("%d",&p[i])==EOF){
	flag = 1;
	break;
      }
    }
    if(flag)break;
    bestIndex = 0;
   long long int pattern[8] ={0};
  for(i=0; i<8; i++){
    for(j=a ,c =7; j<8+a; j++, c--){
      pattern[i] += capacity[j%8] * (int)pow(10.0,c);
      pat[i][b] = capacity[j%8];
    if(capacity[j%8] < p[b]){
      n += p[b] - capacity[j%8];
    }
    b++;
    }
    a = (j-1) % 8;
    b = 0;
    not_ride[i] = n;
    n = 0;
  }
  best = not_ride[0];
  for(i=1; i<8; i++){
    if(best > not_ride[i]){
      best = not_ride[i];
      bestIndex = i;
    }
    else if(best == not_ride[i]){
      if(pattern[bestIndex] > pattern[i])
	bestIndex = i;
    }
  }
  for(i=0; i<8; i++){
    if(i == 7)
      printf("%d\n",pat[bestIndex][i]);
    else
      printf("%d ",pat[bestIndex][i]);
  }
  }
  return 0;
}

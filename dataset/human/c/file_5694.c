#include<stdio.h>

#define N 200000

int big  (int,int);
int small (int,int);

int main(){
  int R[N];
  int maxv,minv;
  int i,num;

  scanf("%d",&num);

  for(i=0;i<num;i++) scanf("%d",&R[i]);

  maxv = R[1] - R[0];
  minv = R[0];

  for(i=1;i<=num-1;i++){
    maxv = big(maxv,R[i]-minv);
    minv = small(minv,R[i]);
  }

  printf("%d\n",maxv);

  return 0;
}


int big (int a,int b){
  if(a > b) return a;
  else return b;
}


int small (int a,int b){
  if(a > b) return b;
  else return a;
}

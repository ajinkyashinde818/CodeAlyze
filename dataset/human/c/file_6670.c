#include<stdio.h>

#define MAX 200000

int Upper(int x,int y){

  if(x >= y){
    return x;
  }
  return y;
}

int Lower(int x,int y){

  if(x <= y){
    return x;
  }
  return y;
}

int main(){

  int i;
  int r[MAX];
  int num;
  int minv;
  int maxv;

  scanf("%d",&num);

  for(i = 0;i < num;i++){
    scanf("%d",&r[i]);
  }

  minv = r[0];
  maxv = r[1]-r[0];
  for(i = 1;i < num;i++){
    maxv = Upper(maxv,r[i]-minv);
    minv = Lower(minv,r[i]);
  }

  printf("%d\n",maxv);

  return 0;
}

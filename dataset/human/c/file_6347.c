#include<stdio.h>
#include<limits.h>

#define LEN 200000

int max(long long int x,long long int y){
  long long int maxi = x;
  if(y > maxi){
    maxi = y;
  }
  return maxi;
}

int min(long long int x,long long int y){
  long long int mini = x;
  if(y < mini){
    mini = y;
  }
  return mini;
}

int main(){
  int R[LEN],n;

  scanf("%d",&n);
  for(int i = 0; i < n; i++)
    scanf("%d",&R[i]);

  int maxv = -1145141919;
  int minv = R[0];

  for(int i = 1; i < n; i++){
    maxv = max(maxv,R[i] - minv);
    minv = min(minv,R[i]);
  }

  printf("%d\n",maxv);
}

#include <stdio.h>
int max(int a,int b);
int min(int a,int b);
int main(){
  int n,R[200000],i;
  int MIN,MAX;
  scanf("%d",&n);
  scanf("%d %d",&R[0],&R[1]);
  MIN=min(R[0],R[1]);
  MAX=R[1]-R[0];
  for(i=2;i<n;i++){
    scanf("%d",&R[i]);
    MAX=max(MAX,R[i]-MIN);
    MIN=min(MIN,R[i]);
  }
  printf("%d\n",MAX);
  return 0;
}
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
  return a<b?a:b;
}

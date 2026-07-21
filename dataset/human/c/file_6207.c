#include<stdio.h>
# define N 200000
int MB(int , int);
int main(){
  int i,n,hako[N];
  int max,min;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&hako[i]);
      }
  max=-1000000000;
  min = hako[0];
  for(i=1;i<n;i++){
    if(max <=hako[i]-min) max =hako[i]-min;
    if(min>hako[i]) min=hako[i];
    }
  printf("%d\n",max);
  
  return 0;
}

#include <stdio.h>

#define N 200000

int main(){

  int i;
  int j;
  int n;
  int minv;
  int maxv =-2000000000;
  int data[N];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
  }

  minv = data[0];

  for(i=1;i<n;i++){
    if(maxv < data[i]-minv){
      maxv = data[i]-minv;
    }
    if(minv >data[i]){
      minv = data[i];
    }
  }

  printf("%d\n",maxv);
  
  return 0;
}

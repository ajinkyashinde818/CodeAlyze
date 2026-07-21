#include <stdio.h>

long long  A[2000001];
long long min,max,d;
int a;

long long make_min(long long x,long long y){
  if(x>=y) min=y;
  else min=x;
  return min;
}
long long make_max(long long x,long long y){
  if(x<=y) max=y;
  else max=x;
  return max;
}

int main(void) {
  scanf("%d",&a);
  for(int i=0;i<a;i++){
      scanf("%d",&A[i]);
  }

  max=A[1]-A[0];
  min = make_min(A[0],A[1]);

    if(a==2){
      max = A[1]-A[0];
    }
      else{
        for(int i=1;i<a;i++){
            d=A[i+1]-min;
            max= make_max(max,d);
            min = make_min(A[i+1],min);
    }
  }

  printf("%d\n",max);

}

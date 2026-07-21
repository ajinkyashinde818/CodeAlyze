#include <stdio.h>
#include <stdlib.h>

int compare(const void *a,const void *b){
  return *(long *)a - *(long *)b;
}

int main(){
  int n;
  scanf("%d",&n);
  long a[100000];
  int count = 0;
  for(int i=0;i<n;i++){
    scanf("%ld",a+i);
    if(a[i] < 0){
      a[i] = (-1)*a[i];
      count += 1;
    }
  }
  qsort(a,n,sizeof(long),compare);
  long sum=0;
  for(int i=0;i<n;i++){
    sum += a[i];
  }
  if(count % 2 == 1){
    sum -= a[0]*2;
  }
  printf("%ld\n",sum);
  return 0;
}

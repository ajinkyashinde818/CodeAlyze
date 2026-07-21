#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int a,b,k;
  scanf("%d%d%d",&a,&b,&k);
  int i;
  for(i=MAX(a,b);k>0;i--){
    if(a%i==0 && b%i==0){
      k--;
    }
  }
  printf("%d\n",i+1);
}

int main(void){
  run();
  return 0;
}

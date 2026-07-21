#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  int n,d,x;
  scanf("%d%d%d",&n,&d,&x);
  int a[100];
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int cnt=0;
  for(i=0;i<n;i++){
    int t=1;
    while(t<=d){
      cnt++;
      t+=a[i];
    }
  }
  printf("%d\n",cnt+x);
}

int main(void){
  run();
  return 0;
}

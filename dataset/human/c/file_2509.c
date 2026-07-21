#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a,b) ((a)>(0)?(a):-(a))

void run(void){
  int s[3]={0};
  int i;
  for(i=0;i<3;i++){
    char c;
    scanf("%c",&c);
    s[c-'a']++;
  }
  for(i=0;i<3;i++){
    if(s[i]!=1){
      printf("No\n");
      return;
    }
  }
  printf("Yes\n");
  return;
}

int main(void){
  run();
  return 0;
}

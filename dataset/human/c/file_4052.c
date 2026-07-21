#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef long long ll;

int max(int a, int b){
  if(a > b) return a;
  else return b;
}
int min(int a, int b){
  if(a < b) return a;
  else return b;
}

int sort(const void *a ,const void *b){
  return *(int*)a - *(int*)b;
}

int f(int a){
  int count = 0;
  int flag = 0;
  for(int i = 1; i <= pow(a,0.5); ++i){
    if(a % i == 0) count ++;
    if(i*i == a)flag = 1;
  }
  count *= 2;
  if(flag == 1) --count;
  return count;
}


int main(){

  int a,b,k;
  scanf("%d%d%d",&a,&b,&k);

  int count = 0;
  for(int i = 100; i > 0; --i){
    if(a % i == 0 && b % i == 0) count ++;
    if(count == k){
      printf("%d",i);
      return 0;
    }
  }

  return 0;
}

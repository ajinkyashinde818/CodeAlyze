#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define rep(i,n) for(int i=0; i <(n); i++)

int compint(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}
int main(){
  int n;
  int a[100001];
  scanf("%d",&n);
  rep(i,n){
    scanf("%d",&a[i]);
  }
  int count=0;
  int light=1;
  int cnt[100001]={0};
  do{
    light=a[light-1];
    count++;
    cnt[light]++;
  }while(light!=2&&cnt[light]<2);
  rep(j,n){
    if(cnt[j]>1){
      printf("-1\n");
      return 0;
    }
  }
  printf("%d\n",count);
  return 0;
}

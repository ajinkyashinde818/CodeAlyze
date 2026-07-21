#include<stdio.h>
#define X 1000000007

int main(){
  long long alpha[26] = {};
  char str[100010] = {};
  long long n = 0;
  long long i = 0;
  long long cnt = 1;
  scanf("%lld",&n);
  scanf(" %s",str);
  for(i=0;i<n;i++){
    alpha[str[i]-'a']++;
  }
  for(i=0;i<26;i++){
    cnt = (cnt *((alpha[i] + 1) % X))%X;
  }
  if(cnt==0){
    cnt = X - 1;
  }else{
    cnt--;
  }
  printf("%lld",cnt);
  return 0;
}

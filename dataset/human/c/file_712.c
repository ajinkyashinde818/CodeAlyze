#include <stdio.h>

int main(void){
  long long N;
  char S[100000];
  long long n[26]={0};
  long long c=1;
  int i;

  scanf("%lld",&N);
  scanf("%s",S);
  
  for(i=0;i<N;i++){
    n[S[i]-'a']++;
  }

  for(i=0;i<26;i++){
    if(n[i]!=0){
        c*=(n[i]+1);
        c%=1000000007;
    }
  }
    
  printf("%lld\n",c-1);
  
  return 0;
}

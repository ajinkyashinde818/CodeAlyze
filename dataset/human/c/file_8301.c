#include <stdio.h>
#include <string.h>

int main(){
  int N,K;
  scanf("%d",&N);
  char S[N],ans[N];
  scanf("%s",S);
  scanf("%d",&K);

  strcpy(ans,S);

  for(int i = 0; i < N; i ++){
    if(S[i] != S[K - 1]){
      ans[i] = '*';
    }
  }

  printf("%s",ans);

  return 0;
}

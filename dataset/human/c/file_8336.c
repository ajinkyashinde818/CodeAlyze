//atcoder clange
#include <stdio.h>

int main(void){
    int N;
    
     scanf("%d", &N);
    char S[N];
    scanf("%s", S);
   int K;
	scanf("%d", &K);
  int i;
  for(i=0;i<N;i++){
	if(S[K-1] != S[i]){
      S[i] = '*';
    }
  }
  
	printf("%s",S);
    return 0;
}

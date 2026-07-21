#include <stdio.h>

int main(void)
{
int N, K, i;
char S[10];

scanf("%d", &N);
scanf("%s", S);
scanf("%d", &K);

for(i=0; i<N; i++){
 if(S[i] != S[K-1])
  S[i] = '*';
}

printf("%s \n", S);

return 0;
}

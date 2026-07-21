#include <stdio.h>

int main(){

      int i,N,K;

      scanf("%d",&N);

      char moji[N],S;

      scanf("%s",moji);

      scanf("%d",&K);

      S = moji[K-1];
      for(i=0;moji[i] != '\0';i++){
            if(moji[i] != S)moji[i] = '*';
      }
      printf("%s",moji);
}

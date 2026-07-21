#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(){
  char S[1000005];
  int Q;
  int rev=0;
  int top=250001;
  int back=250002;

  scanf("%s",&S[250002]);
  back += strlen(&S[250002]);
  scanf("%d",&Q);
  for(int i = 1 ; i <= Q ; i++){
    int T;
    scanf("%d",&T);
    if(T == 1){
      rev++;
    }else if(T == 2){

      int F;
      char c[4];
      scanf("%d",&F);

      if(F == 1){
        if(rev % 2 == 0){
          scanf("%s",&c);
          S[top] = c[0];
          top--;
        }else if(rev % 2 == 1){
          scanf("%s",&c);
          S[back] = c[0];
          back++;
        }
      }else if(F == 2){
        if(rev % 2 == 0){
          scanf("%s",&c);
          S[back] = c[0];
          back++;
        }else if(rev % 2 == 1){
          scanf("%s",&c);
          S[top] = c[0];
          top--;
        }
      }
    }

  }
  if(rev % 2 == 0){
    for(int i = top+1 ; i <= back-1 ; i++){
      printf("%c",S[i]);
    }
  }else if(rev % 2 == 1){
    for(int i = back-1 ; i >= top+1 ; i--){
      printf("%c",S[i]);
    }
  }
}

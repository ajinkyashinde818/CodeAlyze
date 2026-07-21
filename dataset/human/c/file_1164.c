#include<stdio.h>
#include<string.h>
int main(void){
  int i,j;
  char c;
  char A[101]={'\0'};
  char S[101]={'\0'};
  scanf("%s",A);
  scanf("%s",S);
  for(i=0;i<strlen(S)-1;i++){
    for(j=i+1;j<strlen(S);j++){
      if(S[i]<S[j]){
        c=S[i];
        S[i]=S[j];
        S[j]=c;
      }
    }
  }
  for(i=0;i<strlen(A)-1;i++){
    for(j=i+1;j<strlen(A);j++){
      if(A[i]>A[j]){
        c=A[i];
        A[i]=A[j];
        A[j]=c;
      }
    }
  }
  if(strcmp(A,S)<0){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
}

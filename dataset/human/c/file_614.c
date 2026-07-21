#include<stdio.h>
#include<stdlib.h>
int main()
{
  int N,M;
  char **A;
  char **B;
  int flag=0;
  
  scanf("%d %d",&N,&M);
  A=(char**)malloc(sizeof(char*)*N);
  for(int i=0;i<N;i++){
    A[i]=(char*)malloc(sizeof(char)*N);
  }
  B=(char**)malloc(sizeof(char*)*M);
  for(int i=0;i<M;i++){
    B[i]=(char*)malloc(sizeof(char)*M);
  }
  for(int i=0;i<N;i++)
    scanf("%s",A[i]);
  for(int i=0;i<M;i++)
    scanf("%s",B[i]);
  
  for(int y=0;y<N;y++){
    for(int x=0;x<N;x++){
      if(y+M-1>=N||x+M-1>=N) continue;
      flag=1;
      
      for(int by=0;by<M;by++){
        for(int bx=0;bx<M;bx++){
          if(A[y+by][x+bx]!=B[by][bx]) flag=0;
          if(flag==0) break;
        }
        if(flag==0) break;
      }
      if(flag==1) break;
    }
    if(flag==1)break;
  }
  if(flag==1) printf("Yes");
  else printf("No");
  
  return 0;
}

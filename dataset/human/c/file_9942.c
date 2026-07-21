#include <stdio.h>

#define MAX 100000

int Parent[MAX];  
int Left[MAX];  
int Right[MAX];
int D[MAX];

void Depth(int ,int);

int main(){
  int i,j;
  int n=0;
  int depth=0;
  int id=0;
  int k=0;
  int c=0;
  int lef=0;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    Left[i]=-1;
    Right[i]=-1;
    Parent[i]=-1;
  }
  
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&k);
    for(j=0;j<k;j++){
      scanf("%d",&c);
      if(j==0)Left[id]=c;
      else Right[lef]=c;
      lef=c;
      Parent[c]=id;
    }
  }

  for(i=0;i<n;i++) {
    if(Parent[i]==-1)break;
  }
  Depth(i,0);

  for(i=0;i<n;i++){
    printf("node %d: ",i);
    printf("parent = %d, ",Parent[i]);
    printf("depth = %d, ",D[i]);
    if(Parent[i]==-1)printf("root, ");
    else if(Left[i]==-1)printf("leaf, ");
    else printf("internal node, ");
    printf("[");
    c=Left[i];
    for(j=0;c!=-1;j++){
      if(j!=0)printf(", ");
      printf("%d",c);
      c=Right[c];
    }
    printf("]\n");
  }
  
  return 0;
}

void Depth(int n, int d){
  D[n]=d;
  if(Right[n]!=-1) Depth(Right[n],d);
  if(Left[n]!=-1)Depth(Left[n],d+1);
}

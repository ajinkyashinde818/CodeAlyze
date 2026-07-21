#include <stdio.h>
#define N 100000

typedef struct{
  int p;
  int d;
  int r;
}node;

int main()
{
  node u[N];
  int b=-1,id,k,c,l,r,i,j,n;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    u[i].p=b;
    u[i].d=b;
    u[i].r=b;
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&id,&k);
    for(j=0;j<k;j++){
      scanf("%d",&c);
      if(j==0)u[id].d=c;
      else u[l].r=c;
      l=c;
      u[c].p=id;
    }
  }
  for(i=0;i<n;i++) print(u,i);
  return 0;
}

void print(node *u,int i){
  int c;

  printf("node %d: ",i);
  printf("parent = %d, ",u[i]);
  printf("depth = %d, ",depth(u,i));
  if(u[i].p==-1)printf("root, ");
  if(u[i].p!=-1 && u[i].d==-1)printf("leaf, ");
  if(u[i].p!=-1 && u[i].d!=-1)printf("internal node, ");
  printf("[");
  if(u[i].d != -1){
    printf("%d",u[i].d);
    c=u[i].d;
    while(u[c].r != -1){
      printf(", %d",u[c].r);
      c=u[c].r;
    }
  }
  printf("]\n");
}

int depth(node *u,int x){
  int count=0,temp;

  while(u[x].p != -1){
    count++;
    temp=u[x].p;
    x=temp;
  }
  return count;
}

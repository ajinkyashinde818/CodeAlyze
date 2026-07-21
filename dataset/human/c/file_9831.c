#include <stdio.h>
#define MAX 100005
#define NIL -1

typedef struct Node {
  int p;
  int l;
  int r;
}N;

N T[MAX];
int D[MAX];



int setDepth(int u,int p){
  D[u]=p;
  if(T[u].r!=NIL)
    setDepth(T[u].r,p);
  if(T[u].l!=NIL)
    setDepth(T[u].l,p+1);
}


int main(){
  int i,j,n,v,d,c,l,r;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].p=NIL;
    T[i].l=NIL;
    T[i].r=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&v,&d);
    for(j=0;j<d;j++){
      scanf("%d",&c);
      if(j==0)T[v].l=c;
      else T[l].r=c;
      l=c;
      T[c].p=v;

    }
  }
  for(i=0;i<n;i++)
    if(T[i].p==NIL)r=i;

  setDepth(r,0);

  for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,T[i].p,D[i]);
    if(T[i].p==NIL)printf("root,");
    else if(T[i].l==NIL)printf("leaf,");
    else printf("internal node,");

    printf(" [");

    for(j=0,c=T[i].l;c!=NIL;j++,c=T[c].r){
      if(j)printf(", ");
      printf("%d",c);

    }
    printf("]\n");

  }



    
  return 0;
}

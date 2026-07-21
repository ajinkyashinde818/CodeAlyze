#include<stdio.h>
#define N 100000
#define NILL -1

typedef struct{
  int p;
  int l;
  int r;
}Node;
  
Node A[N];
int n,B[N];

  
int rec(int x,int y){
  B[x] = y;
  if(A[x].r != NILL) rec(A[x].r,y);
  if(A[x].l != NILL) rec(A[x].l,y + 1);
}


int main(){
  int i,j,d,v,c,l,r,n,op;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    A[i].p = A[i].l = A[i].r = NILL;
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&v,&d);
    for(j=0;j<d;j++){
      scanf("%d",&c);
      if(j==0) A[v].l=c;
      else A[l].r = c;
      l=c;
      A[c].p = v;
    }
  }
  for(i=0;i<n;i++){
    if(A[i].p == -1) r=i;
  }

  rec(r,0);

  for(i=0;i<n;i++){
   
    printf("node %d: parent = %d, depth = %d,",i,A[i].p,B[i]);
    if(A[i].p == -1) printf(" root,");
    else if(A[i].l == -1 ) printf(" leaf,");
    else printf(" internal node,");
    printf(" [");
    for(j=0,op=A[i].l;op != -1;j++,op = A[op].r){
      if(j != 0) printf(", ");
      printf("%d",op);
    }
    printf("]\n");  
  }

  return 0;
}

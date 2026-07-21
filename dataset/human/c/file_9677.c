#include<stdio.h>
#define MAX 100000
void rec(int x,int y);
typedef struct{
  int p;
  int l;
  int r;
}id;
   
id A[MAX];
int n,B[MAX];
 
   
void rec(int x,int y){
  B[x] = y;
  if(A[x].r != -1) rec(A[x].r,y);
  if(A[x].l != -1) rec(A[x].l,y + 1);
}


int main(){
  int c,d,i,j,v,l,r,n,op;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    A[i].p = A[i].l = A[i].r = -1;
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
    op=A[i].l;
    for(j=0;op!=-1;j++){
      if(j != 0) printf(", ");
      printf("%d",op);
      op = A[op].r;
    }
    printf("]\n");  
  }
 
  return 0;
}

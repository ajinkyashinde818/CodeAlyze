#include<stdio.h>
#define N 25

struct Node{
  int p;
  int l;
  int r;
};
  
struct Node A[N];
int n,B[N],C[N];

  
int rec(int x,int y){
  B[x] = y;
  if(A[x].r != -1) rec(A[x].r,y+1);
  if(A[x].l != -1) rec(A[x].l,y + 1);
}

int Getb(int x){
  if(A[x].p== -1) return -1;
  if(A[A[x].p].l!=x&&A[A[x].p].l!=-1)
    return A[A[x].p].l;
  if(A[A[x].p].r!=x&&A[A[x].p].r!=-1)
    return A[A[x].p].r;
  return -1;
}

int Geth(int x){
  int a=0,b=0;
  if(A[x].l != -1) a=Geth(A[x].l)+1;
  if(A[x].r != -1) b=Geth(A[x].r)+1;
  return C[x]=(a>b ? a : b);
}

  
  

int main(){
  int i,j,d,v,c,l,r,n,op;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    A[i].p = A[i].l = A[i].r = -1;
  }

  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&d,&op);
    A[v].l = d;
    A[v].r = op;
    if(d != -1) A[d].p=v;
    if(op != -1) A[op].p=v;
  }
  for(i=0;i<n;i++){
    if(A[i].p == -1) r=i;
  }

  rec(r,0);
  

  for(i=0;i<n;i++){
    int deg=0;
    if(A[i].l!=-1) deg++;
      if(A[i].r!=-1) deg++;
    
    Geth(i);
 
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,A[i].p,Getb(i),deg,B[i],C[i]);
    if(A[i].p == -1) printf("root\n");
    else if(A[i].l == -1 && A[i].r == -1 ) printf("leaf\n");
    else printf("internal node\n");

  }
  return 0;
}

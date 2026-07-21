#include<stdio.h>
#define MAX 100005
#define NIL -1

void print(int);
int rec(int,int);

struct Node{
  int p,l,r;
};


int n,B[MAX];
struct Node A[MAX];


int main(){
  int i,j,a,b,c,d,e;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    A[i].p = NIL;
    A[i].l = NIL;
    A[i].r = NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&b,&a);
    for(j=0;j<a;j++){
      scanf("%d",&c);
      if(j==0){
	A[b].l = c;
      }
      else A[d].r = c;
      d = c;
      A[c].p = b;
    }
  }
  for(i=0;i<n;i++){
    if(A[i].p == NIL){
      e = i;
    }
  }
  rec(e,0);
  for(i=0;i<n;i++){
    print(i);

  }
  return 0;
}

void print(int s){
  int i,c;
  printf("node %d: ",s);
  printf("parent = %d, ",A[s].p);
  printf("depth = %d, ",B[s]);
  if(A[s].p == NIL){
    printf("root, ");
  }
  else if(A[s].l == NIL){
    printf("leaf, ");
  }
  else printf("internal node, ");

  printf("[");

  for(i = 0,c = A[s].l;c != NIL;i++,c = A[c].r){
    if(i>0){
      printf(", ");
    }
    printf("%d",c);
  }
  printf("]\n");
}

int rec(int t,int q){
  B[t] = q;
  if(A[t].r != NIL)rec(A[t].r,q);
  if(A[t].l != NIL)rec(A[t].l,q+1);
}

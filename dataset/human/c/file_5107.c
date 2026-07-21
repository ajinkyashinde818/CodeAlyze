#include<stdio.h>
#define MAX 10000
#define NIL -1

struct Node {
  int p,l,r;
};

void setdep(int,int);
int setheight(int);
int sibling(int);
void print(int);


struct Node A[MAX];
int n,B[MAX],C[MAX];

int main(){
  int i,a,b,c,root;
  root=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    A[i].p=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d %d %d",&a,&b,&c);
    A[a].l = b;
    A[a].r=c;
    if(b != NIL){
      A[b].p=a;
    }
    if(c != NIL){
      A[c].p = a;
    }
  }
 for(i=0;i<n;i++){
      if(A[i].p == NIL){
        root = i;
      }
    }
    setdep(root,0);
    setheight(root);
    for(i=0;i<n;i++){
      print(i);
    }
 return 0;
  }


void setdep(int p,int q){
  if(p == NIL){
    return;
  }
  B[p]=q;
  setdep(A[p].l,q+1);
  setdep(A[p].r,q+1);
}
int setheight(int r){
  int l,m;
  l=0;
  m=0;
  if(A[r].l != NIL){
    l = setheight(A[r].l) + 1;
}
  if( A[r].r != NIL){
    m = setheight(A[r].r) + 1;
  }
  return C[r] = (l > m ? l : m);
}

int sibling(int s){
  if(A[s].p == NIL)return NIL;
  if(A[A[s].p].l != s && A[A[s].p].l != NIL)return A[A[s].p].l;
  if(A[A[s].p].r != s && A[A[s].p].r != NIL)return A[A[s].p].r;
  return NIL;
}
void print(int t){
  int d;
  d=0;
  printf("node %d: ", t);
  printf("parent = %d, ", A[t].p);
  printf("sibling = %d, ",sibling(t));
  if(A[t].l != NIL)d++;
  if(A[t].r != NIL)d++;
  printf("degree = %d, ", d);
  printf("depth = %d, ", B[t]);
  printf("height = %d, ", C[t]);
  if(A[t].p == NIL){
 printf("root\n");
  }  else if(A[t].l == NIL && A[t].r == NIL){
    printf("leaf\n");
  }
  else{
    printf("internal node\n");
  }
}

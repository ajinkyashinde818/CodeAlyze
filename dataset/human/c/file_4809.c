#include<stdio.h>
#define MAX 10000
#define NIL -1

struct Node {
  int parent,left,right;
};

void setdepth(int,int);
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
    A[i].parent=NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d %d %d",&a,&b,&c);
    A[a].left = b;
    A[a].right=c;
    if(b != NIL){
      A[b].parent=a;
    }
    if(c != NIL){
      A[c].parent = a;
    }
  }
 for(i=0;i<n;i++){
      if(A[i].parent == NIL){
        root = i;
      }
    }
    setdepth(root,0);
    setheight(root);
    for(i=0;i<n;i++){
      print(i);
    }
 return 0;
  }


void setdepth(int p,int q){
  if(p == NIL){
    return;
  }
  B[p]=q;
  setdepth(A[p].left,q+1);
  setdepth(A[p].right,q+1);
}
int setheight(int r){
  int l,m;
  l=0;
  m=0;
  if(A[r].left != NIL){
    l = setheight(A[r].left) + 1;
}
  if( A[r].right != NIL){
    m = setheight(A[r].right) + 1;
  }
  return C[r] = (l > m ? l : m);
}

int sibling(int s){
  if(A[s].parent == NIL)return NIL;
  if(A[A[s].parent].left != s && A[A[s].parent].left != NIL)return A[A[s].paren\
t].left;
  if(A[A[s].parent].right != s && A[A[s].parent].right != NIL)return A[A[s].par\
ent].right;
  return NIL;
}
void print(int t){
  int d;
  d=0;
  printf("node %d: ", t);
  printf("parent = %d, ", A[t].parent);
  printf("sibling = %d, ",sibling(t));
  if(A[t].left != NIL)d++;
  if(A[t].right != NIL)d++;
  printf("degree = %d, ", d);
  printf("depth = %d, ", B[t]);
  printf("height = %d, ", C[t]);
  if(A[t].parent == NIL){
 printf("root\n");
  }  else if(A[t].left == NIL && A[t].right == NIL){
    printf("leaf\n");
  }
  else{
    printf("internal node\n");
  }
}

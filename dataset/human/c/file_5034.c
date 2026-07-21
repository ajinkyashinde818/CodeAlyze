#include<stdio.h>
#define MAX 10000
#define NIL -1


typedef struct{
  int parent;
  int left;
  int right;
}Node;

Node T[MAX];

int n,H[MAX];

int getDep(int u){

  int d=0;
  while(T[u].parent!=NIL){
    u=T[u].parent;
    d++;
  }
  return d;
}

int setH(int u){

  int h1,h2;
  h1=h2=0;

  if(T[u].right!=NIL) h1=setH(T[u].right)+1;
  if(T[u].left!=NIL) h2=setH(T[u].left)+1;

  return H[u] = (h1>h2?h1:h2);

}

int getS(int u){
  if(T[u].parent==NIL) return NIL;
  
  if(T[T[u].parent].left != u && T[T[u].parent].left!=NIL) return T[T[u].parent].left;

  if(T[T[u].parent].right != u && T[T[u].parent].right!=NIL) return T[T[u].parent].right;

  return NIL;
}


void print(int u){

  int i,c;

  printf("node %d: parent = %d, sibling = %d, ",u,T[u].parent,getS(u));

  int deg = 0;
  if(T[u].left!=NIL) deg++;
  if(T[u].right!=NIL) deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",getDep(u));
  printf("height = %d, ",H[u]);

  
  if(T[u].parent==NIL) printf("root\n");
  else if(T[u].left==NIL&&T[u].right==NIL) printf("leaf\n");
  else printf("internal node\n");

  
}


int main(){
  int i,j,l,r,v,root=0;
  
  scanf("%d",&n);

  for(i=0;i<n;i++) T[i].parent=NIL;
  
  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);

    T[v].left=l;
    T[v].right=r;

    if(l!=NIL)T[l].parent=v;
    if(r!=NIL)T[r].parent=v;
  }
  for(i=0;i<n;i++){
    if(T[i].parent==NIL) root=i;
  }

  setH(root);
  
  for(i=0;i<n;i++){
    print(i);
  }

  return 0;
  
}

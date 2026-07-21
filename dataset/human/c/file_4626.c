#include <stdio.h>
#include <string.h>
#define N 100000

int height(int);
int depth(int);

typedef struct{
  int parent;
  int left;
  int right;
} data;
data node[N];


int main(){
  int n,i,j,c,t,l,x,d[20],h[20],le,ri,sib[N],f1=0,f2=0,deg[N];
  char typ[N][20],a[] = "root",b[] = "leaf",e[] = "internal node";

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    node[i].parent = node[i].left = node[i].right = sib[i] = -1;
  }
  for(i = 0;i < n;i++){
    scanf("%d%d%d",&x,&le,&ri);
    node[x].left = le;
    node[x].right = ri;
    if(le != -1){
      node[le].parent = x;
      f1++;
    }
    if(ri != -1){
      node[ri].parent = x;
      f2++;
    }
    if(le != -1 && ri != -1){
      sib[ri] = le;
      sib[le] = ri;
    }
    deg[x] = f1 + f2;
    f1 = f2 = 0;
  }
  for(i = 0;i < n;i++){

    if(node[i].parent == -1) strcpy(typ[i], a);
    else if(node[i].left == -1 && node[i].right == -1) strcpy(typ[i], b);
    else strcpy(typ[i], e);
    h[i] = height(i);
    d[i] = depth(i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",i,node[i].parent,sib[i],deg[i],d[i],h[i],typ[i]);
  }
  return 0;
}

int depth(int u){
  int d=0;
  while(node[u].parent != -1){
    u = node[u].parent;
    d++;
  }
  return d;
}

int height(int u){
  int h1 = 0,h2 = 0;
  if(node[u].left != -1) h1 = height(node[u].left) + 1;
  if(node[u].right != -1) h2 = height(node[u].right) + 1;
  if(h1 > h2) return h1;
  else return h2;
}

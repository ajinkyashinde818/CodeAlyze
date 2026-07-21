#include <stdio.h>
#define MAX 1000005
#define NIL -1

struct Node{
  int p,l,r;
};
struct Node tree[MAX];
int n,D[MAX],H[MAX];

int getSibling(int u){
  if(tree[u].p==NIL){
    return NIL;
  }
  if(tree[tree[u].p].l!=u && tree[tree[u].p].l!=NIL){
    return tree[tree[u].p].l;
  }
  if(tree[tree[u].p].r!=u && tree[tree[u].p].r!=NIL){
    return tree[tree[u].p].r;
  }
  return NIL;
}
void print(int u){
  int sub,dgree=0;
  printf("node %d: parent = %d, sibling = %d, ",u,tree[u].p,sub = getSibling(u));
  if(tree[u].l!=NIL){
    dgree++;
  }
  if(tree[u].r!=NIL){
    dgree++;
  }
  printf("degree = %d, depth = %d, height = %d, ",dgree,D[u],H[u]);

  if(tree[u].p==NIL){
    printf("root\n");
  }
  else if(tree[u].l==NIL && tree[u].r==NIL){
    printf("leaf\n");
  }
  else{
    printf("internal node\n");
  }
}

void setDepth(int u,int d){
  if(u==NIL){
    return;
  }
  D[u] = d;
  setDepth(tree[u].l,d+1);
  setDepth(tree[u].r,d+1);
}

int setHeight(int u){
  int h1=0,h2=0;
  if(tree[u].l != NIL){
    h1 = setHeight(tree[u].l) + 1;
  }
  if(tree[u].r != NIL){
    h2 = setHeight(tree[u].r) + 1;
  }
  if(h1>=h2){
    H[u] = h1;
    return H[u];
  }
  else{
    H[u] = h2;
    return H[u];
  }
}

int main(){
  int i,v,l,r,root=0;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    tree[i].p = NIL;
  }
  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    tree[v].l = l;
    tree[v].r = r;
    if(l != NIL){
      tree[l].p = v;
    }
    if(r != NIL){
      tree[r].p = v;
    }
  }
  for(i=0;i<n;i++){
    if(tree[i].p == NIL){
      root = i;
    }
  }
  setDepth(root,0);
  setHeight(root);

  for(i=0;i<n;i++){
    print(i);
  }
return 0;
}

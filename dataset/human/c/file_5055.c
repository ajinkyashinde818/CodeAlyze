#include <stdio.h>
#include <stdlib.h>
#define MAX 10000
#define NIL -1

typedef struct{
  int parent,left,right;
}family;

int setHeight(int);
int getSibling(int);
void setDepth(int,int);
void printchildren(int);

int D[MAX],H[MAX],n;
family t[MAX];

int main(){
  int i,id,lef,rig,root = 0,deg;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    t[i].parent = NIL;
    t[i].left = NIL;
    t[i].right = NIL;
  }
  for(i = 0;i < n;i++){
    scanf("%d",&id);
    scanf("%d",&lef);
    scanf("%d",&rig);
    t[id].right = rig;
    t[id].left = lef;
    if(rig != NIL) t[rig].parent = id;
    if(lef != NIL) t[lef].parent = id;
    
  }
  for(i = 0;i < n;i++) if(t[i].parent == NIL) root = i;
  setDepth(root,0);
  setHeight(root);
  
  for(i = 0;i < n;i++){
    deg = 0;
    printf("node %d: parent = %d, sibling = %d, ",i,t[i].parent,getSibling(i));
    if(t[i].left != NIL) deg++;
    if(t[i].right != NIL) deg++;
    printf("degree = %d, depth = %d, height = %d, ",deg,D[i],H[i]);
    if(t[i].parent == NIL) printf("root\n");
    else if(t[i].left == NIL && t[i].right == NIL) printf("leaf\n");
    else printf("internal node\n");
  }

  return 0;
}

void setDepth(int u,int p){
  if(u == NIL) return;
  D[u] = p;
  setDepth(t[u].left,p + 1);
  setDepth(t[u].right,p + 1);
}

int setHeight(int u){
  int h1 = 0,h2 = 0;
  if(t[u].left != NIL){
    h1 = setHeight(t[u].left) + 1;
  }
  if(t[u].right != NIL){
    h2 = setHeight(t[u].right) + 1;
  }
  if(h1 < h2) return H[u] = h2;
  else return H[u] = h1;
}

int getSibling(int u){
  if(t[u].parent == NIL) return NIL;
  if(t[t[u].parent].left != u && t[t[u].parent].left != NIL) return t[t[u].parent].left;
  if(t[t[u].parent].right != u && t[t[u].parent].right != NIL) return t[t[u].parent].right;
  return NIL;
}

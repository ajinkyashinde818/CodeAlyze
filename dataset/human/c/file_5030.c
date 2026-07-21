#include<stdio.h>

#define MAX 10000
#define NIL -1

typedef struct{
  int parent, left, right;
}Node;

Node g_node[MAX];
int g_n, g_d[MAX], g_h[MAX];

void setDepth(int u, int d);
int setHeight(int u);
int getSibling(int u);
void print(int u);

int main(){
  int i, v, l, r, root = 0;

  scanf("%d",&g_n);

  for(i = 0; i < g_n; i++){
    g_node[i].parent = NIL;
  }

  for(i = 0; i < g_n; i++){
    scanf("%d %d %d",&v,&l,&r);
    g_node[v].left = l;
    g_node[v].right = r;
    if(l != NIL) g_node[l].parent = v;
    if(r != NIL) g_node[r].parent = v;
  }

  for(i = 0; i < g_n; i++){
    if(g_node[i].parent == NIL) root = i;
  }

  setDepth(root, 0);
  setHeight(root);

  for(i = 0; i < g_n; i++){
    print(i);
  }
  
  return 0;
}

void setDepth(int u, int d){
  if(u == NIL) return;
  g_d[u] = d;
  setDepth(g_node[u].left, d + 1);
  setDepth(g_node[u].right, d + 1);
}

int setHeight(int u){
  int h1 = 0, h2 = 0;
  if(g_node[u].left != NIL) h1 = setHeight(g_node[u].left) + 1;
  if(g_node[u].right != NIL) h2 = setHeight(g_node[u].right) + 1;

  if(h1 > h2){
    g_h[u] = h1;
    return h1;
  }
  else{
    g_h[u] = h2;
    return h2;
  }
}

int getSibling(int u){

  if(g_node[u].parent == NIL) return NIL;
  if(g_node[g_node[u].parent].left != u && g_node[g_node[u].parent].left != NIL)
    return g_node[g_node[u].parent].left;
  if(g_node[g_node[u].parent].right != u && g_node[g_node[u].parent].right != NIL)
    return g_node[g_node[u].parent].right;
  return NIL;
}

void print(int u){
  int deg = 0;
  
  printf("node %d: ",u);
  printf("parent = %d, ", g_node[u].parent);
  printf("sibling = %d, ", getSibling(u));

  if(g_node[u].left != NIL) deg++;
  if(g_node[u].right != NIL) deg++;
  printf("degree = %d, ",deg);
  printf("depth = %d, ",g_d[u]);
  printf("height = %d, ",g_h[u]);

  if(g_node[u].parent == NIL){
    printf("root\n");
  }else if(g_node[u].left == NIL && g_node[u].right == NIL){
    printf("leaf\n");
  }else{
    printf("internal node\n");
  }
}

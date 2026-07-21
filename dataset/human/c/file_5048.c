#include <stdio.h>
#define N 10000
#define NIL -1

typedef struct node{
  int p;
  int l;
  int r;
} Node;

Node no[N];
int n;
int d[N], h[N];

void Depth(int node, int depth){
  if(node == NIL) return;
  d[node] = depth;
  Depth(no[node].l, depth+1);
  Depth(no[node].r, depth+1);
}

int Height(int node){
  int he1 = 0, he2 = 0;
  if(no[node].l != NIL){
    he1 = Height(no[node].l) + 1;
  }
  if(no[node].r != NIL){
    he2 = Height(no[node].r) + 1;
  }
  return h[node] = (he1 > he2 ? he1 : he2);
}

int Sibling(int node){
  if(no[node].p == NIL) return NIL;
  if(no[no[node].p].l != node && no[no[node].p].l != NIL){
    return no[no[node].p].l;
  }
  if(no[no[node].p].r != node && no[no[node].p].r != NIL){
    return no[no[node].p].r;
  }
  return NIL;
}

void output(int node){
  printf("node %d: parent = %d, sibling = %d, ", node, no[node].p, Sibling(node));
  int de = 0;
  if(no[node].l != NIL){
    de++;
  }
  if(no[node].r != NIL){
    de++;
  }
  printf("degree = %d, depth = %d, height = %d, ", de, d[node], h[node]);

  if(no[node].p == NIL){
    printf("root\n");
  }else if(no[node].l == NIL && no[node].r == NIL){
    printf("leaf\n");
  }else {
    printf("internal node\n");
  }
}

int main(){
  int i;
  int id, left, right, root = 0;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    no[i].p = NIL;
  }

  for(i = 0; i < n; i++){
    scanf("%d%d%d", &id, &left, &right);
    no[id].l = left;
    no[id].r = right;
    if(left != NIL){
      no[left].p = id;
    }
    if(right != NIL){
      no[right].p = id;
    }
  }

  for(i = 0; i < n; i++){
    if(no[i].p == NIL){
      root = i;
    }
  }

  Depth(root, 0);
  Height(root);

  for(i = 0; i < n; i++){
    output(i);
  }

  return 0;
}

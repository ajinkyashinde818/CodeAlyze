#include <stdio.h>
#define NIL -1

typedef struct {
  int id;
  int l;
  int r;
  int p;
} Tree;

Tree tree[30];
int max = 0;
int H[30];
void init(int n){
  for(int i = 0; i < n; ++i){
    tree[i].id = NIL;
    tree[i].l= NIL;
    tree[i].r = NIL;
    tree[i].p = NIL;
  }
}
void print_sibling(int i){
  printf("sibling = ");
  int p = tree[i].p;
  if(p == NIL)
    printf("%d", NIL);
  else if(tree[p].l == NIL || tree[p].r == NIL)
    printf("%d", NIL);
  else if(i == tree[p].l)
    printf("%d", tree[p].r);
  else
    printf("%d", tree[p].l);
  printf(", ");
}
void print_degree(int i){
  int count = 0;
  if(tree[i].l != NIL)
    ++count;
  if(tree[i].r != NIL)
    ++count;
  printf("degree = %d, ", count);
}
void print_depth(int i){
  int count = 0;
  while(1){
    i = tree[i].p;
    if(i == NIL)
      break;
    ++count;
  }
  printf("depth = %d, ", count);

}
int getRoot(int n){
  int root = 0;
  for(int i = 0; i < n; ++i){
    if(tree[i].p == NIL){
      root = i;
      break;
    }
  }
  return root;
}

int setHeight(int n){
  int h1 = 0, h2 = 0;
  if(tree[n].r != NIL)
    h1 = setHeight(tree[n].r) + 1;
  if(tree[n].l != NIL)
    h2 = setHeight(tree[n].l) + 1;
  H[n] =(h1 > h2 ? h1 : h2); 
  return (h1 > h2 ? h1 : h2);
}
void print(int n){
  for(int i = 0; i < n; ++i){
    printf("node %d: parent = %d, ", tree[i].id, tree[i].p);
    print_sibling(i);
    print_degree(i);
    print_depth(i);
    printf("height = %d, ", H[i]);
    if(tree[i].p == NIL)
      printf("root");
    else if(tree[i].r == NIL && tree[i].l == NIL)
      printf("leaf");
    else
      printf("internal node");
    printf("\n");
  }
}

int main(){
  int n, id, l, r;
  
  scanf("%d", &n);
  init(n);
  for(int i = 0; i < n; ++i){
    scanf("%d%d%d", &id, &l, &r);
    tree[id].id = id;
    tree[id].l = l;
    tree[id].r = r;
    if(l != NIL)
      tree[l].p = id;
    if(r != NIL)
      tree[r].p = id;
  }
  setHeight(getRoot(n));
  print(n);
  return 0;
}

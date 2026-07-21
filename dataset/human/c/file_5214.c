#include <stdio.h>
#define N 10000

typedef struct{
  int p;
  int l;
  int r;
}Node;

Node T[N];
int n, D[N], H[N];

void setDepth(int u, int d){
  if(u == -1) return;
  D[u] = d;
  setDepth(T[u].l, d+1);
  setDepth(T[u].r, d+1);
}

int setHeight(int u){
  int h1=0, h2=0;
  if(T[u].l != -1) h1 = setHeight(T[u].l) + 1;
  if(T[u].r != -1) h2 = setHeight(T[u].r) + 1;
  return H[u] = (h1 > h2 ? h1 : h2);
}

int getSibling(int u){
  if(T[u].p == -1) return -1;
  if(T[T[u].p].l != u && T[T[u].p].l != -1) return  T[T[u].p].l;
  if(T[T[u].p].r != u && T[T[u].p].r != -1) return T[T[u].p].r;
  return -1;
}

int main(){
  int i, v, l, r, deg, root=0;

  scanf("%d", &n);

  for(i=0; i<n; i++) T[i].p = -1;

  for(i=0; i<n; i++){
    scanf("%d %d %d", &v, &l, &r);
    T[v].l = l;
    T[v].r = r;
    if(l != -1) T[l].p = v;
    if(r != -1) T[r].p = v;
  }

  for(i=0; i<n; i++){
    if(T[i].p == -1) root = i;
  }

  setDepth(root, 0);
  setHeight(root);

  for(i=0; i<n; i++){
    printf("node %d: ", i);
    printf("parent = %d, ", T[i].p);
    printf("sibling = %d, ", getSibling(i));
    deg = 0;
    if(T[i].l != -1) deg++;
    if(T[i].r != -1) deg++;
    printf("degree = %d, ", deg);
    printf("depth = %d, ", D[i]);
    printf("height = %d, ", H[i]);

    if(T[i].p == -1) printf("root\n");
    else if(T[i].l == -1 && T[i].r == -1) printf("leaf\n");
    else printf("internal node\n");
  }
  
  return 0;
}

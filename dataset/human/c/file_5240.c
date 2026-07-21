#include <stdio.h>
#include <string.h>

typedef struct {
  int par, sib, lch, rch, depth, height;
} node;

#define MAX_N 25

int n;
node T[MAX_N];

int max(int a, int b) {
  return a > b ? a : b;
}

int dfs(int u, int depth) {
  int hl = 0, hr = 0;
  T[u].depth = depth;
  if(T[u].lch != -1) hl = dfs(T[u].lch, depth+1) + 1;
  if(T[u].rch != -1) hr = dfs(T[u].rch, depth+1) + 1;
  return T[u].height = max(hl, hr);
}

int main() {
  int root = -1;
  int i;

  for(i = 0; i < MAX_N; i++) {
    T[i] = (node){-1, -1, -1, -1, -1, -1};
  }

  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    int id, lch, rch;
    scanf("%d %d %d", &id, &lch, &rch);
    T[id].lch = lch;
    T[id].rch = rch;
    if(lch != -1) {
      T[lch].sib = rch;
      T[lch].par = id;
    }
    if(rch != -1) {
      T[rch].sib = lch;
      T[rch].par = id;
    }
  }

  for(i = 0; i < n; i++) {
    if(T[i].par == -1) root = i;
  }

  dfs(root, 0);

  for(i = 0; i < n; i++) {
    char type[256];
    int deg = 0;
    if(T[i].par == -1) strcpy(type, "root");
    else if(T[i].lch == -1 && T[i].rch == -1) strcpy(type, "leaf");
    else strcpy(type, "internal node");
    if(T[i].lch != -1) deg++;
    if(T[i].rch != -1) deg++;
    printf("node %d: ", i);
    printf("parent = %d, ", T[i].par);
    printf("sibling = %d, ", T[i].sib);
    printf("degree = %d, ", deg);
    printf("depth = %d, ", T[i].depth);
    printf("height = %d, ", T[i].height);
    puts(type);
  }

  return 0;
}

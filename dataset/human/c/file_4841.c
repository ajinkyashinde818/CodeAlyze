#include <stdio.h>
int N;
int deg[100001];
int par[100001];
int sib[100001];
int Depth(int);
int Height(int);
int main() {
  int j,i;
  scanf("%d", &N);
  for(i = 0; i < N; ++i) {
    par[i] = -1;
    sib[i] = -1;
    deg[i] = 0;
  }
  for(i = 0; i < N; i++) {
    int id, lef, rig;
    scanf("%d %d %d", &id, &lef, &rig);
    if(lef != -1) {
      par[lef] = id;
      sib[lef] = rig;
      deg[id]++;
    }
    if(rig != -1) {
      par[rig] = id;
      sib[rig] = lef;
      deg[id]++;
    }
  }
  for(i = 0; i < N; ++i) {
    int depth = Depth(i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
           i, par[i], sib[i], deg[i], depth, Height(i));
    if(depth == 0) {
      printf("root\n");
    } else if(deg[i] == 0) {
      printf("leaf\n");
    } else {
      printf("internal node\n");
    }
  }
  return 0;
}
int Depth(int i) {
  if(par[i] == -1) return 0;
  return Depth(par[i]) + 1;
}
int Height(int i) {
  int j, h;
  h = 0;
  for(j = 0; j < N; ++j) {
    if(par[j] == i) {
      int tmp = Height(j) + 1;
      if(tmp > h) h = tmp;
    }
  }
  return h;
}

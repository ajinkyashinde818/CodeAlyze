#include <stdio.h>

int T;
int pa[100001];
int si[100001];
int dg[100001];

int cDepth(int i) {
  if(pa[i] == -1) return 0;
  return cDepth(pa[i]) + 1;
}

int cHeight(int i) {
  int j, h;
  h = 0;
  
  for(j = 0; j < T; ++j) {
    if(pa[j] == i) {
      int tmp = cHeight(j) + 1;
      if(tmp > h) h = tmp;
    }
  }
  return h;
}

int main() {
  int i,j;
  
  scanf("%d", &T);
  for(i = 0; i < T; ++i) {
    pa[i] = -1;
    si[i] = -1;
    dg[i] = 0;
  }
  for(i = 0; i < T; ++i) {
    int id, le, ri;
    scanf("%d %d %d", &id, &le, &ri);
    if(le != -1) {
      pa[le] = id;
      si[le] = ri;
      ++dg[id];
    }
    
    if(ri != -1) {
      pa[ri] = id;
      si[ri] = le;
      ++dg[id];
    }
  }

  for(i = 0; i < T; ++i) {
    int depth = cDepth(i);
    
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
           i, pa[i], si[i], dg[i], depth, cHeight(i));
    if(depth == 0) {
      printf("root\n");
    } else if(dg[i] == 0) {
      printf("leaf\n");
    } else {
      printf("internal node\n");
    }
  }
  
  return 0;
}

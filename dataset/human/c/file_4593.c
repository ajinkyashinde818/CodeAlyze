#include <stdio.h>
#include<stdlib.h>
int n;
int p[100001];
int s[100001];
int d[100001];

int Depth(int i) {
  if(p[i] == -1) return 0;
  return Depth(p[i]) + 1;
}

int Height(int i) {
  int j, l;
  l=0;
  for(j = 0; j < n; ++j) {
    if(p[j] == i) {
      int tmp = Height(j)+1;
      if(tmp>l) l=tmp;
    }
  }
  return l;
}
int main() {
  int i,j;
  scanf("%d", &n);
  for(i = 0; i < n; ++i) {
    p[i] = -1;
    s[i] = -1;
    d[i] = 0;
  }
  for(i = 0; i < n; ++i) {
    int id, left, right,k;
    k=0;
    scanf("%d %d %d", &id, &left, &right);
    if(left != -1) {
      p[left] = id;
      s[left] = right;
      ++d[id];
    }
    if(right != -1) {
      p[right] = id;
      s[right] = left;
      ++d[id];
    }
  }

  for(i = 0; i < n; ++i) {
    int fukasa = Depth(i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d\
, height = %d, ",
           i, p[i], s[i], d[i], fukasa, Height(i));
    if(fukasa == 0) {
      printf("root\n");
    } else if(d[i] == 0) {
      printf("leaf\n");
    } else {
      printf("internal node\n");
    }
  }
  return 0;
}

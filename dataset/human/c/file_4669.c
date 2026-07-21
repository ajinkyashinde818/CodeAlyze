#include <stdio.h>
 
int N;
int parent[100001];
int sibling[100001];
int degree[100001];
 
int calcDepth(int i) {
  if(parent[i] == -1) return 0;
  return calcDepth(parent[i]) + 1;
}
 
int calcHeight(int i) {
  int j, h;
  h = 0;
  for(j = 0; j < N; ++j) {
    if(parent[j] == i) {
      int tmp = calcHeight(j) + 1;
      if(tmp > h) h = tmp;
    }
  }
  return h;
}
 
int main() {
  int i,j;
  scanf("%d", &N);
  for(i = 0; i < N; ++i) {
    parent[i] = -1;
    sibling[i] = -1;
    degree[i] = 0;
  }
  for(i = 0; i < N; ++i) {
    int id, left, right;
    scanf("%d %d %d", &id, &left, &right);
    if(left != -1) {
      parent[left] = id;
      sibling[left] = right;
      ++degree[id];
    }
    if(right != -1) {
      parent[right] = id;
      sibling[right] = left;
      ++degree[id];
    }
  }
 
  for(i = 0; i < N; ++i) {
    int depth = calcDepth(i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
           i, parent[i], sibling[i], degree[i], depth, calcHeight(i));
    if(depth == 0) {
      printf("root\n");
    } else if(degree[i] == 0) {
      printf("leaf\n");
    } else {
      printf("internal node\n");
    }
  }
  return 0;
}

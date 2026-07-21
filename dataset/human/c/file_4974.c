#include<stdio.h>
#include<string.h>
int N;
int parent[100002];
int sibling[100002];
int degree[100002];
 
int Depth(int i) {
  if(parent[i] == -1) return 0;
  return Depth(parent[i]) + 1;
}
  
int Height(int i) {
  int j, x, y;
 
  x = 0;
 
  for(j = 0; j < N; j++) {
    if(parent[j] == i) {
      y = Height(j) + 1;
      if(y > x) x = y;
    }
  }
 
  return x;
}
 
int main() {
  int i, j, depth;
  int id, left, right;
 
  scanf("%d", &N);
  for(i = 0; i < N; i++) {
    parent[i] = -1;
    sibling[i] = -1;
    degree[i] = 0;
  }
  for(i = 0; i < N; i++) {
    scanf("%d %d %d", &id, &left, &right);
 
    if(left != -1) {
      parent[left] = id;
      sibling[left] = right;
      degree[id]++;
    }
 
    if(right != -1) {
      parent[right] = id;
      sibling[right] = left;
      degree[id]++;
    }
  }
   
  for(i = 0; i < N; i++) {
    depth = Depth(i);
 
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", i, parent[i], sibling[i], degree[i], depth, Height(i));
 
    if(depth == 0) {
      printf("root\n");
    }
 
    else if(degree[i] == 0) {
      printf("leaf\n");
    }
 
    else {
      printf("internal node\n");
    }
  }
 
  return 0;
}

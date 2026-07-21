#include <stdio.h>
int v;
int parent[100001];
int sibling[100001];
int degree[100001];
int Depth(int i);
int Height(int i);
int main(){
  int i,j;
  int id, l, r;
  scanf("%d", &v);
  for(i = 0; i < v; ++i) {
    parent[i] = -1;
    sibling[i] = -1;
    degree[i] = 0;
  }
  for(i = 0; i < v; ++i) {
    scanf("%d %d %d", &id, &l, &r);
    if(l != -1){
      parent[l] = id;
      sibling[l] = r;
      ++degree[id];
    }
    if(r != -1){
      parent[r] = id;
      sibling[r] = l;
      ++degree[id];
    } }
  for(i = 0; i < v; ++i) {
    int depth = Depth(i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", i, parent[i], sibling[i], degree[i], depth, Height(i));
    if(depth == 0) {
      printf("root\n");
    } else if(degree[i] == 0) {
      printf("leaf\n");
    } else {
      printf("internal node\n");
    } }
  return 0; }
           
           
           
int Depth(int i){
  if(parent[i] == -1) return 0;
  return Depth(parent[i]) + 1;
}
int Height(int i){
  int j, h;
  h = 0;
  for(j = 0; j < v; ++j){
    if(parent[j] == i){
      int tmp = Height(j) + 1;
      if(tmp > h){
	h = tmp;
      } }
  }
    return h; }

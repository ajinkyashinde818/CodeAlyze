#include<stdio.h>
  
int par[100001];
int sib[100001];
int deg[100001];
int n;
  
int depth(int);
int height(int);
  
int main(int argc,char *argv[]) {
  int i,j;
  scanf("%d", &n);
  for(i = 0; i < n; ++i) {
    par[i] = -1;
    sib[i] = -1;
    deg[i] = 0;
  }
  for(i = 0; i < n; ++i) {
    int id, left, right;
    scanf("%d %d %d", &id, &left, &right);
    if(left != -1) {
      par[left] = id;
      sib[left] = right;
      deg[id]++;
    }
    if(right != -1) {
      par[right] = id;
      sib[right] = left;
      deg[id]++;
    }
  }
  
  for(i = 0; i < n; ++i) {
    int dep = depth(i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
           i, par[i], sib[i], deg[i], dep, height(i));
    if(dep == 0) {
      printf("root\n");
    } else if(deg[i] == 0) {
      printf("leaf\n");
    } else {
      printf("internal node\n");
    }
  }
  return 0;
}
 
int depth(int i) {
  if(par[i] == -1) return 0;
  return depth(par[i]) + 1;
}
  
int height(int i) {
  int j, h = 0;;
 
  for(j = 0; j < n; ++j) {
    if(par[j] == i) {
      int tmp = height(j) + 1;
      if(tmp > h) h = tmp;
    }
  }
  return h;
}

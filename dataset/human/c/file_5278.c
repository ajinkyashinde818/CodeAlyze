#include<stdio.h>
  
int p[100001];
int s[100001];
int deg[100001];
int n;
  
int depth(int);
int height(int);
  
int main(int argc,char *argv[]) {
  int i,j;
  scanf("%d", &n);
  for(i = 0; i < n; ++i) {
    p[i] = -1;
    s[i] = -1;
    deg[i] = 0;
  }
  for(i = 0; i < n; ++i) {
    int id, left, right;
    scanf("%d %d %d", &id, &left, &right);
    if(left != -1) {
      p[left] = id;
      s[left] = right;
      deg[id]++;
    }
    if(right != -1) {
      p[right] = id;
      s[right] = left;
      deg[id]++;
    }
  }
  
  for(i = 0; i < n; ++i) {
    int dep = depth(i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
           i, p[i], s[i], deg[i], dep, height(i));
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
  if(p[i] == -1) return 0;
  return depth(p[i]) + 1;
}
  
int height(int i) {
  int j, h = 0;;
 
  for(j = 0; j < n; ++j) {
    if(p[j] == i) {
      int tmp = height(j) + 1;
      if(tmp > h) h = tmp;
    }
  }
  return h;
}

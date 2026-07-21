#include <stdio.h>
#define n_max 100001
int Depth(int);
int Height(int);

int n, parent[n_max], sibling[n_max], degree[n_max];
 
int main() {
  int i, j, id, left, right, dep;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    parent[i] = -1;
    sibling[i] = -1;
    degree[i] = 0;
  }
  
  for(i=0;i<n;i++) {
    
    scanf("%d %d %d",&id,&left,&right);
    
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
 
  for(i = 0; i < n; ++i) {
    dep = Depth(i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", i, parent[i], sibling[i], degree[i], dep, Height(i));
    
    if(dep==0) printf("root\n");

    else if(degree[i]==0) printf("leaf\n");

    else printf("internal node\n");
  }
  return 0;
}



int Depth(int i){
  if(parent[i]==-1) return 0;
  return Depth(parent[i])+1;
}


int Height(int i){
  int j, h, alo;
  
  h = 0;
  for(j=0;j<n;j++) {
    if(parent[j] == i) {
      alo = Height(j) + 1;
      if(alo>h) h=alo;
    }
  }
  return h;
}

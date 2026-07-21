#include<stdio.h>
#define NILL -1
int n,parent[100000];

int depth(int);
int height(int);
int main()
{
  int i,j,k,m=0,l,r,L[100000],R[100000],id, child; 
  int sib[100000],deg[100000],hei[100000],dep[100000];
  for(i=0; i<100000; i++){
    parent[i] = -1;
    sib[i] = -1;
    deg[i] = 0;
    }
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d %d %d", &id, &l, &r);
     if(l!= -1) {
      parent[l] = id;
      sib[l] = r;
      deg[id]++;
    }
    if(r!= -1) {
      parent[r] = id;
      sib[r] = l;
      deg[id]++;
    }
  }for(i=0; i<n; i++){
    int dep=depth(i);
      printf("node %d: ", i);
      printf("parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", parent[i],sib[i], deg[i], dep, height(i));
      if(parent[i]==NILL)printf("root");
      else if(deg[i]==0)printf("leaf");
      else printf("internal node");
      printf("\n");
    }
  return 0;
}
int depth(int i){
  if(parent[i]==-1)return 0;
  return depth(parent[i]) + 1;
}
  
int height(int i){
  int j, h = 0;
  for(j = 0; j < n; ++j){
    if(parent[j] == i){
      int tmp = height(j) + 1;
      if(tmp > h) h = tmp;
    }
  }
  return h;
}

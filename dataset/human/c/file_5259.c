#include <stdio.h>
#include <string.h>

#define MAX_N 25
#define max(a,b) (a < b ? b : a)

void setHeight(int,int,int*,int*);
int getDepth(int,int*);

int main(){
  int n,i,id,l,r,type;
  int parent[MAX_N],sib[MAX_N];
  int child[MAX_N],height[MAX_N];
  char name[3][14] = {"root","leaf","internal node"};

  memset(parent,-1,sizeof(parent));
  memset(sib,-1,sizeof(sib));

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d%d%d",&id,&l,&r);
    child[id] = 0; height[i] = 0;
    if(l >= 0){ parent[l] = id; ++child[id]; }
    if(r >= 0){ parent[r] = id; ++child[id]; }
    if(l >= 0 && r >= 0){
      sib[l] = r; sib[r] = l;
    }
  }
  for(i = 0 ; i < n ; i++){
    setHeight(i,0,height,parent);
  }
  for(i = 0 ; i < n ; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",
           i,parent[i],sib[i],child[i],getDepth(i,parent),height[i]);
    if(parent[i] == -1){ type = 0; }
    else if(child[i] == 0){ type = 1; }
    else{ type = 2; }
    printf("%s\n",name[type]);
  }
  return 0;
}

void setHeight(int x,int depth,int *height,int *parent){
  height[x] = max(height[x],depth);
  if(parent[x] == -1){ return; }
  setHeight(parent[x],depth+1,height,parent);
}

int getDepth(int x,int *parent){
  if(parent[x] == -1){ return 0; }
  return getDepth(parent[x],parent) + 1;
}

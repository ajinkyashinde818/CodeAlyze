#include <stdio.h>
#include <string.h>
#define N 100000

int child[N][20];
int parent[N];
int depth[N];
int k[N];
int root;
 
void pr(int id,char str[][20]){
  int type,i;
  if(parent[id] == -1) type = 0;
  else if(k[id] > 0) type = 1;
  else if(k[id] == 0) type = 2;
 
   
  printf("node %d: parent = %d, depth = %d, %s, [", id, parent[id], depth[id], str[type]);
  for(i=0;i<k[id];i++){
    if(i)printf(", ");
    printf("%d",child[id][i]);
  }
  printf("]\n");
}
 
void dfs(int id,int dep){
  int i;
  depth[id] = dep;
  for( i=0;i<k[id];i++)dfs(child[id][i],dep+1);
}
 
int main(){
  int n,i,j,id;
  char str[3][20] = {"root","internal node","leaf"};
  scanf("%d",&n);
  memset(parent,-1,sizeof(parent));
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d",&k[id]);
    for(j=0;j<k[id];j++){
      scanf("%d",&child[id][j]);
      parent[ child[id][j] ] = id;
    }
  }
   
  for(i=0;i<n;i++)
    if(parent[i] == -1) root = i;
  dfs(root,0);
  for(i=0;i<n;i++) pr(i,str);
 
  return 0;
}

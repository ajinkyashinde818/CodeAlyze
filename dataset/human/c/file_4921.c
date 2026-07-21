#include <stdio.h>
#define MAX 100000
int p,parent[MAX],sibling[MAX],degree[MAX];
int Depth(int i),Height(int i);
int main(){
  int i,j,id,a,b;;
  scanf("%d",&p);
  for(i=0;i<p;++i){
    parent[i]=-1;
    sibling[i]=-1;
    degree[i]=0;
  }
  for(i=0;i<p;++i){
    scanf("%d%d%d",&id,&a,&b);
    if(a!=-1){
      parent[a]=id;
      sibling[a]=b;
      ++degree[id];
    }
    if(b!=-1){
      parent[b]=id;
      sibling[b]=a;
      ++degree[id];
    }
  }
  for(i=0;i<p;++i) {
    int depth=Depth(i);
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,parent[i],sibling[i],degree[i],depth,Height(i));
    if(depth==0){
      printf("root\n");
    }
    else if(degree[i]==0)
      printf("leaf\n");
    else
      printf("internal node\n");
  }
  return 0;
  }

int Depth(int i){
  if(parent[i]==-1)
    return 0;
  return Depth(parent[i])+1;
}

int Height(int i){
  int k,h;
  h=0;
  for(k=0;k<p;++k){
    if(parent[k]==i){
      int tmp=Height(k)+1;
      if(tmp>h){
        h=tmp;
      }
    }
  }
  return h;
}

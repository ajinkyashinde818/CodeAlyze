#include <stdio.h>
typedef struct node {
  int parent;
  int left;
  int right;
}Node;

int Depth(int);
Node trees[100000];
int depth[100000];
int main(){
  int c,n,i,j,k,id,l=0,r;

    scanf("%d",&n);
    
    for(i=0;i<n;i++){
    trees[i].parent=-1;
    trees[i].left=-1;
    trees[i].right=-1;
  }
    
  for(i=0;i<n;i++) {
    scanf("%d %d",&id,&k);
    for(j=0;j<k;j++) {
      scanf("%d",&c);
      if(j==0) trees[id].left=c;
      else trees[l].right=c;
      l=c;
      trees[c].parent=id;
    }
  }
  
    for(i=0;i<n;i++){
    depth[i] = Depth(i);
  }

    for(i=0;i<n;i++) {
      printf("node %d: ",i);
      printf("parent = %d, ",trees[i].parent);
      printf("depth = %d, ",depth[i]);
      if(trees[i].parent == -1)printf("root, ");
      else if(trees[i].left == -1)printf("leaf, ");
      else printf("internal node, ");
      printf("[");
      for(j = 0,c=trees[i].left;c!=-1;j++,c=trees[c].right){
	if(j!=0)printf(", ");
	printf("%d",c);
	
      }
      printf("]\n");
    }
    return 0;
}

int Depth(int u){
   int d = 0;
   
  while(1){
     
    u = trees[u].parent;
    if ( u == -1 ) break;
    d++;
     
  }
  return d;
   
}

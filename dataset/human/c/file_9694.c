#include <stdio.h>
#define MAX 100000
#define NIL -1

struct Node {
    int parent;
    int left;
    int right;
};

struct Node gNode[MAX];
int gDepth[MAX];

void print(int node){
  int i,left;
  printf("node %d: ",node);
  printf("parent = %d, ",gNode[node].parent);
  printf("depth = %d, ",gDepth[node]);
    
  if(gNode[node].parent == NIL){
    printf("root, ");
  }
  else if(gNode[node].left == NIL){
    printf("leaf, ");
  }
  else{
    printf("internal node, ");
  }
  printf("[");
    
    for(i=0,left=gNode[node].left;left!=NIL;i++,left=gNode[left].right){
      if(i) {
	printf(", ");
      }
        printf("%d",left);
    }
    printf("]\n");
}

void rec(int node ,int parent){
    gDepth[node]=parent;
    if(gNode[node].right!=NIL){
        rec(gNode[node].right,parent);
    }
    if(gNode[node].left!=NIL){
        rec(gNode[node].left,parent+1);
    }
}

int main(){
  int nodeNum,nodeIndex,node,left,root,n,i,j;
    scanf("%d",&n);
    for(i = 0;i < n;++i){
        gNode[i].parent = gNode[i].left = gNode[i].right = NIL;
    }
    for(i = 0;i < n;++i){
      scanf("%d%d",&nodeIndex,&nodeNum);
        for(j=0;j<nodeNum;++j){
	  scanf("%d",&node);
            if(j == 0){
                gNode[nodeIndex].left = node;
            }
            else{
                gNode[left].right = node;
            }
            left = node;
            gNode[node].parent = nodeIndex;
        }
    }    
    for(i = 0;i < n;++i){
        if(gNode[i].parent == NIL){
            root = i;
        }
    }
    rec(root,0);
    for(i = 0;i < n;++i){
        print(i);
    }
    return 0;
}

#include <stdio.h>
#define MAX 100000
#define NIL -1

void rec(int,int);
void print(int);
struct Node{
  int parent;
  int left;
  int right;
};

struct Node gNode[MAX];
int gDepth[MAX];

int main(){

  int nodeNum,nodeIndex,node,left,root,n,i,j;
  scanf("%d",&n);
  //初期化
  for(i=0;i<n;i++){
    gNode[i].parent=gNode[i].left=gNode[i].right=NIL;
  }
  //nodeに代入
  for(i=0;i<n;i++){
    scanf("%d%d",&nodeIndex,&nodeNum);
    for(j=0;j<nodeNum;j++){
      scanf("%d",&node);
      if(j==0){
	gNode[nodeIndex].left=node;
      }
      else{
	gNode[left].right=node;
      }
      left=node;
      gNode[node].parent=nodeIndex;
    }
  }
  //rootを探す
  for(i=0;i<n;i++){
    if(gNode[i].parent==NIL){
      root=i;
    }
  }
  //根からはじまって深さを代入
  rec(root,0);

  //nodeのindexごと出力する
  for(i=0;i<n;i++){
    print(i);
  
  }
  return 0;
}

  void rec(int node, int parent){
  
    gDepth[node]=parent;
    if(gNode[node].right != NIL){
      //右の兄弟に同じ深さを設定
      rec(gNode[node].right,parent);
    }
    if(gNode[node].left != NIL){
      //最も左の子に自分の深さ+1を設定
      rec(gNode[node].left,parent+1);
    }
  }

  void print(int node){
    
    int left;
    printf("node %d: ",node);
    printf("parent = %d, ",gNode[node].parent);
    printf("depth = %d, ",gDepth[node]);

    if(gNode[node].parent==NIL)
      printf("root, ");

    else if(gNode[node].left==NIL)
      printf("leaf, ");
   
    else printf("internal node, ");

    printf("[");

    for(left = gNode[node].left; left != NIL; left = gNode[left].right){
      printf("%d",left);
      if(gNode[left].right!=-1)printf(", ");
    }
    printf("]\n");
  }

#include <stdio.h>
#define MAX 100001
#define NIL -1 /*use to show there no any input*/

typedef struct{
  int parent,left,right;
}Record;
int dep[MAX];

void depth(int, int, Record*);
int main(){
  int i,j,num,id,childnum,child,prechild,root;
  Record data[MAX];
  scanf("%d",&num);
  for(i=0;i<num;i++){
    data[i].parent=NIL;
    data[i].left=NIL;
    data[i].right=NIL;
  }
  
  for(i=0;i<num;i++){
    scanf("%d%d",&id,&childnum);
    for(j=0;j<childnum;j++){
      scanf("%d",&child);
      if(j==0) data[id].left=child;
      else data[prechild].right=child;
      prechild=child;
      data[child].parent=id;
    }
  }
  for(i=0;i<num;i++){
    if(data[i].parent==NIL){
      root=i;
      break;
    }
  }
  depth(root,0,data);

  for(i=0;i<num;i++){
    printf("node %d: parent = %d, ",i,data[i].parent);
    printf("depth = %d, ",dep[i]);
    if(i==root) printf("root, ");
    else if(data[i].left==NIL) printf("leaf, ");
    else printf("internal node, ");
    printf("[");
    child=data[i].left;
    for(j=0;child!=NIL;j++){
      if(j>0) printf(", ");
      printf("%d",child);
      child=data[child].right;
    }
    printf("]\n");
  }
  return 0;
}	

void depth(int x, int y, Record *data){
  dep[x]=y;
  if(data[x].right!=NIL) depth(data[x].right,y,data);
  if(data[x].left!=NIL) depth(data[x].left,y+1,data);
}

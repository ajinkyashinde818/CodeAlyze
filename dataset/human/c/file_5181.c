#include <stdio.h>
#define MAX 25
#define NIL -1 /*use to show there no anything*/

typedef struct{
  int parent,left,right;
}Record;
int dep[MAX],heig[MAX];

void depth(int, int, Record*);
int  height(int, Record*);
int main(){
  int i,j,num,id,root,lef,rig,deg[MAX];
  Record data[MAX];
  scanf("%d",&num);
  for(i=0;i<num;i++) {
    data[i].parent=NIL;
    deg[i]=0;
  }
  
  for(i=0;i<num;i++){
    scanf("%d%d%d",&id,&lef,&rig);
    data[id].left=lef;
    data[id].right=rig;
      
    if(lef!=NIL) {
      data[lef].parent=id;
      deg[id]++;
    }
    if(rig!=NIL){
      data[rig].parent=id;
      deg[id]++;
    }
  }
  for(i=0;i<num;i++){
    if(data[i].parent==NIL){
      root=i;
      break;
    }
  }
  depth(root,0,data);
  height(root,data);
  for(i=0;i<num;i++){
    printf("node %d: parent = %d, ",i,data[i].parent);
    printf("sibling = ");
    if(data[i].parent==NIL)printf("%d, ",NIL);
    else if(data[data[i].parent].left!=NIL && data[data[i].parent].left!=i){
      printf("%d, ",data[data[i].parent].left);
    }
    else if(data[data[i].parent].right!=NIL && data[data[i].parent].right!=i){
      printf("%d, ",data[data[i].parent].right);
    }
    else printf("%d, ",NIL);
    printf("degree = %d, ",deg[i]);
   
    printf("depth = %d, ",dep[i]);
    printf("height = %d, ",heig[i]);
    if(i==root) printf("root");
    else if(data[i].left==NIL && data[i].right==NIL) printf("leaf");
    else printf("internal node");
   
    printf("\n");
  }
  return 0;
}	

void depth(int x, int y, Record *data){
  if(x==NIL) return;
  dep[x]=y;
  depth(data[x].left,y+1,data);
  depth(data[x].right,y+1,data);
 
}

int height(int x, Record *data){
  int height1=0,height2=0;
  if(data[x].left!=NIL) height1=height(data[x].left,data)+1;
  if(data[x].right!=NIL) height2=height(data[x].right,data)+1;
  if(height1>height2) heig[x]=height1;
  else heig[x]=height2;
  return heig[x];
}

//Binary Tree
#include <stdio.h>
#define NIL -1
int setHeight(int );
void setDepth(int ,int );
int getSibling(int );
typedef struct{
  int parent,left_child,right_child,height,depth;
}Tree;

Tree Node[25];
int n;

int main(void){
  int i,j,node,left,right,degree;
  scanf("%d",&n);

  i=0;
  while(i<n){
    Node[i].parent=NIL;
    Node[i].left_child=NIL;
    Node[i].right_child=NIL;
    i++;
  }

  i=0;
  while(i<n){
    scanf("%d%d%d",&node,&left,&right);
    Node[node].left_child=left;
    Node[node].right_child=right;
    if(Node[node].left_child!=NIL)
      Node[Node[node].left_child].parent=node;
    if(Node[node].right_child!=NIL)
      Node[Node[node].right_child].parent=node;
    i++;
  }

  i=0;
  while(i<n){
    //find element of root
    if(Node[i].parent==NIL)
      j=i;
    i++;
  }

  setHeight(j);
  setDepth(j,0);


  i=0;
  while(i<n){
    printf("node %d: parent = %d, sibling = %d, ",i,Node[i].parent,getSibling(i));
    degree=0;
    if(Node[i].left_child!=NIL)degree++;
    if(Node[i].right_child!=NIL)degree++;
    printf("degree = %d, depth = %d, height = %d, ",degree,Node[i].depth,Node[i].height);
    if(Node[i].parent==NIL)
      printf("root");
    else if(Node[i].left_child==NIL && Node[i].right_child==NIL)
      printf("leaf");
    else printf("internal node");
    printf("\n");
    i++;
  }
  return 0;
}

int setHeight(int node){
  int height1=0,height2=0;
  //If there is(are) a child(s) of left or right, height is added 1
  if(Node[node].left_child!=NIL)
    height1=setHeight(Node[node].left_child)+1;
  if(Node[node].right_child!=NIL)
    height2=setHeight(Node[node].right_child)+1;
  if(height1>height2)
    Node[node].height=height1;
  else Node[node].height=height2;
  return Node[node].height;
}

void setDepth(int node,int deep){
  if(node!=NIL){
    Node[node].depth=deep;
    setDepth(Node[node].left_child,deep+1);
    setDepth(Node[node].right_child,deep+1);
  }
}

int getSibling(int node){
  if(Node[node].parent==NIL)return NIL;
  if(Node[Node[node].parent].left_child!=node && Node[Node[node].parent].left_child!=NIL)
    return Node[Node[node].parent].left_child;
  if(Node[Node[node].parent].right_child!=node && Node[Node[node].parent].right_child!=NIL)
    return Node[Node[node].parent].right_child;
  return NIL;
}

#include <stdio.h>
#define NIL -1

struct Node{
  int parent;
  int left;
  int right;
};

void getDepth(int, int);
int getHeight(int);
int getSibling(int);
int getDegree(int);
void printType(int);

struct Node t[25];
int Depth[25];
int Height[25];
int height1=0, height2=0;

int main(){

  int n, id, vec, left, right, root;
  int i, j, k;

  scanf("%d", &n); //n=節点の数
  
  for(i=0; i<n; i++) t[i].parent =t[i].left =t[i].right =NIL;
  
  for(i=0; i<n; i++){
    scanf("%d %d %d", &vec, &left, &right);
    
    t[vec].left=left; t[vec].right=right;
    
    if(left!=NIL) t[left].parent=vec;
    if(right!=NIL) t[right].parent=vec;
  }

  for(i=0; i<n; i++){
    if(t[i].parent==NIL) root=i;
  }

  getDepth(root, 0);

  for(i=0; i<n; i++){

    printf("node %d: ", i);
    printf("parent = %d, ", t[i].parent);
    printf("sibling = %d, ",getSibling(i));
    printf("degree = %d, ", getDegree(i) );
    printf("depth = %d, ", Depth[i]);
    printf("height = %d, ", getHeight(i) );
    printType(i);

  }
  return 0;
}

void getDepth(int x, int d){

  if(x==NIL) return; //一番底に来たとき

  Depth[x]=d;
  getDepth( t[x].left, d+1);
  getDepth( t[x].right, d+1);
}

int getHeight(int x){

  int height1=0, height2=0; //右と左にそれぞれ子がいないか確かめる
  int height;

  if(t[x].right ==NIL && t[x].left==NIL) Height[x]=0;
  else{
  if(t[x].left != NIL){
    
    height1=getHeight( t[x].left)+1;
  }
  if( t[x].right != NIL){

    height2=getHeight( t[x].right)+1;
  }
  }
  if(height1 < height2) height=height2;
  else height=height1;

  return height;
}

int getSibling(int x){

  if( t[x].parent == NIL) return NIL;

  else if(  t[ t[x].parent ].left ==  x && t[ t[x].parent ].right != NIL){
    //xが親の左の子で、右の子がNILでないとき、右の子を返す
    return t[ t[x].parent ].right;
  }
  else if( t[ t[x].parent ].right == x && t[ t[x].parent ].left != NIL){
    return t[ t[x].parent ].left;
  }
  return NIL;
}

int getDegree(int x){

  if(t[x].right ==NIL && t[x].left==NIL) return 0;
  else if(t[x].right !=NIL && t[x].left !=NIL) return 2;
  else return 1; 
}
void printType(int x){

  if(t[x].parent == NIL) printf("root\n");
  else if(t[x].left == NIL && t[x].right == NIL) printf("leaf\n");
  else printf("internal node\n");

}

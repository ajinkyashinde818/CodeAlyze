#include <stdio.h>
#define NIL -1
typedef struct{
  int parent;
  int left;
  int right;
  int depth;
  int sibling;
  int degree;
  int height;
} data;

void preparse(int);
void sibling(int,int,int);
void degree(int);
int height(int);
data A[25];
int B[25];
int main(){
  int N,i,id,l,r,root;

  scanf("%d",&N);

  for(i=0;i<N;i++) {
    A[i].parent=NIL;
    A[i].sibling=NIL;
  }
    for(i=0;i<N;i++){
    scanf("%d%d%d",&id,&l,&r);
    
    A[id].left=l;
    A[id].right=r;
    if(l!=NIL) A[l].parent=id;
    if(r!=NIL) A[r].parent=id;
    }
    for(i=0;i<N;i++){
      if(A[i].parent==NIL) root=i;
	}
 
    preparse(root);
  sibling(root,A[root].right,A[root].left);
  degree(root);
  height(root);
  
  for(i=0;i<N;i++){ printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,A[i].parent,A[i].sibling,A[i].degree,A[i].depth,A[i].height);  
    if(A[i].parent==NIL) printf("root\n");
    else if(A[i].right==NIL&&A[i].left==NIL) printf("leaf\n");
    else if((A[i].right!=NIL&&A[i].left==NIL)||(A[i].right==NIL&&A[i].left!=NIL)||(A[i].right!=NIL&&A[i].left!=NIL))printf("internal node\n");
  
  }
  return 0;
}

void preparse(int u){
  static int count;
 
  if(u==NIL) return;

  A[u].depth=count;
  count++;
  preparse(A[u].left);
  preparse(A[u].right);
  count--;
}

void sibling(int u,int r,int l){
  int i;
 
  if(u==NIL) return;


  if(A[u].left!=NIL && A[u].right!=NIL) {

    A[l].sibling=A[u].right;   
    A[r].sibling=A[u].left;
  }

  sibling(A[u].left,A[l].right,A[l].left);
  sibling(A[u].right,A[r].right,A[r].left);
  
}
  
void degree(int u){
  if(u==NIL) return;
  if(A[u].left!=NIL && A[u].right!=NIL) A[u].degree=2;
  else if((A[u].left==NIL && A[u].right!=NIL) || (A[u].left!=NIL && A[u].right==NIL)) A[u].degree=1;
  else A[u].degree=0;

  degree(A[u].left);
  degree(A[u].right);
}

int height(int u){
  int h1=0,h2=0;
  if(A[u].left!=NIL) h1=height(A[u].left)+1;
  if(A[u].right!=NIL) h2=height(A[u].right)+1;

if(h1>h2) B[u]=h1;
      else B[u]=h2;
 A[u].height=B[u];
 
 return B[u]; 
}

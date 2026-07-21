#include <stdio.h>

#define MAX 100005
#define R -1

typedef struct{
  int parent;
  int right; //??????
  int left;  //??????
}Node;

Node A[MAX];
int n;
int B[MAX];
int C[MAX];

void depth(int u,int p){
  B[u]=p;
  if(A[u].right!=R) depth(A[u].right,p);
  if(A[u].left!=R) depth(A[u].left,p+1);
}
void print2(int i){
  int c,j;
  c=A[i].left;
  for(j=0,c=A[i].left;c!=R;j++,c=A[c].right){
    if(j)printf(", ");
    printf("%d",c);
  }
}

void print(){
  int i;
  for(i=0;i<n;i++){
    printf("node %d: ",i);
    printf("parent = %d, ",A[i].parent);
    printf("depth = %d, ",B[i]);
    if(A[i].parent==R) printf("root, ");
    else if(A[i].left==R) printf("leaf, ");
    else printf("internal node, ");
    printf("[");
    print2(i);
    printf("]\n");
  }
}

int main(int argc, char const *argv[]) {
  int i,j,root,cnt,r=0,c,x,s;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    A[i].parent=R;
    A[i].left=R;
    A[i].right=R;
  }
  for(i=0;i<n;i++){
    scanf("%d",&root);
    scanf("%d",&C[i]);
    for(j=0;j<C[i];j++){
      scanf("%d",&c);
      A[c].parent=root;
      if(j==0) A[root].left=c;
      else A[x].right=c;
      x=c;
    }
  }
  for(i=0;i<n;i++){
    if(A[i].parent==R) s=i;
  }
  depth(s,0);
  print();
  return 0;
}

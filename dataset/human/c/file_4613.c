#include <stdio.h>

#define MAX 100005
#define R -1

typedef struct{
  int parent;
  int right;
  int left;
}Node;

Node A[MAX];
int n;
int B[MAX];
int C[MAX];

int height(int u){
  int x1=0,x2=0;
  if(A[u].left!=R) x1=height(A[u].left)+1;
  if(A[u].right!=R) x2=height(A[u].right)+1;
  return C[u]=(x1>x2 ? x1:x2);
}

void depth(int u,int p){
  if(u==R) return;
  B[u]=p;
  depth(A[u].right,p+1);
  depth(A[u].left,p+1);
}

int getsibling(int u){
  //A[u]???root??????????????????????????????R????????????
  if(A[u].parent==R) return R;
  //A[u]?????????????????????A[u]????????§?????????????????????????????????????????£???????????°????????????????????????
  if(A[A[u].parent].left != u && A[A[u].parent].left!=R)
    return A[A[u].parent].left;
  if(A[A[u].parent].right != u && A[A[u].parent].right!=R)
      return A[A[u].parent].right;
  return R;
}
/*void print2(int i){
  int c,j;
  c=A[i].left;
  for(j=0,c=A[i].left;c!=R;j++,c=A[c].right){
    if(j)printf(", ");
    printf("%d",c);
  }
}
*/
void print(){
  int i,flag1=0,flag2=0;
  for(i=0;i<n;i++){
    printf("node %d: ",i);
    printf("parent = %d, ",A[i].parent);
    printf("sibling = %d, ",getsibling(i));
    if(A[i].left!=R) flag1=1;
    if(A[i].right!=R) flag2=1;
    printf("degree = %d, ",flag1+flag2);
    flag1=0;
    flag2=0;
    printf("depth = %d, ",B[i]);
    printf("height = %d, ",C[i]);
    if(A[i].parent==R) printf("root\n");
    else if(A[i].left==R && A[i].right==R) printf("leaf\n");
    else printf("internal node\n");
  /*  printf("[");
    print2(i);
    printf("]\n");
    */
  }
}

int main(int argc, char const *argv[]) {
  int i,j,root,x,y,s;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    A[i].parent=R;
    A[i].left=R;
    A[i].right=R;
  }
  for(i=0;i<n;i++){
    scanf("%d",&root);
    scanf("%d",&x);
    scanf("%d",&y);
    A[root].left=x;
    A[root].right=y;
    if(x!=R) A[x].parent=root;
    if(y!=R) A[y].parent=root;
  }

  for(i=0;i<n;i++){
    if(A[i].parent==R) s=i;
  }
  depth(s,0);
  height(s);
  print();
  return 0;
}

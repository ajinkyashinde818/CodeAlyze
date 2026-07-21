#include<stdio.h>
#define MAX 10001
typedef struct{
  int parent, left, right;
} Tree;
Tree T[MAX];
//int s=0,t=0;
#define NIL -1
int getheight(int);
void print(void);
int i,v,j,n,k,depth=0,num,l,r,degree=0,height=0;

int main()
{

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].parent=NIL;
  }

  for(i=0;i<n;i++){
    scanf("%d%d%d",&v,&l,&r);
    T[v].left=l;
    T[v].right=r;
    if(l!=NIL && r!=NIL){
      T[l].parent=v;
      T[r].parent=v;
    }
    else if(l!=NIL && r==NIL){
      T[l].parent=v;
    }
    else if(l==NIL && r!=NIL){
      T[r].parent=v;
    }
  }

  for(i=0;i<n;i++){
    printf("node %d: parent = %d, ",i,T[i].parent);
    if(T[i].parent==NIL){
      printf("sibling = -1, ");
    }
    else if(T[T[i].parent].left==i){
      printf("sibling = %d, ",T[T[i].parent].right);
    }
    else{
      printf("sibling = %d, ",T[T[i].parent].left);
    }
    printf("degree = ");
    if(T[i].left!=NIL && T[i].right!=NIL){
      printf("2, ");
    }
    else if(T[i].left==NIL && T[i].right==NIL){
      printf("0, ");
    }
    else printf("1, ");

    num=i;
    while(T[num].parent!=NIL){
      depth++;
      num=T[num].parent;
    }
    printf("depth = %d, ",depth);
    depth=0;

    printf("height = ");
    height=getheight(i);
    printf("%d,",height);
    //s=0;t=0;

    if(T[i].parent==NIL){
      printf(" root\n");
    }
    else if(T[i].left==NIL && T[i].right==NIL){
      printf(" leaf\n");
    }
    else {
      printf(" internal node\n");
      }
  }
  return 0;
}

int getheight(int i)
{
  int s=0,t=0;
  if(T[i].left==NIL && T[i].right==NIL)return 0;

  if(T[i].left!=NIL){
  s=getheight(T[i].left)+1;
  }
  if(T[i].right!=NIL){
  t=getheight(T[i].right)+1;
  }
  if(s>t){
    return s;
  }
  else{
    return t;
  }
}

void print(){
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, ",i,T[i].parent);
    if(T[i].parent==NIL){
      printf("sibling = -1, ");
    }
    else if(T[T[i].parent].left==i){
      printf("sibling = %d, ",T[T[i].parent].right);
    }
    else{
      printf("sibling = %d, ",T[T[i].parent].left);
    }
    printf("degree = ");
    if(T[i].left!=NIL && T[i].right!=NIL){
      printf("2, ");
    }
    else if(T[i].left==NIL && T[i].right==NIL){
      printf("0, ");
    }
    else printf("1, ");

    num=i;
    while(T[num].parent!=NIL){
      depth++;
      num=T[num].parent;
    }
    printf("depth = %d, ",depth);
    depth=0;

    printf("height = ");
    height=getheight(i);
    printf("%d,",height);
    //s=0;t=0;

    if(T[i].parent==NIL){
      printf(" root\n");
    }
    else if(T[i].left==NIL && T[i].right==NIL){
      printf(" leaf\n");
    }
    else {
      printf(" internal node\n");
      }
  }
}

#include<stdio.h>
#define MAX 100005
#define NIL -1

typedef struct{
  int p,l,r,h,flag;
}Node;
Node T[MAX];

int depth(int);
int sub(int);
int deg(int);
int height(int);

int main(){

  int n,i,j,node,degree,child,left;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    T[i].p = NIL;
    T[i].l = NIL;
    T[i].r = NIL;
    T[i].h = 0;
    T[i].flag = 0;
  }
  for(i = 0; i < n; i++){
    scanf("%d",&node);
    for(j = 0; j < 2; j++){
      scanf("%d",&child);
      if(child != -1){
        T[child].p = node;
        if(j == 0)
          T[node].l = child;
        else
          T[node].r = child;


      }
    }
  }

  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth\
 = %d, height = %d, ",i,T[i].p,sib(i),deg(i),depth(i),height(i));
    if(T[i].p == NIL)
      printf("root\n");
    else if(T[i].l == NIL && T[i].r == NIL)
      printf("leaf\n");
    else
      printf("internal node\n");
    //    print_degree(T[i].l);
  }
  return 0;
}

int depth(int node){

  int count=0;

  while(T[node].p != NIL){
    count++;
    node = T[node].p;
  }
  return count;
}

int sib(int i){

  int parent,right,left;

  parent = T[i].p;
  left = T[parent].l;
  right = T[parent].r;

  if(parent == -1)
    return -1;
  if(i == left)
    return right;
  else
    return left;
}

int deg(int i){

  int parent,count=0;

  if(T[i].l != NIL)
    count++;
  if(T[i].r != NIL)
    count++;
  return count;
}

int height(int i){

  int left = 0,right = 0;

  if(T[i].l != NIL){
    left = height(T[i].l) + 1;
  }
  if(T[i].r != NIL){
    right = height(T[i].r) + 1;
  }
  if(right > left)
    return right;
  else
    return left;
}

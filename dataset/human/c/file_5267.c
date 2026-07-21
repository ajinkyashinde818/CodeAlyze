#include<stdio.h>
#include<stdlib.h>
#define NIL -1
#define MAX 25

typedef struct node{
  int l;
  int r;
  int p;
}Node;

void print(int);
void calcDepth(int , int );
int calcSib(int);
int calcHeight(int);

Node T[MAX];
int D[MAX];
int H[MAX];

int main(){
  int i,j;
  int n,id,l,r;
  int root = NIL;

  scanf("%d",&n);
  for(i = 0; i < n; i++)T[i].l = T[i].r = T[i].p = NIL;//treeの初期化 
  
  for(i = 0;i < n; i++){
    scanf("%d",&id);//節点の情報追加
    //printf("test 0 in for scanf\n");
    if(i == 0)T[id].p = NIL;
    for(j = 0; j < 1; j++){
      scanf(" %d %d",&l,&r);
      T[id].l = l;
      T[id].r = r;
      T[l].p = T[r].p = id;
    }
  }
  
  //printf("test1 入力\n");
  for(i = 0; i < n; i++){
    if(T[i].p == NIL)root = i;
  }
  //printf("test2 root\n");
  
  calcDepth(root , 0);
  calcHeight(root);
  
  for(i = 0; i < n; i++)print(i);

  return 0;
}

void print(int u){
  int deg,sib,dep;

  deg = NIL;
  
  if(T[u].l == NIL && T[u].r == NIL)deg = 0;//degの調整
  else if(T[u].r != NIL && T[u].l != NIL)deg = 2;
  else deg = 1;

  sib = NIL;
  if(T[u].p == NIL)sib = NIL;
  else sib = calcSib(u);
  
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d,",u,T[u].p,sib,deg,D[u],H[u]);
  
  if(T[u].l == NIL && T[u].r == NIL){
    if(T[u].p == NIL)printf(" root\n");
    else printf(" leaf\n");//typeのprint
  }
  else if(T[u].p == NIL)printf(" root\n");
  else printf(" internal node\n");
  
}

int calcSib(int u){
  
  if(T[T[u].p].l == NIL && T[T[u].p].r == NIL)return NIL;
  if(T[T[u].p].l != u && T[T[u].p].l != NIL){
    return T[T[u].p].l;
  }
  if(T[T[u].p].r != u && T[T[u].p].r != NIL){
    return T[T[u].p].r;
  }
  return NIL;
}

void calcDepth(int u, int p){
  
  D[u] = p;
  if(T[u].l != NIL)calcDepth(T[u].l,p+1);
  if(T[u].r != NIL)calcDepth(T[u].r,p+1);
}

int calcHeight(int u){
  int height_l = 0,height_r = 0;
  
  
  if(T[u].l != NIL)height_l = calcHeight(T[u].l) + 1;
  if(T[u].r != NIL)height_r = calcHeight(T[u].r) + 1;

  if(height_l >= height_r)H[u] = height_l;
  else H[u] = height_r;

  return H[u];
}

#include<stdio.h>
#include<stdlib.h>
#define MAX 100005
#define NIL -1

struct Node{
  int p,l,r,cn;
  int *chil;
  //int chil[100];
};

struct Node T[MAX];

int getDepth(int u){
  int d = 0;
  while(T[u].p != NIL){
    u = T[u].p;
    d++;
  }
  return d;
}

void printChildren(int u){
  int i;

  printf("node %d: parent = %d, depth = %d, ",u,T[u].p,getDepth(u));

  if(T[u].p == NIL) printf("root, [");
  else if(T[u].l == NIL) printf("leaf, [");
  else printf("internal node, [");

  if (T[u].cn == 0) printf("]\n");
  else {
    for(i=0; i<T[u].cn-1; i++){
      printf("%d, ",T[u].chil[i]);
    }
    printf("%d]\n",T[u].chil[i]);
  }
}

int main(){
  int i,j;
  int n,num,quo;
  int l;

  scanf("%d",&n);

  for(i=0; i<n; i++) T[i].p = T[i].l = T[i].r = NIL;

  for(i=0; i<n; i++){
    scanf("%d%d",&num,&quo);
    T[num].cn = quo;
    if (T[num].cn > 0){
      T[num].chil = (int *)malloc(T[num].cn*sizeof(int));
    }
    for(j=0; j<quo; j++){
      scanf("%d",&T[num].chil[j]);
      if(j == 0) T[num].l = T[num].chil[j];
      else T[l].r = T[num].chil[j];
      l = T[num].chil[j];
      T[T[num].chil[j]].p = num;
    }
  }
  
  for(i=0; i<n; i++) printChildren(i);

  return 0;
}

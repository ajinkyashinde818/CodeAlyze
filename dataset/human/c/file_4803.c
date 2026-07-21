#include<stdio.h>
#define N 100000

typedef struct{
  int p,l,r;
} Node;

Node A[N];
int deep;
int sibling(int id){
  if(A[id].p == -1) return -1;
  else if(A[A[id].p].l == id) return A[A[id].p].r;
  else return A[A[id].p].l;
 
}
int degree(int id){
  int deg = 0;
  if(A[id].l != -1 ) deg++;
  if(A[id].r != -1 ) deg++;
  return deg;
}

int height(int id){
  int lheight=0,rheight=0;
  if(A[id].l != -1){
    lheight = height(A[id].l)+1;
  } 
  if(A[id].r != -1){
    rheight = height(A[id].r)+1;
  }
  if(lheight > rheight) return lheight;
  else return rheight;
  
}

int depth(int id){
  if( A[id].p == -1) return 0;
  else{
    deep++;
    depth(A[id].p); 
  }
  return deep;
}

void printType(int id){
  if(A[id].p == -1) printf("root");
  else if(A[id].l != -1 || A[id].r != -1) printf("internal node");
  else printf("leaf");
}

main(){
  int i,n;
  int v,d,c;

  scanf("%d",&n);

  for(i = 0; i < n; i ++){
    A[i].p = -1;
    A[i].l = -1;
    A[i].r = -1;
  }

  for(i = 0; i < n; i ++){
    scanf("%d%d%d",&v,&d,&c);
    if(d != -1)A[d].p = v;
    if(c != -1)A[c].p = v;
    A[v].l = d;
    A[v].r = c;
  }
 
  for(i = 0; i < n; i ++){ 
    deep=0;
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,A[i].p,sibling(i),degree(i),depth(i),height(i));
    printType(i);
    printf("\n");
  }
  return 0;
}

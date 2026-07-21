#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int p;
  int h;
  int dep;
  int deg;
  int left,right;
  int s;
}Tree;

Tree T[25];

void rootedtree(int);
void depth(int);
void height(int);

int main(){
  int n,id,i,j,root,hei;

  scanf("%d",&n);
  
  //T = malloc(sizeof(Tree) * n);
  
  for(i = 0; i < n; i++){
    T[i].p = -1;
    T[i].s = -1;
    T[i].dep = 0;
    T[i].deg = 0;
  }
  
  for(i = 0; i < n; i++){
    scanf("%d",&id);
    rootedtree(id);
  }
  
 for(i = 0; i < n; i++){
   if(T[i].p == -1) root = i;
 }
 
 depth(root);

 for(i = 0; i < n; i++){
   if(T[i].deg == 0 ){
     T[i].h=0;
     if(T[i].p != -1)
       height(i);
   }
 }
 
 for(i = 0; i < n; i++){
   printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,T[i].p,T[i].s,T[i].deg,T[i].dep,T[i].h);
   if(T[i].dep == 0) printf("root");
   else if(T[i].deg > 0) printf("internal node");
   else printf("leaf");
   printf("\n");
   
 }
 
 //free(T);
 
 return 0;
}

void rootedtree(int id){
  int i;
  scanf("%d%d",&T[id].left,&T[id].right);
  
  if(T[id].left != -1 && T[id].right != -1)
    T[id].deg = 2;
  if(T[id].left != -1 && T[id].right == -1)
    T[id].deg = 1;
  if(T[id].left == -1 && T[id].right != -1)
    T[id].deg = 1;
  T[T[id].left].s = T[id].right;
  T[T[id].left].p = id;
  T[T[id].right].s = T[id].left;
  T[T[id].right].p = id;
}

void depth(int id){
  if(T[id].deg > 0){
    if(T[id].left != -1){
      T[T[id].left].dep = T[id].dep + 1;
      depth(T[id].left);
    }
    if(T[id].right != -1){
      T[T[id].right].dep = T[id].dep + 1;
      depth(T[id].right);
    }
  }
}

void height(int id){
  if( T[T[id].p].h < T[id].h + 1){
    T[T[id].p].h = T[id].h + 1;
    if( T[T[id].p].p != -1)
      height(T[id].p);
  }
}

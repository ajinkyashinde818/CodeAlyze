#include<stdio.h>
#include<stdlib.h>
#define N 100001

typedef struct{
  int parent;
  int left;
  int right;
} Tree;
 
Tree T[N];
 
int sibilings(int);
int degree(int);
int depth_c(int);
int hight(int);
void print(int);
 int sibilings(int a){
  if(T[a].parent == -1){
    return -1;
  }
  else if(T[T[a].parent].left == a){
    return T[T[a].parent].right;
  }
  else return T[T[a].parent].left;
}
 
int degree(int b){
  if(T[b].left ==-1 && T[b].right == -1){
    return 0;
  }
  else if(T[b].left !=-1 && T[b].right != -1){
    return 2;
  }
  else
    return 1;
}
 
int depth_c(int c){
  int count = 0;
  if(T[c].parent == -1){
    return 0;
  }
  else{
    count = depth_c(T[c].parent) + 1;
    return count;
  }
}
 
int hight(int z){
  int ah = 0, bh = 0;
  if(T[z].left != -1){
    ah = hight(T[z].left) + 1;
  }
   if(T[z].right != -1){
    bh = hight(T[z].right) + 1;
  }
   if(ah < bh){
     return bh;
   }
   else
     return ah;
}
 
void print(int f){
  printf("node %d: parent = %d, sibling = %d, degree = %d, ",f, T[f].parent, sibilings(f),degree(f));
  printf("depth = %d, height = %d, ",depth_c(f),hight(f));
  if(T[f].parent == -1){
    printf("root\n");
  }
  else if(T[f].left == -1 && T[f].right == -1){
    printf("leaf\n");
  }
  else
    printf("internal node\n");
}

main(){
  int i,j,p,l,r,n;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    T[i].parent = -1;
    T[i].left = -1;
    T[i].right = -1;
  }
  for(i=0; i<n; i++){
    scanf("%d%d%d",&p,&l,&r);
    T[l].parent = p;
    T[r].parent = p;
    T[p].left = l;
    T[p].right = r;
   }
  for(i=0; i<n; i++){
    print(i);
   }
  return 0;
}

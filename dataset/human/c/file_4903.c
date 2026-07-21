#include<stdio.h>
#include<stdlib.h>
 
typedef struct{
  int parent;
  int left;
  int right;
} Tree;
  
Tree T[1000000];
  
int sibilings(int);
int degree(int);
int depth_c(int);
int hight(int);
void print(int);
 int sibilings(int n){
  if(T[n].parent == -1){
    return -1;
  }
  else if(T[T[n].parent].left == n){
    return T[T[n].parent].right;
  }
  else return T[T[n].parent].left;
}
  
int degree(int m){
  if(T[m].left ==-1 && T[m].right == -1){
    return 0;
  }
  else if(T[m].left !=-1 && T[m].right != -1){
    return 2;
  }
  else
    return 1;
}
  
int depth_c(int l){
  int count = 0;
  if(T[l].parent == -1){
    return 0;
  }
  else{
    count = depth_c(T[l].parent) + 1;
    return count;
  }
}
  
int hight(int i){
  int ah = 0, bh = 0;
  if(T[i].left != -1){
    ah = hight(T[i].left) + 1;
  }
   if(T[i].right != -1){
    bh = hight(T[i].right) + 1;
  }
   if(ah < bh){
     return bh;
   }
   else
     return ah;
}
  
void print(int j){
  printf("node %d: parent = %d, sibling = %d, degree = %d, ",j, T[j].parent, sibilings(j),degree(j));
  printf("depth = %d, height = %d, ",depth_c(j),hight(j));
  if(T[j].parent == -1){
    printf("root\n");
  }
  else if(T[j].left == -1 && T[j].right == -1){
    printf("leaf\n");
  }
  else
    printf("internal node\n");
}
 
main(){
  int i, j, p, l, r, n;
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

#include<stdio.h>
 
#define N 25
 
typedef struct{
  int p,s,deg,dep,h,left,right;
}Node;
 
int depth(Node *, int);
int height(Node *, int);
 
int main(){
  int i,n,id;
  Node T[N],tmp;
 
  scanf("%d",&n);
  for(i=0; i<n; i++){
    T[i].p = -1;
    T[i].dep = 0;
    T[i].deg = 0;
    T[i].s = -1;
  }
  for(i=0; i<n; i++){
    scanf("%d",&id);
    scanf("%d%d", &T[id].left, &T[id].right);
    T[T[id].left].p = id;
    T[T[id].right].p = id;
    if(T[id].left != -1){
      T[id].deg++;
      T[T[id].left].s = T[id].right;
    }
     if(T[id].right != -1){
      T[id].deg++;
      T[T[id].right].s = T[id].left;
    }
  }
 
  for(i=0; i<n; i++){
    T[i].dep = depth(T,i);
    T[i].h = height(T,i);
  }
   
  for(i=0; i<n; i++){
    if(T[i].p == -1)  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, root\n", i, T[i].p, T[i].s, T[i].deg, T[i].dep, T[i].h);
    else if(T[i].deg != 0)  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, internal node\n" , i, T[i].p, T[i].s, T[i].deg, T[i].dep, T[i].h);
    else  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, leaf\n" , i, T[i].p, T[i].s, T[i].deg, T[i].dep, T[i].h);
  }
 
  return 0;
}
 
int depth(Node *T, int i){
 
  if(T[i].p == -1) return 0;
 
  return depth(T, T[i].p) + 1;
   
}
 
int height(Node *T, int i){
  int righth=0,lefth=0;
  if(T[i].right != -1) righth = height(T, T[i].right) + 1;
  if(T[i].left != -1) lefth = height(T, T[i].left) + 1;
  if(righth >= lefth) return righth;
  else return lefth;
}

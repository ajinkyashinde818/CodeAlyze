#include <stdio.h>
#define N 100000
 
typedef struct{
  int par;
  int left;
  int right;
}node;
 
node T[N];
int dep(int);
int hei(int);
 
int main(){
  int i,j,n,a;
 
  scanf("%d",&n);
 
  for(i=0; i<n; i++) T[i].par = T[i].left = T[i].right =-1;
 
  for(i=0; i<n; i++){
    scanf("%d",&a);
    scanf("%d %d", &T[a].right, &T[a].left);
    if(T[a].left != -1) T[T[a].left].par = a;
    if(T[a].right != -1) T[T[a].right].par = a;
  }
  
 for(i=0; i<n; i++){
    printf("node %d: parent = %d, sibling = ", i ,T[i].par);
    if(T[i].par == -1){
      printf("-1, ");
    }
    else{
      if(T[T[i].par].left == i){
        printf("%d, ",T[T[i].par].right);
      }
      else{
        printf("%d, ",T[T[i].par].left);
      }
    }
 
    printf("degree = ");
    if(T[i].left == -1 && T[i].right == -1){
      printf("0, ");
    }  
 else{
      if(T[i].left != -1 && T[i].right != -1){
        printf("2, ");
      }
      else{
        printf("1, ");
      }
    }
    printf("depth = %d, height = %d, ", dep(i), hei(i));
 
    if(T[i].par == -1){
      printf("root");
    }
    else{
      if(T[i].left ==-1 && T[i].right == -1){
        printf("leaf");
      }
      else{
        printf("internal node");
      }
    }
    printf("\n");
  }
 
  return 0;
}
 
int dep(int n){
  if(T[n].par == -1) return 0;
  return dep(T[n].par)+1;
}
 
int hei(int n){
  int right=0,left=0;
 
  if(T[n].right == -1 && T[n].left == -1) return 0;
 
  if(T[n].right != -1) right = hei(T[n].right)+1;
  if(T[n].left != -1) left = hei(T[n].left)+1;
 
  if(left > right) return left;
  else return right;
}

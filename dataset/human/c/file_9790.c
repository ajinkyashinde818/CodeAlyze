#include <stdio.h>
#define NIL -1
#define N 100005
 
 struct Node{
  int p;
  int l;
  int r;
};
struct Node A[N];

int depth(int);
int child(int);
 
int main()
{
 
 
  int i,j;
  int n,id,d,c,k;
  scanf("%d",&n);
   
  for(i = 0; i < n; i++){
   A[i].p = NIL;
   A[i].l = NIL;
   A[i].r = NIL;
  }
  for(i = 0; i < n; i++){
    scanf("%d %d",&id,&d);
    for(j = 0; j < d; j++){
      scanf("%d",&c);
       
      A[c].p = id;
       
      if(j == 0){
    A[id].l = c;
      }
      
      else {
    A[k].r = c;
      }
      
      k = c;
    }
  }
 
  for(i = 0; i < n; i++){
 
    printf("node %d: parent = %d, depth = %d, ",i,A[i].p,depth(i));
     
    
    if(A[i].p == NIL){
      printf("root, [");
    }
    else if(A[i].l == NIL){
      printf("leaf, [");
    }
    
    else {
    printf("internal node, [");
    }
    child(A[i].l);
    printf("]\n");
  }
  return 0;
}
 
 
int depth(int x)
{
  int a;
   
  if(A[x].p == NIL){
    return 0;
  }
  else {
  	
    a = depth(A[x].p) + 1;
    return a;
  }
}
 
int child(int x)
{
  if(x==NIL){
    return 0;
  }
  
  else {
    if(A[x].r == NIL){
      printf("%d",x);
    }
    else {
      printf("%d, ",x);
      child(A[x].r);
    }
   }
}

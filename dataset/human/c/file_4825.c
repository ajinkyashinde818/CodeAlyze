#include <stdio.h>
#define NIL -1
#define N 100006



struct Node{
  int p,l,r;
};
struct Node A[N];

int deep(int);
int brother(int);
int deg(int);
int height(int);


main()
{


  int i,j;
  int n,id,e,c;



  scanf("%d",&n);
  
  for(i = 0; i < n; i++){
   A[i].p = NIL;
   A[i].l = NIL;
   A[i].r = NIL;
  }
  for(i = 0; i < n; i++){
    scanf("%d%d%d",&id,&e,&c);
    
    A[e].p = id;
    A[c].p = id;
    A[id].l = e;
    A[id].r = c;
  
  }
  
  for(i = 0; i < n; i++){
    
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,A[i].p,brother(i),deg(i),deep(i),height(i));
    
    if(A[i].p == NIL){
      printf("root\n");
    }
    else if(A[i].r == NIL && A[i].l == NIL){
      printf("leaf\n");
    }
    else {
      printf("internal node\n");
    }
  }
  return 0;
}

int deep(int s)
{
  int a;
  
  if(A[s].p == NIL){
    return 0;
  }
  else {
    a = deep(A[s].p) + 1;
    return a;
  }
}

int brother(int s)
{
  if(A[s].p == NIL){
    return NIL;
  }
  else {
    if(s == A[A[s].p].l){
      return A[A[s].p].r;
    }
    else {
      return A[A[s].p].l;
    }
  }
}

int deg(int s)
{
  
  if(A[s].l == NIL && A[s].r == NIL){
    return 0;
  }
  else if(A[s].r != NIL && A[s].l != NIL){
    return 2;
  }
  else {
    return 1;
  }
}

int height(int s)
{

  int left=0, right=0;

  if(s == NIL){
    return 0;
  }

  if(A[s].r != NIL){
    right = height(A[s].r) + 1;
  }
  
  if(A[s].l != NIL){
    left = height(A[s].l) + 1;
  }
  
  if(left > right){
    return left;
  }
  else {
    return right;
  }
}

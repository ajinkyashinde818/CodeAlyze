#include<stdio.h>
#define N -1
#define MAX 100001
 
struct Node{
  int p,l,r;
};
 
struct Node T[MAX];
int A[MAX];
 
int dep(int);
int sib(int);
int deg(int);
int hei(int);
 
main(void){
  int P;
  int n;
  int i;
   
  scanf("%d",&n);
   
  for(i=0;i<n;i++){
    T[i].p=T[i].l=T[i].r=N;
  }
   
  for(i=0;i<n;i++){
    scanf("%d",&P);
    scanf("%d %d",&T[P].l,&T[P].r);
    T[T[P].l].p=P;
    T[T[P].r].p=P;
  }
   
  for(i=0;i<n;i++){
    A[i]=dep(i);
  }
   
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,T[i].p, sib(i), deg(i),A[i],hei(i));   
    if(T[i].p==N) printf("root\n");
    else if(T[i].l!=N||T[i].r!=N)printf("internal node\n");
    else printf("leaf\n");
  }
  return 0;
}
 
 
int dep(int i){
  int c=0;
  while(T[i].p!=N){
    c=c+1;
    i=T[i].p;
  }
  return c;
}
 
 
int sib(int i){
  if(T[i].p==N) return N;
  if(T[T[i].p].r==i) return T[T[i].p].l;
  if(T[T[i].p].l==i) return T[T[i].p].r;
}
 
int deg(int i){
  int c=0;
  if(T[i].l!=N) c=c+1;
  if(T[i].r!=N) c=c+1;
  return c;
}
 
int hei(int i){
  int hl=0;
  int hr=0;
  if(T[i].l!=N) hl=hei(T[i].l)+1;
  if(T[i].r!=N) hr=hei(T[i].r)+1;
   
  if(hl<hr) return hr;
  else return hl;
}

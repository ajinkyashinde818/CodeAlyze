#include<stdio.h>
#define N -1
#define MAX 100001
  
struct Node{
  int p,l,r;
};
  
struct Node T[MAX];
int a[MAX];

int deg(int);
int he(int); 
int dep(int);
int si(int);

main(void){
  int P,n,i;

    
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
    a[i]=dep(i);

  }
    
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,T[i].p, si(i), deg(i),a[i],he(i));   
    if(T[i].p==N) printf("root\n");
    else if(T[i].l!=N||T[i].r!=N){
     printf("internal node\n");
    }
    else {
     printf("leaf\n");
   } 
  }
  return 0;
}
  
  
int dep(int i){
  int count=0;
  while(T[i].p!=N){
    count=count+1;
    i=T[i].p;
  }
  return count;
}
  
  
int si(int i){
  if(T[i].p==N){
  return N;
 }
  if(T[T[i].p].r==i){
  return T[T[i].p].l;
 }
  if(T[T[i].p].l==i){
  return T[T[i].p].r;
 }
}
  
int deg(int i){
  int count=0;
  if(T[i].l!=N){
   count=count+1;
 }
  if(T[i].r!=N){
   count=count+1;
 }
  return count;
}
  
int he(int i){
  int h1=0;
  int h2=0;
  if(T[i].l!=N){
   h1=he(T[i].l)+1;
  }

  if(T[i].r!=N){
   h2=he(T[i].r)+1;
  }
    
  if(h1<h2) return h2;
  else return h1;
}

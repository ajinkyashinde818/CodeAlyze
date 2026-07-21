#include<stdio.h>
#define N -1
#define MAX 100001

struct Node{
  int p,l,r;
};

struct Node T[MAX];
int A[MAX];

int depth(int);
int sibling(int);
int degree(int);
int height(int);

main(){
  int parent;
  int n;
  int i;
  
  scanf("%d",&n);
  
  for(i=0; i < n; i++){
    T[i].p = T[i].l = T[i].r = N;
  }
  
  for(i = 0; i < n; i++){
    scanf("%d",&parent);
    scanf("%d %d",&T[parent].l,&T[parent].r);
    T[T[parent].l].p = parent;
    T[T[parent].r].p = parent;
  }
  
  for(i = 0; i < n; i++){
    A[i] = depth(i);
  }
  
  for(i = 0; i<n; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,T[i].p, sibling(i), degree(i),A[i],height(i));    
    if(T[i].p == N) printf("root\n");
    else if(T[i].l != N || T[i].r != N)printf("internal node\n");
    else printf("leaf\n");
  } 
  return 0;
}


int depth(int i){
  int count = 0;
  while(T[i].p !=N){
    count++;
    i = T[i].p;
  }
  return count;
}


int sibling(int i){
  if(T[i].p == N) return N;
  if(T[T[i].p].r == i) return T[T[i].p].l;
  if(T[T[i].p].l == i) return T[T[i].p].r;
}

int degree(int i){
  int count = 0;
  if(T[i].l != N) count++;
  if(T[i].r != N) count++;
  return count;
}

int height(int i){
  int hl = 0;
  int hr = 0;
  if(T[i].l != N) hl = height(T[i].l) + 1;
  if(T[i].r != N) hr = height(T[i].r) + 1;
  
  if(hl < hr) return hr;
  else return hl;
}

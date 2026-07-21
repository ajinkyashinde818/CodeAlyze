#include<stdio.h>
#define MAX 10000
#define NOT   -1

struct Node{int p, l, r;};
struct Node T[MAX];
int n,H[MAX],A[MAX];

int getDepth(int);
int getSibling(int);
void Print(int);

int main( ){
  int i,j,k,l,v,c,r,p;
  scanf("%d",&n);
  for(i = 0; i<n; i++){
    T[i].p = NOT;
  }

  for(i = 0; i < n; i++){
    scanf("%d %d %d",&v, &l,&r);
    T[v].l =l;
    T[v].r = r;
    if( l != NOT){
      T[l].p = v;
    }
    if(r != NOT){
      T[r].p = v;
    }
  }

    for(i = 0; i < n; i++){
      A[i] = getDepth(i);
      H[i] = 0;
    }
    for(i = 0; i < n; i++){
      if(T[i].l == NOT && T[i].r == NOT){
	H[i] = 0;
	 p = T[i].p;
	 c = 1;
	 while(1){
	   if(p == NOT) break;
	   if(H[p] < c)
	     H[p] = c;
	   c++;
	   p = T[p].p;
	   
	 }
      }
    }

    for(i = 0; i < n; i++) Print(i);
    
    return 0;
  }

int getDepth(int u){
  int k = 0;
  while(1){
    u = T[u].p;
    if(u == NOT) break;
    k++;
  }
  return k;
}

void Print(int u){
  int i,c =0;
  printf("node %d: ",u);

  printf("parent = %d, ",T[u].p);
  printf("sibling = %d, ",getSibling(u));

  if(T[u].l != NOT) c++;
  if(T[u].r != NOT) c++;

  printf("degree = %d, ", c);
  printf("depth = %d, ", A[u]);
  printf("height = %d, ", H[u]);

  if ( T[u].p == NOT ){
    printf("root\n");
  }
  else if ( T[u].l == NOT && T[u].r == NOT ){
    printf("leaf\n");
  }
  else {
    printf("internal node\n");
  }
}

 int getSibling(int u){
  if(T[u].p == NOT)
    return NOT;
  if(T[T[u].p].l != u && T[T[u].p].l != NOT)
    return T[T[u].p].l;
  if(T[T[u].p].r != u && T[T[u].p].r != NOT)
    return T[T[u].p].r;
  return NOT;
}

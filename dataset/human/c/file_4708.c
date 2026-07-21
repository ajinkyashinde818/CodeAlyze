#include<stdio.h>

#define MAX 10000
#define NIL -1

struct Node{
  int p, l, r;
};

struct Node T[MAX];

int n,D[MAX],H[MAX];

int getdepth(int u){
  int d = 0;
  while(1){
    
    u = T[u].p;
    
    if( u == NIL ){
      break;
    }
    
    d++;
  }
  
  return d;
}

int getsibling(int u){
  
  if( T[u].p == NIL ) {
    return NIL;
  }
  
  if( T[T[u].p].l != u && T[T[u].p].l != NIL ) {
    return T[T[u].p].l;
  }
  
  if( T[T[u].p].r != u && T[T[u].p].r != NIL ){
    return T[T[u].p].r;
  }
  
  return NIL;
}

void print(int u){

  int d = 0;
  
  printf("node %d: parent = %d, sibling = %d,",u,T[u].p,getsibling(u));
  
  if( T[u].l != NIL ){
    d++;
  }
  
  if( T[u].r != NIL ) {
    d++;
  }
  
  printf(" degree = %d, depth = %d, height = %d, ", d,D[u],H[u]);

  if( T[u].p == NIL ){
    printf("root\n");
  }
  
  else if( T[u].l == NIL && T[u].r == NIL){
    printf("leaf\n");
  }
  
  else{
    printf("internal node\n");
  }
  
}

int main(){
  
  int i, v, l, r;
  
  scanf("%d", &n);

  for(i=0;i<n;i++){
    T[i].p = NIL;
  }

  for(i=0;i<n;i++){
    
    scanf("%d%d%d",&v,&l,&r);

    T[v].l = l;
    

    T[v].r = r;
    if(l!=NIL){
      T[l].p = v;
    }
    
    if(r != NIL){
      T[r].p = v;
    }
  }

  for (i=0;i<n;i++){
    
    D[i] = getdepth(i);
    H[i] = 0;
    
  }

  for (i=0;i<n;i++){
    if(T[i].l == NIL && T[i].r == NIL){
      
      H[i] = 0;
      
      int p = T[i].p;
      int count = 1;
      
      while(1){
	
	if(p == NIL){
	  break;
	}
	
	if(H[p] < count){
	  H[p] = count;
	}
	
	count++;
	p = T[p].p;
      }
    }
  }

  for (i=0;i<n;i++){
    print(i);
  }
  
  return 0;
}

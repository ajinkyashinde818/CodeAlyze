#include<stdio.h>
#define MAX 100005
#define NIL -1
  
struct Node{
  int l, p, r;
};
struct Node T[MAX];
int n;
 
int getDepth(int u){
  int d=0, i=0;
  while(1){
    if(T[u].p == NIL)break;
    d++;
    u=T[u].p;
  }
  return d;
}
void print(int u){
  
  printf("node %d: parent = %d, depth = %d, ",u,T[u].p,getDepth(u));
     
  if( T[u].p == NIL) printf("root, [");
   
else if(T[u].l == NIL) printf("leaf, [");
   
else printf("internal node, [");
     
  if( T[u].l != NIL){
    while(1){
       
if(T[T[u].l].r == NIL){
    printf("%d",T[u].l);
    break;
      }
       
else {
    printf("%d, ",T[u].l);
    T[u].l = T[T[u].l].r;
      }
    }
  }
    
  printf("]\n");
}
  
int main(){
  int i, j, k, id, c, l, t;
  
  scanf("%d", &n);
    
  for ( i = 0; i < n; i++ ) {
    T[i].p = T[i].l = T[i].r = NIL;
  }
    
  for ( i = 0; i < n; i++ ){
    scanf("%d %d", &id, &k);
    for ( j = 0; j < k; j++ ){
      scanf("%d", &c);
        
      if(j == 0){
    T[id].l = c;
    T[c].p = id;
    t = c;
      }
      else{
    T[t].r = c;
    T[c].p = id;
    t = c;
      }
    }
  }
    
  for ( i = 0; i < n; i++ ){
 
 print(i);
  } 
return 0;
}

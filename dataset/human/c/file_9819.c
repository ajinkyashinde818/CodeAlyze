#include<stdio.h>
#define MAX 100005
#define NIL -1
  
struct Node{
    int p, l, r;
};
struct Node T[MAX];
int dep=1,m;
 
main(){
  int i, j, d, v, c, l, n,tmp;
      
    scanf("%d", &n);
      
    for ( i = 0; i < n; i++ ) {
        T[i].p = T[i].l = T[i].r = NIL;
    }
      
    for (i = 0; i < n; i++){
        scanf("%d %d", &v, &d);
        for ( j = 0; j < d; j++ ){
      m=d;
            scanf("%d", &c);
              
            if(j==0){
                T[c].p=v;
                T[v].l=c;
        tmp=c;
            }
            else{
                T[c].p=v;
                T[tmp].r=c;
        tmp=c;
            }
              
        }
    }
      
    for ( i = 0; i < n; i++ ) print(i);
    return 0;
}
 
 
int depth(int u){
  if(T[u].p == NIL)return 0;
  if(T[T[u].p].p != NIL){
     dep++;
    depth(T[u].p);
  }
  return dep;
}
  
  
void print(int u){
  int i;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  dep=1;
  printf("depth = %d, ",depth(u));
   
   if(T[u].p == NIL){
     printf("root, [");
     if(T[u].l != NIL){
      printf("%d",T[u].l);
      while( T[T[u].l].r!=NIL){
     printf(", %d", T[T[u].l].r);
     T[u].l=T[T[u].l].r;
      }
     }
      printf("]\n");
   }//Endroot
  
   else if(T[u].p != NIL && T[u].l != NIL){
      printf("internal node, [%d",T[u].l);
      while( T[T[u].l].r!=NIL){
     printf(", %d", T[T[u].l].r);
     T[u].l=T[T[u].l].r;
       }
      printf("]\n");
   }//Endroot
  
   else if(T[u].l == NIL){
  printf("leaf, []\n");
   }//Endleaf
  
}

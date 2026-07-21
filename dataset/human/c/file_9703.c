#include<stdio.h>
#define MAX 100005
#define NIL -1
 
struct Node{int p,l,r,lef;};
struct Node T[MAX]; 
 
void print(int u){
 
  int i=T[u].p, depth=0;
  while(i!=NIL){
    i = T[i].p;
    depth++;
  }
 
  if(depth==0){
    printf("node %d: parent = %d, depth = %d, root, ",u,T[u].p,depth);
  }else if(T[u].l==NIL){
    printf("node %d: parent = %d, depth = %d, leaf, ",u,T[u].p,depth);
  }else{
    printf("node %d: parent = %d, depth = %d, internal node, ",u,T[u].p,depth);
  }
 
  i = T[u].l;
  printf("[");
  if(i!=NIL){
    printf("%d",i);
  }
 
  while (i!=-1){
  i = T[i].r;
 
  if(i!=NIL){
    printf(", %d", i);
  }
  }
  printf("]\n");
}
 
int main(){
  int i, j, d, v, c, l, n;
 
  scanf("%d", &n);
 
  for(i=0;i<n;i++){
    T[i].p = T[i].l = T[i].r = NIL;
  }
 
  for ( i = 0; i < n; i++ ){
 
    scanf("%d %d",&v,&d);
 
    for(j=0;j<d;j++){
      scanf("%d",&c);
       T[c].p = v;
   
       if(j==0){
     T[v].l = c;
       }else if(j>0){
     T[l].r = c;
       }
       l = c; 
  
    }
  }  
 
  for (i=0;i<n;i++){
    print(i);
  }  
  return 0;     
}

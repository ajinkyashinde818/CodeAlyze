#include <stdio.h>

#define N 100000

typedef struct{
  int p;
  int l;
  int r;
}Node;

int main(){

   int i;
   int j;
   int id;
   int k;
   int c;
   int tmp;
   int n;
   int depth;
  Node T[N];

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    T[i].p = -1;
    T[i].l = -1;
    T[i].r = -1;
  }
  
  for(i=0;i<n;i++){
  scanf("%d%d",&id,&k);
 
  for(j=0;j<k;j++){
    
    scanf("%d",&c);
    T[c].p = id;
    
    if(j==0){
    T[id].l = c;
    tmp = c;
    }
    
    if(j>0){
    T[tmp].r = c;
    tmp = c;
    }
    
   }
  }
  
    for(i=0;i<n;i++){
      printf("node %d: parent = %d, ",i,T[i].p);
 
        depth=0;
        id=i;
        while(T[id].p != -1){
            depth++;
            id=T[id].p;
        }
        printf("depth = %d, ",depth);
 
        if(T[i].p==-1) printf("root, ");
        else if(T[i].l==-1) printf("leaf, ");
        else printf("internal node, ");
 
        printf("[");
    if(T[i].l!=-1){
        id=T[i].l;
        printf("%d",id);
     while(T[id].r!=-1){
        id=T[id].r;
        printf(", %d",id);
            }
        }
        printf("]\n");
 }
  
  return 0;
}

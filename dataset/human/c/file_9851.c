#include<stdio.h>

#define N 100001

int getdepth(int);

typedef struct {
  int p,l,r;
} Node;

Node Tr[N];
int id;

int main(){
  int i,n,j,s,deg,k,dep;
  
  
  scanf("%d",&n);
  
  for(i=0 ; i<n ; i++){
    Tr[i].p = Tr[i].l = Tr[i].r = -1;
  }
  
  for(i=0 ; i<n ; i++){
    scanf("%d",&id);
    scanf("%d",&k);
    
    for(j=0 ; j<k ; j++){
      scanf("%d",&deg);
    
    if (j==0) Tr[id].l = deg;
    else Tr[s].r = deg;
    s = deg;
  Tr[s].p = id;
    }}
  
  for(i=0 ; i<n ; i++){
    dep = getdepth(i);

    printf("node %d: parent = %d, depth = %d, ",i,Tr[i].p,dep);
    
    if(dep==0) printf("root, ");
  
    else if(Tr[i].l==-1) printf("leaf, ");
  
    else printf("internal node, ");
   
    printf("[");
  
    if(Tr[i].l != -1){
      id = Tr[i].l;
      printf("%d",id);
    
      while(id != -1){
	id = Tr[id].r;
      
	if(id != -1) printf(", %d",id);
      }
    }
 
    printf("]\n");
 
  }
  return 0;
}

int getdepth(int i){
  int c = 0;

  id = Tr[i].p;

  while(id != -1){
    id = Tr[id].p;
    c++;
  }

  return c;
}

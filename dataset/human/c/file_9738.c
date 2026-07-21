#include<stdio.h>
#include<stdlib.h>
typedef struct{
  int par;
  int dep;
}node;

typedef struct{
  int id;
  int k;
  int *val;
}cnode;

int dep;

int getdep(node* T, int i){
  if(T[i].par == -1) return dep;
  dep++;
  return getdep(T, T[i].par);
}

void print(node T,cnode C){
  int i;
  printf("node %d: parent = %d, depth = %d, ",C.id,T.par,T.dep);

  if(T.par == -1) printf("root");
  else if(C.k == 0) printf("leaf");
  else printf("internal node");

  printf(", [");
  for(i=0;i<C.k;i++){
    printf("%d",C.val[i]);
    if(i != C.k-1) printf(", ");
  }
  printf("]\n");
}

int main(){
  node T[100000];
  cnode C[100000];
  int i,j,n;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++) T[i].par = -1;
  
  for(i=0;i<n;i++){
    scanf("%d%d",&C[i].id,&C[i].k);
  
     C[i].val = (int *)malloc(sizeof(int)*C[i].k);
      for(j=0;j<C[i].k;j++){
        scanf("%d",&C[i].val[j]);
        T[C[i].val[j]].par = C[i].id;
      }
  }

  for(i=0;i<n;i++){
    dep=0;
    T[i].dep = getdep(T,i);
  }

  for(i=0;i<n;i++){
    j=0;
    while(i!=C[j].id) j++;
    print(T[i],C[j]);

    free(C[j].val);
  }

  return 0;
}

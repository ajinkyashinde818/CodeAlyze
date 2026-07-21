#include <stdio.h>

#define MAX 100000

int type(int,int);

typedef struct{
  int le,ri,pa;
}data;

data Da[MAX];

int De[MAX];

int main(){
  int n,id,k,buf,bufi,chk=0,le,ri;
  int i,j;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++) Da[i].pa=Da[i].le=Da[i].ri=-1;
  
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&k);
    for(j=0;j<k;j++){
      scanf("%d",&bufi);
      if(j==0) Da[id].le=bufi;
      else Da[le].ri=bufi;
      le=bufi;
      Da[bufi].pa=id;
    }
  }
  for(i=0;i<n;i++){
    if(Da[i].pa==-1) ri=i;
  }

  type(ri,0);
  
  for(i=0;i<n;i++){
    chk=0;
    printf("node %d: ",i);
    printf("parent = %d, ",Da[i].pa);
    printf("depth = %d, ",De[i]);
    if(Da[i].pa==-1) printf("root, ");
    else if(Da[i].le==-1) printf("leaf, ");
    else printf("internal node, ");
    printf("[");
    for(j=0,buf=Da[i].le;buf!=-1;j++,buf=Da[buf].ri){
      if(j) printf(", ");
      printf("%d",buf);
    }
    printf("]\n");
  }
  
  return 0;
}

int type(int a,int b){
  De[a]=b;
  if(Da[a].ri!=-1) type(Da[a].ri,b);
  if(Da[a].le!=-1) type(Da[a].le,b+1);
}

#include <stdio.h>
#define N 100000
#define NIL -1

typedef struct tree {
  int p,l,r;
}tax;
tax T[N];

int main()
{
  int n,i,j,k,id,center,temp1,temp2;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    T[i].p=T[i].l=T[i].r=NIL;
  }
  
  for(i=0;i<n;i++){
    scanf("%d %d",&id,&k);
    for(j=0;j<k;j++){
      scanf("%d",&center);
      T[center].p=id;
      if(j==0) T[id].l=center;
      else T[temp1].r=center;
      temp1=center;
    }
  }
  
  for(i=0;i<n;i++){
    id=0;
    k=0;
    temp1=T[i].p;
    temp2=T[i].l;
    
    while(temp1!=NIL){
      k++,temp1=T[temp1].p;
    }
    
    printf("node %d: parent = %d, depth = %d, ",i,T[i].p,k);
    
    if(T[i].p==NIL) printf("root, [");
    else if(T[i].l!=NIL) printf("internal node, [");
    else printf("leaf, [");
    
    while(temp2!=NIL){
      if(id==0){
	printf("%d",T[i].l);
	id=1;
      }else printf(", %d",temp2);
      temp2=T[temp2].r;
    }
    printf("]\n");
  }
  return 0;
}

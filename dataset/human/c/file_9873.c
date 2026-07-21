#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int pa;
  int le;
  int ri;
} node;

int main(){
  node *ar,*t;
  int a,b,n,id,c,k,z,depth;

  scanf("%d",&n);
  ar=(node *)malloc(sizeof(node)*n);
  t=ar;
  for(a=0;a<n;a++){
    t[a].pa=-1;
    t[a].le=-1;
    t[a].ri=-1;
  }
  
  for(a=0;a<n;a++){
    scanf("%d %d",&id,&k);    
    for(b=0;b<k;b++){
      scanf("%d",&c);
      t[c].pa=id;
      if(b==0)t[id].le=c;
      else t[z].ri=c;
      z=c;
    }
  }
  
  for(a=0;a<n;a++){
    z=t[a].pa;
    depth=0;
    while(z!=-1){
      depth++;
      z=t[z].pa;
    }
    
    printf("node %d: parent = %d, depth = %d, ",a,t[a].pa,depth);
    if(t[a].pa==-1)printf("root, [");
    else if(t[a].le==-1)printf("leaf, [");
    else printf("internal node, [");
    z=t[a].le;
    
    if(z!=-1){
      printf("%d",t[a].le);
      while(t[z].ri!=-1){
	printf(", %d",t[z].ri);
	z=t[z].ri;
      }
    }
    
    printf("]\n");
  }
  
  return 0;
}

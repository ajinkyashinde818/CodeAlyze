#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int parent;//parent
  int left;//left child
  int right;//right sibling
}Tree;

int main(){
  Tree *t;
  int n,i,j,id,k,prov,depth,tn; //k=degree,prov=karinohensu,tn=type_number
  char type[3][15]={"root","internal node","leaf"};
  scanf("%d",&n);
  t=(Tree*)malloc(sizeof(Tree)*n);//akekata

  for(i=0;i<n;i++){
    t[i].parent=-1;
    t[i].left=-1;
    t[i].right=-1;
  }
  
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      if(j==0){
	scanf("%d",&t[id].left);
	prov=t[id].left;
      }
      else{
	scanf("%d",&t[prov].right);
	  prov=t[prov].right;
      }
	  t[prov].parent=id;
    }  
  }
  
  for(i=0;i<n;i++){
    //depth
    depth=0;
    prov=t[i].parent;
    while(prov!=-1){
      prov=t[prov].parent;
      depth++;
    }    //end of deptp
    //type
    if(depth==0)
      tn=0;
    else if(t[i].left==-1)
      tn=2;
    else
      tn=1;
    //ende of type
    printf("node %d: parent = %d, depth = %d, ",i,t[i].parent,depth);
    printf("%s, [",type[tn]);
    if(t[i].left!=-1)
      {
	printf("%d",t[i].left);
	prov=t[i].left;
	while(t[prov].right!=-1){
	  printf(", %d",t[prov].right);
	  prov=t[prov].right;
	}
      }
    printf("]\n");
  }
  free(t);
  return 0;
}

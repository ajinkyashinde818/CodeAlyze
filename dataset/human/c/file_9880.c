#include<stdio.h>
 
struct intree{
  int parent;
	int left;
	int right;
};
 
 
int main(void){
  	int n,i,j,k,id,left,child,depth,key;
	struct intree list[100000];
 
   
  scanf("%d",&n);
  for(i=0;i<n;i++){
    list[i].parent=-1;
    list[i].left=-1;
  	list[i].right=-1;
  }  
   
  for(i=0;i<n;i++){
    scanf("%d %d",&id,&k);
      for(j=0;j<k;j++){
  		scanf("%d",&child);
      	if(j==0){
      		list[id].left=child;
      		list[child].parent=id;
      	}
      	else{
      		list[left].right=child;
      		list[child].parent=id;
      	}
  	left=child;
      }
  }
      	
	 for(i=0;i<n;i++){
    printf("node %d: ",i);
    printf("parent = %d, ",list[i].parent);
    key=i;
	 	depth=0;
	 	while(list[key].parent!=-1){
	 		key=list[key].parent;
	 		depth++;
	 	}
	 	printf("depth = %d, ",depth);  
    
	 	if(list[i].parent==-1) printf("root, ");
    else if(list[i].left==-1 && list[i].parent!=-1) printf ("leaf, ");
    else printf("internal node, ");
    printf("[");
	 	
	 	if(list[i].left!=-1){
	 		key=list[i].left;
	 		printf("%d",list[i].left);
	 		while(list[key].right!=-1){
	 			printf(", %d",list[key].right);
	 			key=list[key].right;
	 		}
	 	}
	 	printf("]\n");
	 	
	 }
  return 0;
}

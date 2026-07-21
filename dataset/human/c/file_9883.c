#include <stdio.h>
#include <string.h>
#define N 100000

struct Node{
  int parent;
  int left;
  int right;
};

int main(){
  
  int n,j,p,i,d,s,t,a,id,k;
  
  scanf("%d",&n);
  
  struct Node T[n];

  for(i=0;i<n;i++){
    T[i].right=T[i].left=T[i].parent=-1;
  }
  
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&d);
      if(j==0){
	t=d;
	T[id].left=t;
	T[d].parent=id;
      }
      else {
	T[t].right=d;
	T[d].parent=id;
	t=d;
      }
    }
  }


    for(i=0;i<n;i++){
      if(T[i].parent==-1){
	printf("node %d: parent = -1, depth = 0, root, [",i);
	a=T[i].left;
	while(a!=-1){
	  printf("%d",a);
	  a=T[a].right;
	  if(a!=-1){
	    printf(", ");
	  }
	}
	  printf("]\n");

      }
    
      else if(T[i].left==-1){
	s=0;
	printf("node %d: parent = %d, depth = ",i,T[i].parent);
	a=T[i].parent;
	while(a!=-1){
	  s++;
	  a=T[a].parent;
	    }
      
	printf("%d, leaf, []\n",s);
      }
    
      else{
	s=0;
	printf("node %d: parent = %d, depth = ",i,T[i].parent);
	a=T[i].parent;
	while(a!=-1){
	  s++;
	  a=T[a].parent;
	    }
      
	printf("%d, internal node, [",s);
	a=T[i].left;
	while(a!=-1){
	  printf("%d",a);
	  a=T[a].right;
	  if(a!=-1){
	    printf(", ");
	  }
	}
	  printf("]\n");

	
      }
    }
    return 0;
  }

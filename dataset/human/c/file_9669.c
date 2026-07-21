#include<stdio.h>

#define NIL -1

int depth(int);

struct Node{
  int parent;
  int left;
  int right;
};

struct Node T[100000];

int main(){

  int n,id,k,c[100000],i,j,m,de,count=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].parent=NIL;
    T[i].right=NIL;
    T[i].left=NIL;
  }

  while(1){

    scanf("%d%d",&id,&k);
    count++;

    
    // printf("wa-i1\n");

    for(j=0;j<k;j++){
      
      scanf("%d",&c[j]);
    }

    
    /* if(count==1){
      
      T[id].parent=NIL;
      T[id].left=c[0];
      T[id].right=NIL;
      //printf("T:%d c[0]:%d\n",T[id].left,c[0]);
      } */
    
    if(k!=0){
      
      T[id].left=c[0];
      
      for(j=0;j<k;j++){
	T[c[j]].parent=id;
	
	if(j==k-1){T[c[j]].right=NIL;} 
	else {T[c[j]].right=c[j+1];}
	
      }
    }
    
    /* else if(k==0){
      
      T[id].left=NIL;
      
      
      // T[id].right=NIL;
	 }*/

    if(count==n)break;
  }

  //fprintf(stderr,"wa-i2\n");
  
  for(i=0;i<n;i++){

    //printf("wa-i4\n");
    
    de = depth(i);

    //printf("wa-i3\n");
    
    printf("node %d: parent = %d, depth = %d,",i,T[i].parent,de);
    
    if(T[i].parent==NIL){printf(" root, ");}
    else if(T[i].left==NIL){printf(" leaf, ");}
    else {printf(" internal node, ");}
    
    printf("[");

    j=T[i].left;

    //printf("\nj:%d\n",j);
    
    while(j!=NIL){

      if(T[i].left==j){
	printf("%d",j);
       
      }
      else{
	printf(", %d",j);
      }
      j=T[j].right;
    }
    
    printf("]\n");
  }

  //printf("node1:right:%d\n",T[].right);


  
  return 0;
}

int depth(int num){

  if(T[num].parent==NIL)return 0;

  return depth(T[num].parent)+1;
  
}

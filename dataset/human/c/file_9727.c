#include<stdio.h>
#define NIL -1
#define RANGE 100000

typedef struct Node{
  int parent;
  int left;
  int right;
}Node;
struct Node T[RANGE];

int main(){
  int id,k,i,j,n,m,d[RANGE];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].parent=NIL;
    T[i].left=RANGE;
    T[i].right=RANGE;
    d[i]=0;
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&k);
    if(k == 1){
      scanf("%d",&T[id].left);
      m=T[id].left;
      T[m].parent=id;
    }
    else if(k>1){
      scanf("%d",&T[id].left);
      m=T[id].left;
      for(j=1;j<k;j++){
	scanf("%d",&T[m].right);
	T[m].parent=id;
	m=T[m].right;
      }
      T[m].parent=id;
    }
  }
  for(i=0;i<n;i++){
    m=T[i].parent;
    while(1){
      if(m==NIL){
	break;
      }
      else{
	m=T[m].parent;
	d[i]++;
      }
    }
    printf("node %d: parent = %d, depth = %d,",i,T[i].parent,d[i]);
	   if(T[i].parent==NIL){
	     if(T[i].left==RANGE){
	       printf(" root, []\n");
	     }
	     else{
	       printf(" root, [%d",T[i].left);
	       m=T[i].left;
	       while(T[m].right!=RANGE){
		 printf(", %d",T[m].right);
		 m=T[m].right;
	       }
	       printf("]\n");
	     }
	   }
	   else if(T[i].left == RANGE) printf(" leaf, []\n");
	   else{
	     printf(" internal node, [%d",T[i].left);
	     m=T[i].left;
	     while(T[m].right!=RANGE){
	       printf(", %d",T[m].right);
	       m=T[m].right;
	     }
	     printf("]\n");
	   }
	   } 
      return 0;
  }

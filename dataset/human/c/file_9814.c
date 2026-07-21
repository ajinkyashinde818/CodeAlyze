#include<stdio.h>
#define MAX 100000
typedef struct node{
  int p;
  int left;
  int right;
 

}Node;
int D[MAX];
Node node[MAX];
void depth(int,int);
int main(){
  int n,i,num,j,cnum,tmp,l;
 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    node[i].p=-1;
    node[i].left=-1;
    node[i].right=-1;
  }
  for(i=0;i<n;i++){
    scanf("%d",&num);
    scanf("%d",&cnum);
    for(j=0;j<cnum;j++){
      scanf("%d",&tmp);
      if(j==0){
	node[num].left=tmp;
      }
      else
	{
	  node[l].right=tmp;
	}
      l=tmp;
      node[tmp].p=num;
    }   
  }
  for(i=0;i<n;i++){
    if(node[i].p==-1){
      depth(i,0);
    }
  }
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,node[i].p,D[i]);
    if(node[i].p==-1){
      printf("root, ");
      printf("[");
      for(j=0,tmp=node[i].left;tmp!=-1;tmp=node[tmp].right,j++){
	if(j==0){
	  printf("%d",tmp);
	}
	else printf(", %d",tmp);
      }
      printf("]\n");
    }
    else if(node[i].left==-1){
      printf("leaf, ");
      printf("[]\n");
    }
    else{
      printf("internal node, ");
      printf("[");
      for(j=0,tmp=node[i].left;tmp!=-1;tmp=node[tmp].right,j++){
	if(j==0){
	printf("%d",tmp);
	}
	else printf(", %d",tmp);
      }
      printf("]\n");
    }
  }
 
}
void depth(int u, int p){
  D[u]=p;
  if(node[u].right!=-1){
    depth(node[u].right,p);
  }
  if(node[u].left!=-1){
    depth(node[u].left,p+1);
  }

}

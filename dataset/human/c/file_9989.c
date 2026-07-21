#include<stdio.h>
#include<string.h>
#define NUM 100000

struct node{
  struct node *parent;
  struct node *left_child;
  struct node *right_sibling;
  int p_number;
  int c_number;
  int number;
};

int main(){
  struct node n[NUM],null_node;
  int n1,i,j,k,num,depth[NUM],child,child1;


  for(i=0;i<NUM;i++){
    n[i].parent=&null_node;
    n[i].left_child=&null_node;
    n[i].right_sibling=&null_node;
    n[i].p_number=-1;
    n[i].c_number=-1;
    depth[i]=0;
  }
  scanf("%d",&n1);
  
  for(i=0;i<n1;i++){ 
    scanf("%d%d",&num,&k);
    if(k>0){
      scanf("%d",&child);
      n[num].left_child=&n[child];
      n[num].c_number=child;
      n[child].parent=&n[num];
      n[child].p_number=num;
      for(j=0;j<k-1;j++){
	scanf("%d",&child1);
	n[child].right_sibling=&n[child1];
	n[child1].parent=&n[num];
	n[child1].p_number=num;
	n[child1].number=child1;
	child=child1;
      }
    }
    n[num].number=num;
  }

  for(i=0;i<n1;i++){
    j=i;
    while(n[j].parent!=&null_node){
      j=n[j].p_number;
      depth[i]++;
    }
  }

  for(i=0;i<n1;i++){
    printf("node %d: ",i);
    printf("parent = %d, ",n[i].p_number);
    printf("depth = %d, ",depth[i]);
    if(n[i].p_number==-1){
      printf("root, [");
    }else if(n[i].p_number!=-1 && n[i].left_child==&null_node){
      printf("leaf, [");
    }else{
      printf("internal node, [");
    }
    if(n[i].left_child!=&null_node){
      printf("%d",n[i].c_number);
      j=n[i].c_number;
      while(n[j].right_sibling!=&null_node){
	printf(", %d",n[j].right_sibling->number);
	j=n[j].right_sibling->number;
      }
    }
    printf("]\n");
  }
  
  return 0;
}

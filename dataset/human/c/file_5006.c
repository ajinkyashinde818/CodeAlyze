#include<stdio.h>
#include<string.h>
#define NUM 100000

struct node{
  struct node *parent;
  struct node *left;
  struct node *right;
  int p_number;
  int s_number;
  int l_number;
  int r_number;
  int number;
};

int Height(int);
struct node n[NUM],null_node;

int main(){
  int i,j,depth[NUM],degree[NUM],height[NUM],n1,num,left,right,h1,h2;
  
  for(i=0;i<NUM;i++){
    n[i].parent=&null_node;
    n[i].left=&null_node;
    n[i].right=&null_node;
    n[i].p_number=-1;
    n[i].s_number=-1;
    n[i].l_number=-1;
    n[i].r_number=-1; 
    depth[i]=0;
    degree[i]=0;
    height[i]=0;
  }
  scanf("%d",&n1);
  
  for(i=0;i<n1;i++){ 
    scanf("%d%d%d",&num,&left,&right);
    n[num].number=num;
    n[num].l_number=left;
    n[num].r_number=right;
    if(left!=-1){
      n[num].left=&n[left];
      n[left].parent=&n[num];
      n[left].p_number=num;
    }
    if(right!=-1){
      n[num].right=&n[right];
      n[right].parent=&n[num];
      n[right].p_number=num;
    }

    if(left!=-1&&right!=-1){
      n[left].s_number=right;
      n[right].s_number=left;
    }
    
    if(left!=-1){
      degree[num]++;
    }
    if(right!=-1){
      degree[num]++;
    }
  }

  for(i=0;i<n1;i++){
    j=i;
    while(n[j].parent!=&null_node){
      j=n[j].p_number;
      depth[i]++;
    }
  }

  for(i=0;i<n1;i++){
    height[i]=Height(i);
  }     

  for(i=0;i<n1;i++){
    printf("node %d: ",i);
    printf("parent = %d, ",n[i].p_number);
    printf("sibling = %d, ",n[i].s_number);
    printf("degree = %d, ",degree[i]);
    printf("depth = %d, ",depth[i]);
    printf("height = %d, ",height[i]);
    if(n[i].p_number==-1){
      printf("root\n");
    }else if(n[i].p_number!=-1 && n[i].left==&null_node && n[i].right==&null_node){
      printf("leaf\n");
    }else{
      printf("internal node\n");
    }
  }
  
  return 0;
}
  
int Height(int i){
  int h1=0,h2=0;
  if(n[i].right!=&null_node){
    h1=Height(n[i].r_number)+1;
  }
  if(n[i].left!=&null_node){
    h2=Height(n[i].l_number)+1;
  }
  
  if(h1>=h2)return h1;
  else return h2;
}

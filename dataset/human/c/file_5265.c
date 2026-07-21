#include<stdio.h>
#define N 25

typedef struct{
  int p,l,r,s;
}Node;

int depth(Node*,int,int);
int height(Node*,int,int,int);

int main(){
  int num,i,j,k,number;
  Node node[N]; 
  
  scanf("%d",&num);

  for(i=0; i<num; i++){
    node[i].p = -1;
  }  
  for(i=0; i<num; i++){
    scanf("%d",&number);
    scanf("%d",&node[number].l);
    scanf("%d",&node[number].r);
    node[node[number].l].p = number;
    node[node[number].r].p = number;
  }
  
  
  for(i=0; i<num; i++){
    printf("node %d: parent = %d, ",i,node[i].p);

    if(node[i].p == -1)printf("sibling = -1, ");
    else if(node[node[i].p].l == -1 && node[node[i].p].r == -1) printf("sibling = -1, ");
    else if(node[node[i].p].l == i) printf("sibling = %d, ",node[node[i].p].r);
    else  printf("sibling = %d, ",node[node[i].p].l);

    if(node[i].l == -1 && node[i].r == -1) printf("degree = 0, ");
    else if (node[i].l == -1 || node[i].r == -1) printf("degree = 1, ");
    else  printf("degree = 2, ");

    printf("depth = %d, height = %d, ",depth(node,i,0),height(node,i,0,0));
    
    if(node[i].p==-1) printf("root\n");
    else if(node[i].l==-1 && node[i].r==-1) printf("leaf\n");
    else printf("internal node\n");
  }
  
  return 0;
}


int depth(Node *node,int num,int count){
  if(node[num].p==-1)return count;
  count++;
  count = depth(node,node[num].p,count);
  return count;
}



int height(Node *node,int num,int count,int max){
  if(node[num].l == -1 && node[num].r == -1){
    if(max < count) max = count;
    return max;
  }
  count++;
  if(node[num].l!=-1) max = height(node,node[num].l,count,max);
  if(node[num].r!=-1) max = height(node,node[num].r,count,max);
  
  count--;
  return max;
}

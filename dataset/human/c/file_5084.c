#include<stdio.h>
#define MAX 26

typedef struct{
  int left;
  int right;
  int parent;
  int sibling;
  int deg;
  int depth;
  int height;
}Node;
 
Node node[MAX];
 
int Height(int i){
  int left=0,right=0; 
 
  if( node[i].left != -1 ) left = Height(node[i].left) + 1;
 
  if( node[i].right != -1 ) right = Height(node[i].right) + 1;
 
  if( right <= left ) return left;
 
  else if( right > left ) return right;
}
 
int main(){
  
  int n,id,right,left,i;
 
  scanf("%d",&n);
 
  for( i = 0 ; i < n ; i++ )
    {
      node[i].left = node[i].right = node[i].parent = node[i].sibling = -1;
      node[i].deg = node[i].depth = node[i].height = 0;
    }
   
  for( i = 0 ; i < n ; i++ )
    {
      scanf("%d%d%d",&id,&right,&left);
      if(right != -1 && left != -1){
    node[right].sibling = left;
    node[left].sibling = right;
    node[id].right = right;
    node[id].left = left;
    node[right].parent = node[left].parent = id;
    node[id].deg = 2;
      }
      else if( right == -1 && left != -1 ){
    node[id].left = left;
    node[left].parent = id;
    node[id].deg++;
      }
      else if( left == -1 && right != -1 ) {
    node[id].right = right;
    node[right].parent = id;
    node[id].deg++;
      }
    }
  int x;
 
  for( i = 0 ; i < n ; i++ )
    {
      x = i;
      while( node[x].parent != -1 )
    {
      x = node[x].parent;
          node[i].depth++;
    }
      node[i].height =  Height(i);
    }
 
  for( i = 0 ; i < n ; i++ )
    {
      printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,node[i].parent,node[i].sibling,node[i].deg,node[i].depth,node[i].height);
      if(node[i].parent == -1 ) printf("root\n");
      else if(node[i].deg == 0 ) printf("leaf\n");
      else printf("internal node\n");
    }
 
  return 0;
}

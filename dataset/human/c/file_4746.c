#include<stdio.h>
#define MAX 26
 
typedef struct{
  int l;
  int r;
  int parent;
  int sibling;
  int deg;
  int depth;
  int height;
}Node;
  
Node node[MAX];
  
int Height(int i){
  int l=0,r=0; 
  if( node[i].l != -1 ) l = Height(node[i].l) + 1;
  if( node[i].r != -1 ) r = Height(node[i].r) + 1;
  if( r <= l ) return l;
  else if( r > l ) return r;
}
  
int main(){
   
  int n,id,r,l,i;
  
  scanf("%d",&n);
  
  for( i = 0 ; i < n ; i++ )
    {
      node[i].l = node[i].r = node[i].parent = node[i].sibling = -1;
      node[i].deg = node[i].depth = node[i].height = 0;
    }
    
  for( i = 0 ; i < n ; i++ )
    {
      scanf("%d%d%d",&id,&r,&l);
      if(r != -1 && l != -1){
    node[r].sibling = l;
    node[l].sibling = r;
    node[id].r = r;
    node[id].l = l;
    node[r].parent = node[l].parent = id;
    node[id].deg = 2;
      }
      else if( r == -1 && l != -1 ){
    node[id].l = l;
    node[l].parent = id;
    node[id].deg++;
      }
      else if( l == -1 && r != -1 ) {
    node[id].r = r;
    node[r].parent = id;
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

#include<stdio.h>
 
typedef struct node{
 
  int p;
  int r;
  int l;
  int br;
}Node;
 
Node node[26];
int m;
void nodegene( Node*);
//void putdepth( Node*);
 
int depth(int);
int height(int);
void nodegene( Node* nod){
 
  nod -> l = -1;
  nod -> r = -1;
  nod -> p = -1;
  nod -> br = -1;
}
 
 
int depth(int k){
  int dep = 0;
  for(dep = 0 ; node[k].p != -1 ; dep++){
    k = node[k].p;
  }
  return dep;
 
}
 
int height(int k){
  int left=0,right=0; 
  
  if( node[k].l != -1 ) left = height(node[k].l) + 1;
  
  if( node[k].r != -1 ) right = height(node[k].r) + 1;
 
  if( right <= left ) return left;
  
  else if( right > left ) return right;
}
 
 
   
int main(){
 
  int i, j, n, l, r, nod, d, degree;
 
  Node c;
  scanf("%d",&m);
 
  for( i = 0; i < m; i++)nodegene(&node[i]);
   
  for( i = 0; i < m; i++){
 
    scanf("%d", &n);
    scanf("%d%d", &r, &l);
    node[l].p = n;
    node[r].p = n;
    node[l].br = r;
    node[r].br = l;
    node[n].r = r;
    node[n].l = l;
     
  }
 
  //  for(i = 0; i < m; i ++)putdepth(&node[i]);
 
  for( i = 0; i < m; i++){
 
    printf("node %d: parent = %d, sibling = %d, degree = ", i, node[i].p, node[i].br);
 
    if(node[i].r != -1 && node[i].l != -1)
      printf("2, ");
    else if(node[i].r != -1 || node[i].l != -1)
      printf("1, ");
    else
      printf("0, ");
 
    printf("depth = %d, height = %d, ",depth(i), height(i));
 
    if((node[i].r == -1 && node[i].l == -1) && node[i].p != -1)
      printf("leaf\n");
    else if(node[i].p == -1)
      printf("root\n");
    else if((node[i].l != -1 || node[i].r != -1) && node[i].p != -1)
      printf("internal node\n" );
     
 
  }
  return 0;
}

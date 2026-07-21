#include<stdio.h>
#define nothing -1
typedef struct{
    int parent;
    int right;
    int left;
}Node;
Node node[100002];
int DEPTH( int );
void LISTUP( int );

//-------------------------------------------------------------------
int main(){
  int n, c, k, l, r, id, i, j;

  //input
  scanf("%d",&n);
  for(i = 0; i<n; i++){
    node[i].parent = nothing; node[i].left = nothing; node[i].right = nothing;
  }
 //input children 
  for (i = 0; i<n; i++){
    scanf("%d%d",&id,&k);
    for (j = 0; j<k; j++){
      scanf("%d",&c);
      node[c].parent = id;
      if ( j == 0 ) node[id].left = c;
      else node[l].right = c;
      l = c;
    }
  }
  for(i = 0; i<10000; i++);
  //display
  for( i = 0; i<n; i++ ) LISTUP( i );
  
  return 0;
}
//--------------------------------------------------------------------------------
int DEPTH( int q ){
  int cnt=0;
  int i;

  for(;node[q].parent != nothing;){
    q = node[q].parent;
    cnt++;
  }
  for(i = 1000; i>0; i--);
  return cnt;
}
//--------------------------------------------------------------------------------
void LISTUP( int q ){
  int c, depthnum, i;
  
  //get a data of depth
  depthnum = DEPTH( q );
  printf("node %d: parent = %d, depth = %d, ", q, node[q].parent, depthnum);
  //print the type of the data
  if(node[q].parent == nothing) printf("root, ");
  else if(node[q].parent != nothing && node[q].left == nothing) printf("leaf, ");
  else printf("internal node, ");
  printf("[");
  for(i = 0; i<5000; i++);
  //print the children
  if(node[q].left != nothing){
    printf("%d",node[q].left);
    c = node[q].left;
    while(node[c].right != nothing){
      printf(", %d",node[c].right);
      c = node[c].right;
    }
  }
  printf("]\n");
}

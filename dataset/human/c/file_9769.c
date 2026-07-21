#include <stdio.h>
#define N 100000
#define NIL -1

struct Node{
  int parent;
  int left;
  int right;
};
struct Node T[100000];
int C[100000];

void getDepth(int, int);

int main()
{
  int n, i, j, k, x, y, id, key, root;
  
  for( i=0 ; i<N ; i++ ){
    T[i].parent = NIL;
    T[i].left = NIL;
    T[i].right = NIL;
  }

  scanf("%d",&n);
  for( i=0 ; i<n ; i++ ){
    scanf("%d %d",&id,&key);
    for( j=0 ; j<key ; j++ ){
      scanf("%d",&x);
      if(j==0)
	T[id].left = x;
      else
	T[y].right = x;
      y = x;
      T[x].parent = id;
    }
  }

  for( i=0 ; i<n ; i++ )
    if(T[i].parent==NIL) root = i;

  getDepth(root,0);

  for( i=0 ; i<n ; i++ ){
    printf("node %d: parent = %d, depth = %d,",i,T[i].parent,C[i]);
    if(T[i].parent==NIL)
      printf(" root, [");
    else if(T[i].left==NIL)
      printf(" leaf, [");
    else
      printf(" internal node, [");
    
    k = T[i].left;
    for( j=0 ; k!=NIL ; j++){
      if(j!=0)printf(", ");
      printf("%d",k);
      k = T[k].right;
    }
    printf("]\n");
  }



  return 0;
}
void getDepth(int r, int d)
{
  C[r] = d;
  if(T[r].right!=NIL)
    getDepth(T[r].right,d);
  if(T[r].left!=NIL)
    getDepth(T[r].left,d+1);
}

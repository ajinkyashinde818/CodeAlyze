#include <stdio.h>
#define N 100000
#define NIL -1

struct Node{
  int parent;
  int left;
  int right;
};
struct Node T[25];
int C[25];
int H[25];

void getDepth(int, int);
int getHeight(int);

int main()
{
  int n, i, j, k, x, y, id, left, right, root;


  scanf("%d",&n);
  for( i=0 ; i<n ; i++ ){
    T[i].parent = NIL;
  }
  for( i=0 ; i<n ; i++ ){
    scanf("%d %d %d",&id,&left,&right);
    T[id].left = left;
    T[id].right = right;

    T[left].parent = id;

    T[right].parent = id;
  }

  for( i=0 ; i<n ; i++ )
    if(T[i].parent==NIL) root = i;

  getDepth(root,0);
  getHeight(root);

  for( i=0 ; i<n ; i++ ){
    printf("node %d: parent = %d, sibling = ",i,T[i].parent);
    
    j=i;
    while(1){
      if(T[i].parent==NIL) {
	printf("%d",T[i].parent);
	break;
      }
      if(T[T[i].parent].left==j) {
	printf("%d",T[T[i].parent].right);
	break;
      }
      if(T[T[i].parent].right==j){
	printf("%d",T[T[i].parent].left);
	break;
      }
      j++;
    }
        
    printf(", degree = ");
    if(T[i].left==NIL && T[i].right==NIL) printf("0");
    else if(T[i].left==NIL && T[i].right!=NIL)printf("1");
    else if(T[i].left!=NIL && T[i].right==NIL)printf("1");
    else printf("2");

    printf(", depth = %d,",C[i]);

    printf(" height = %d,",H[i]);
    
    if(T[i].parent==NIL)
      printf(" root\n");
    else if(T[i].left==NIL && T[i].right==NIL)
      printf(" leaf\n");
    else
      printf(" internal node\n");
  }

  return 0;
}
void getDepth(int r, int d)
{
  if(r==NIL) return;
  C[r] = d;


  getDepth(T[r].right,d+1);

  getDepth(T[r].left,d+1);
}

int getHeight(int r)
{
  int x=0, y=0;

  if(T[r].right!=NIL)
    x = getHeight(T[r].right)+1;
  if(T[r].left!=NIL)
    y = getHeight(T[r].left)+1;
  if(x>y) H[r] = x;
  else H[r] = y;
  return H[r];
}

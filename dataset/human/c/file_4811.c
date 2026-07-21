#include <stdio.h>
#define NIL -1
#define MAX 10000

struct Node{
  int parent;
  int left;
  int right;
};

struct Node L[MAX];
int n;
int data[MAX];
int he[MAX];


void depth(int j, int k)
{
  if(j == NIL)return;
  data[j] = k;
  depth(L[j].left,k+1);
  depth(L[j].right,k+1);
}

int height(int o)
{
  int h1 = 0;
  int h2 = 0;
  
  if( L[o].left != NIL )
    h1 = height(L[o].left) + 1;
  if( L[o].right != NIL )
    h2 = height(L[o].right) + 1;
  return he[o] = ( h1 > h2 ? h1 : h2);
}

int sibling(int o)
{
  if( L[o].parent == NIL )return NIL;
  if( L[L[o].parent].left != o && L[L[o].parent].left != NIL)
    return L[L[o].parent].left;
  if( L[L[o].parent].right != o && L[L[o].parent].right != NIL)
     return L[L[o].parent].right;
  return NIL;
}

void print( int o )
{
  int degree = 0;
  
  printf("node %d: parent = %d, sibling = %d, ",o,L[o].parent,sibling(o));
  if( L[o].left != NIL)degree++;
  if( L[o].right != NIL )degree++;
  printf("degree = %d, depth = %d, height = %d, ",degree,data[o],he[o]);
  if( L[o].parent == NIL ){
    printf("root");
  }
  else if( L[o].left == NIL && L[o].right == NIL ){
    printf("leaf");
  }
  else{
    printf("internal node");
  }
  printf("\n");
}

int main()
{
  int i;
  int a,b,c;
  int r=0;
  
  scanf("%d",&n);
  for( i = 0; i< n; i++) L[i].parent = NIL;
  for( i = 0 ; i < n ; i++){
    scanf("%d%d%d",&a,&b,&c);
    L[a].left = b;
    L[a].right = c;
    if( b != NIL )L[b].parent = a;
    if( c != NIL )L[c].parent = a;
  }
  for( i = 0 ; i < n; i++ )if( L[i].parent == NIL ) r = i;
  depth(r,0);
  height(r);
  
  for( i = 0 ; i < n; i++ )print(i);
  for( i = 0 ; i < n; i++ );
  return 0;
}

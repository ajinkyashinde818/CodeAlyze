#include<stdio.h>

#define MAX 25

typedef struct{
  int parent;
  int left;
  int right;
}Tree;

int DEGREE( int );
int DEPTH( int );
int HEIGHT( int );
int get_sibling( int );

Tree T[MAX];

int main()
{
  int i, n, id, left, right, degree, depth, height, sibling;

  scanf("%d", &n);

  for( i=0; i<n; i++ )
    {
      T[i].parent = -1;
      T[i].left = -1;
      T[i].right = -1;
    }

  for( i=0; i<n; i++ )
    {
      scanf("%d%d%d", &id, &left, &right);
      
      T[id].left = left;
      T[id].right = right;
      if( left != -1) T[left].parent = id;
      if( right != -1 ) T[right].parent = id;
    }


  for( i=0; i<n; i++ )
    {
      printf("node %d: ", i);
      printf("parent = %d, ", T[i].parent);

      sibling = get_sibling(i);
      printf("sibling = %d, ", sibling);

  
      degree = DEGREE(i);
      printf("degree = %d, ", degree );


      depth = DEPTH(i);
      printf("depth = %d, ", depth);

      height = HEIGHT(i);

      printf("height = %d, ", height);

      if( T[i].parent == -1 ) printf("root\n");

      else if( degree == 0 ) printf("leaf\n");

      else printf("internal node\n");
    }

  return 0;
}

      
int DEGREE( int id )
{
  int count=0;

  if( T[id].left != -1 ) count++;
  if( T[id].right != -1 ) count++;

  return count;
}
      

int DEPTH( int id )
{
  int count=0;

  while( T[id].parent != -1 )
    {
      id = T[id].parent;
      count++;
    }
  return count;
}


int HEIGHT( int id )
{
  int h1=0, h2=0;
  if( T[id].right != -1 )
    {
      h1 = HEIGHT( T[id].right ) + 1;
    }
  if( T[id].left != -1 )
    {
      h2 = HEIGHT( T[id].left ) + 1;
    }

  if( h1 > h2 ) return h1;
  else return h2;
}


int get_sibling( int id )
{
  if( T[id].parent == -1 )
    {
      return -1;
    }
  else if( T[T[id].parent].left != id )
    {
      return T[T[id].parent].left;
    }
  else if( T[T[id].parent].right != id )
    {
      return T[T[id].parent].right;
    }
}

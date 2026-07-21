#include<stdio.h>
#define MAX 10000

struct Node{
  int p, l, r;
};

struct Node Tree[MAX];
int n;
int depth[MAX], H[MAX];

int getDepth(int x){
  int count = 0;
  while(1){
    x = Tree[x].p;
    if ( x == -1 )
     break;
    count++;
  }
  return count;
}

int getSibling(int x){

  if ( Tree[x].p == -1 )
   return -1;
  if ( Tree[Tree[x].p].l != x && Tree[Tree[x].p].l != -1 )
   return Tree[Tree[x].p].l;
  if ( Tree[Tree[x].p].r != x && Tree[Tree[x].p].r != -1 ) 
  return Tree[Tree[x].p].r;

  return -1;
}

void print(int x){

  printf("node %d: ", x);
  printf("parent = %d, ", Tree[x].p);
  printf("sibling = %d, ", getSibling(x));
  int count = 0;
  if ( Tree[x].l != -1 ) count++;
  if ( Tree[x].r != -1 ) count++;
  printf("degree = %d, ", count);
  printf("depth = %d, ", depth[x]);
  printf("height = %d, ", H[x]);

  if ( Tree[x].p == -1 ){
    printf("root\n");
  } else if ( Tree[x].l == -1 && Tree[x].r == -1 ){
    printf("leaf\n");
  } else {
    printf("internal node\n");
  }
}

main(){
  int i, v, l, r;
  int c;
  scanf("%d", &n);

  for ( i = 0; i < n; i++ ) {
    Tree[i].p = -1;
  }

  for ( i = 0; i < n; i++ ){
    scanf("%d %d %d", &v, &l, &r);
    Tree[v].l = l;
    Tree[v].r = r;
    if ( l != -1 ) 
        Tree[l].p = v;

    if ( r != -1 ) 
        Tree[r].p = v;
  }

  for ( i = 0; i < n; i++ ){
    depth[i] = getDepth(i);
    H[i] = 0;
  }

  for ( i = 0; i < n; i++ ){
    if ( Tree[i].l == -1 && Tree[i].r == -1 ) {
      H[i] = 0;
      int p = Tree[i].p;
         c = 1;
      while(1){
        if ( p == -1 ) break;
        if ( H[p] < c ) H[p] = c;
        c++;
        p = Tree[p].p;
      }
    }
  }

  for ( i = 0; i < n; i++ ) 
    print(i);
  return 0;
}

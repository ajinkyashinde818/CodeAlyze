#include<stdio.h>
#define MAX 100005
#define NIL -1
int n;
struct Node{
  int p; //parent
  int l; //left-child
  int r; //right sibiling
};
struct Node T[MAX];
int depth(int u){
  int d=0;
  int tmp=T[u].p;
  while( tmp!=NIL ){ d++; tmp=T[tmp].p;}
  return d;
}
int height(int u){
  int l=NIL;
  int r=NIL;
  if( T[u].l!=NIL ) l=height(T[u].l);
  if( T[u].r!=NIL ) r=height(T[u].r);
  l++;
  r++;
  if( l>r ) return l;
  else return r;
}
int find_sibling(int u){
  int tmp=T[u].p;
  if( tmp!=NIL ){
    if( T[tmp].r==u ) return T[tmp].l;
    else return T[tmp].r;
  }
  return NIL;
}
int degree(int u){
  int d=0;
  if( T[u].l!=NIL )d++;
  if( T[u].r!=NIL )d++;
  return d;
}
void print(int u){
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", u, T[u].p, find_sibling(u), degree(u), depth(u), height(u));
  if( T[u].p==NIL) printf("root\n");
  else if( T[u].l!=NIL || T[u].r!=NIL) printf("internal node\n");
  else printf("leaf\n");
}
int main(void){
  int i;
  int d;
  scanf("%d", &n);
  for ( i=0; i<n; i++ ) T[i].p=T[i].l=T[i].r=NIL;
  for ( i=0; i<n; i++ ){
    scanf("%d", &d);
    scanf("%d %d", &T[d].l, &T[d].r);
    T[T[d].l].p=T[T[d].r].p=d;
  }
  for ( i=0; i<n; i++ ) print(i);
  return 0;
}

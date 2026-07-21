#include<stdio.h>
#define MAX 10000
#define NIL -1
 
struct Node{
  int p, l, r;
};
 
struct Node A1[MAX];
int num;
int A2[MAX], A3[MAX];
 
int getDepth(int m){
  int d = 0;
  while(1){
    m = A1[m].p;
    if ( m == NIL ) break;
    d++;
  }
  return d;
}
 
int getSibling(int m){
  if ( A1[m].p == NIL ) return NIL;
  if ( A1[A1[m].p].l != m && A1[A1[m].p].l != NIL )return A1[A1[m].p].l;
  if ( A1[A1[m].p].r != m && A1[A1[m].p].r != NIL )return A1[A1[m].p].r;
  return NIL;
}
 
void print(int m){
  printf("node %d: ", m);
 
  printf("parent = %d, ", A1[m].p);
  printf("sibling = %d, ", getSibling(m));
  int deg = 0;
   
  if ( A1[m].l != NIL )
    deg++;
  if ( A1[m].r != NIL )
    deg++;
   
  printf("degree = %d, ", deg);
  printf("depth = %d, ", A2[m]);
  printf("height = %d, ", A3[m]);
 
  if ( A1[m].p == NIL ){
    printf("root\n");
  } else if ( A1[m].l == NIL && A1[m].r == NIL ){
    printf("leaf\n");
  } else {
    printf("internal node\n");
  }
}
 
int main(){
  int i, v, l, r;
  scanf("%d", &num);
 
  for ( i = 0; i < num; i++ ) {
    A1[i].p = NIL;
  }
 
  for ( i = 0; i < num; i++ ){
    scanf("%d %d %d", &v, &l, &r);
    A1[v].l = l;
    A1[v].r = r;
    if ( l != NIL ) A1[l].p = v;
    if ( r != NIL ) A1[r].p = v;
  }
 
  for ( i = 0; i < num; i++ ){
    A2[i] = getDepth(i);
    A3[i] = 0;
  }
 for ( i = 0; i < num; i++ ){
    scanf("%d %d %d", &v, &l, &r);
    A1[v].l = l;
    A1[v].r = r;
    if ( l != NIL ) A1[l].p = v;
    if ( r != NIL ) A1[r].p = v;
  }
 
  for ( i = 0; i < num; i++ ){
    A2[i] = getDepth(i);
    A3[i] = 0;
  }
 
  for ( i = 0; i < num; i++ ){
    if ( A1[i].l == NIL && A1[i].r == NIL ) { // is leaf
      A3[i] = 0;
      int p = A1[i].p;
      int c = 1;
      while(1){
        if ( p == NIL ) break;
        if ( A3[p] < c ) A3[p] = c;
        c++;
        p = A1[p].p;
      }
    }
  }
 
  for ( i = 0; i < num; i++ ) print(i);
  return 0;
}

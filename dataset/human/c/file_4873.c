#include<stdio.h>
#define MAX 100005
#define NIL -1

/*
 p: parent
 l: left-child
 r: right sibling
 */
struct Node{
  int p, l, r;
};
struct Node T[MAX]; // Tree
int n;
int depth(int u){
  int d = 0, i;
  for(i=u; T[i].p!=NIL; i=T[i].p, d++);
  return d;
}
int height(int u){
  int l = 0, r = 0,h=0;
    if (T[u].l != -1){
        l += height(T[u].l);
        l++;
    }
    if (T[u].r != -1){
        r += height(T[u].r);
        r++;
    }
    if(r>=l) h=r;
    else h=l;
  return h;
}
void print(int u){
  int sibling,degree;
  printf("node %d: parent = %d, ",u,T[u].p);
  if(T[u].p==NIL){
    sibling=-1;
  }else if(T[T[u].p].l==u){
    sibling=T[T[u].p].r;
  }else{
    sibling=T[T[u].p].l;
  }
  printf("sibling = %d, ",sibling);
  
  if(T[u].l == NIL && T[u].r == NIL){
    degree=0;
  }else if(T[u].l == NIL || T[u].r == NIL){
    degree=1;
  }else{
    degree=2;
  }
  printf("degree = %d, ",degree);
  printf("depth = %d, height = %d, ",depth(u),height(u));
  if(T[u].p==NIL){
    printf("root\n");
  }else if(height(u)==0){
    printf("leaf\n");
  }else{
    printf("internal node\n");
  }
  
   
}

int main(){
  int i, j, d, v, c, l,tmp;
  
  scanf("%d", &n);
  
  for ( i = 0; i < n; i++ ) {
    T[i].p = T[i].l = T[i].r = NIL;
  }
  
  for ( i = 0; i < n; i++ ){
    scanf("%d %d %d", &v, &d, &c);
    T[v].l = d;
    T[v].r = c;
    T[d].p = T[c].p = v;
  }
  for ( i = 0; i < n; i++ ) print(i);
  return 0;
}

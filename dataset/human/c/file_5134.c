#include<stdio.h>
#define MAX 100005
#define NIL -1

struct Node{
    int p, l, r;
};
struct Node T[MAX];
int dep,hileft,hiright;

main(){
  int i, j, d, v, c, l, n,tmp;
      
    scanf("%d", &n);
      
    for ( i = 0; i < n; i++ ) {
        T[i].p = T[i].l = T[i].r = NIL;
    }
    for (i = 0; i <n ; i++){
      scanf("%d %d %d", &v, &d, &c);
             T[d].p=v;
         T[c].p=v;
             T[v].l=d;
             T[v].r=c;
  
    }
      
    for ( i = 0; i < n; i++ ) print(i);
    return 0;
}

int depth(int u){
  if(T[u].p == NIL)return 0;
   if(T[u].p != NIL){
     dep++;
    depth(T[u].p);
  }
  return dep;
}
  
int degree(int u){
    if (T[u].l == NIL && T[u].r == NIL)return 0;
    else if(T[u].l != NIL && T[u].r != NIL)return 2;
    else  return 1;
}
int sibling(int u){
  if(T[u].p == NIL) return NIL;
  else if(T[T[u].p].l==u)return T[T[u].p].r;
  else return T[T[u].p].l;
}
 
int hight(int u){
  int hileft = 0, hiright = 0;
  if(T[u].l != -1) {
hileft = hight(T[u].l) + 1;
  }
  if(T[u].r != -1){
 hiright = hight(T[u].r) + 1;
  }
  if(hileft < hiright) return hiright;
  else return hileft;
}

  
void print(int u){
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("sibling = %d, ",sibling(u));
  printf("degree = %d, ",degree(u));
  dep=0;
  printf("depth = %d, ",depth(u));
  //hileft=hiright=0;
  printf("height = %d, ",hight(u));
  
  if(T[u].p == NIL)printf("root\n");
  else if(T[u].l == NIL && T[u].r == NIL)printf("leaf\n");
  else printf("internal node\n");
}

#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define NIL -1
#define a(x,y) ((x) > (y) ? (x) : (y))
struct Node {int p,l,r;};
struct Node T[MAX];
int D[MAX];
int getDepth(int);
int setHight(int*,int);
int getSibling(int);

int main(){
  int n,i,c,l,r;
  scanf("%d",&n);

  for(i = 0; i < n; i++){
    T[i].p = NIL;
    T[i].l = NIL;
    T[i].r = NIL;
  }

  for(i = 0; i < n; i++){
    scanf("%d%d%d",&c,&l,&r);
    T[c].l = l;
    T[c].r = r;
    if(l != NIL) T[l].p = c;
    if(r != NIL) T[r].p = c;
  }

  for(i = 0; i < n; i++){
    if(T[i].p == NIL) r = i;
  }
  for(i = 0; i < n; i++){
      int d=0;
    printf("node %d: ",i);
    printf("parent = %d, ",T[i].p);
    printf("sibling = %d, ",getSibling(i));
    if(T[i].l != NIL) d++;
    if(T[i].r != NIL) d++;
    printf("degree = %d, ",d);
    printf("depth = %d, ",getDepth(i));
    setHight(D,i);
    printf("height = %d, ",D[i]);

    if(T[i].p == NIL) printf("root\n");
    else if(T[i].l == NIL && T[i].r == NIL) printf("leaf\n");
    else printf("internal node\n");

  }

}

int getDepth(int u){
 int a = 0;
 while(T[u].p != NIL){
   u = T[u].p;
   a++;
 }
 return a;
}

int setHight(int D[],int u){
 int h1 = 0, h2 = 0;
 if(T[u].r != NIL){
   h1 = setHight(D,T[u].r) + 1;
 }
 if(T[u].l != NIL){
   h2 = setHight(D,T[u].l) + 1;
 }

 return D[u] = a(h1,h2);
}

int getSibling(int u){
 if(T[u].p == NIL) return NIL;
 if(T[T[u].p].l != u && T[T[u].p].l != NIL){
   return T[T[u].p].l;
 }
 if(T[T[u].p].r != u && T[T[u].p].r != NIL){
   return T[T[u].p].r;
 }
 return NIL;
}

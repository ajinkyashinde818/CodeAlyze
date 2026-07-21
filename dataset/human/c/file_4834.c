#include<stdio.h>
#define N 100000

typedef struct{ 
  int p,l,r;
}Node;

Node T[N];

int dep,hl,hr;

main(){
  int i, j, d, v, c, l, n,tmp;
  
  scanf("%d", &n);
    
    for ( i = 0; i < n; i++ ) {
      T[i].p = T[i].l = T[i].r = -1;
    }
    for (i = 0; i <n ; i++){
      scanf("%d %d %d", &v, &d, &c);
      T[d].p=v;
      T[c].p=v;
      T[v].l=d;
      T[v].r=c; 
    }
       
    for ( i = 0; i < n; i++){
      print(i);
    }
    return 0;
}

int sibling(int u){
  if(T[u].p == -1) return -1;
  else if(T[T[u].p].l == u)return T[T[u].p].r;
  else return T[T[u].p].l;
}

int degree(int u){
  if (T[u].l == -1 && T[u].r == -1) return 0;
  else if(T[u].l != -1 && T[u].r != -1) return 2;
  else  return 1;
}

int depth(int u){
  if(T[u].p == -1) return 0;
   if(T[u].p != -1){
     dep++;
    depth(T[u].p);
   }
   return dep;
}

int hight(int u){
  int hl = 0, hr = 0;
  if(T[u].l != -1) {
    hl = hight(T[u].l) + 1;
  }
  if(T[u].r != -1){
    hr = hight(T[u].r) + 1;
  }
  if(hl < hr) return hr;
  else return hl;
}

void print(int u){
  printf("node %d: parent = %d, sibling = %d, degree = %d, ",u,T[u].p,sibling(u),degree(u));
  dep=0;
  printf("depth = %d, height = %d, ",depth(u),hight(u));  
  if(T[u].p == -1)printf("root\n");
  else if(T[u].l == -1 && T[u].r == -1)printf("leaf\n");
  else printf("internal node\n");
}

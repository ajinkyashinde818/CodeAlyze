#include<stdio.h>
#define N 100000

struct Node{int r,l,in;};
struct Node T[N];

int n , length[N];

int depth(int , int);

int main(){
  int i,id,k,c,j,l,in;
  
  scanf("%d",&n);
  
  for(i = 0 ; i < n ; i++){
    T[i].r = -1;
    T[i].l = -1;
    T[i].in = -1;
  }
  
  for(i = 0 ; i < n ; i++){
    scanf("%d%d",&id,&k);
    for(j = 0 ; j < k ;j++){
      scanf("%d",&c);
      if(j == 0) T[id].l = c;
      else T[l].in = c;
      l = c;
      T[c].r = id;
    }
  }
  for(i = 0 ; i < n ; i++)
    if(T[i].r == -1) in = i;
  
  depth(in , 0);
  
  for(i = 0 ; i < n ; i++){
    printf("node %d: parent = %d, depth = %d,", i , T[i].r , length[i]);
    printf(" ");
    if(T[i].r == -1) printf("root, [");
    else if(T[i].l == -1) printf("leaf, [");
    else printf("internal node, [");
    c=T[i].l;
    while(c != -1){
      if(c == T[i].l)printf("%d",c);
      c = T[c].in;
      if(c != -1)printf(", %d",c);
     
     
    }
    printf("]\n");
  }
  return 0;
}

int depth(int u, int q){
  length[u] = q;
  if(T[u].in != -1) depth(T[u].in , q);
  if(T[u].l != -1) depth(T[u].l , q+1);
}

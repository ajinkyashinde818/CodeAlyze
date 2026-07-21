#include <stdio.h>
#define X 100000

typedef struct{
  int p,l,r;
}N;

N T[X];
int n, D[X];

void print(int);
int rec(int, int);

int main(){

  int i,j,ne,d,v,c,l;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    T[i].p = T[i].l = T[i].r = -1;

  for(i=0;i<n;i++){
    scanf("%d%d", &v, &d);
    for(j=0;j<d;j++){
      scanf("%d",&c);
      if(j == 0) T[v].l = c;
      else T[l].r = c;
      l = c;
      T[c].p = v;
    }
  }

  for(i=0;i<n;i++)
    if(T[i].p == -1) ne=i;

  rec(ne,0);
  for(i=0;i<n;i++)
    print(i);

  return 0;
}

void print(int x){
  int i,c;

  printf("node %d: parent = %d, depth = %d, ",x,T[x].p,D[x]);

  if(T[x].p == -1)
    printf("root, [");

  else if(T[x].l == -1)
    printf("leaf, [");

  else printf("internal node, [");

  for(i=0,c=T[x].l; c!=-1; i++,c=T[c].r){
    if(i)printf(", ");
    printf("%d",c);
  }
  printf("]\n");
}

int rec(int a,int b){

  D[a] = b;
  if(T[a].r != -1) rec(T[a].r,b);
  if(T[a].l != -1) rec(T[a].l,b+1);
}

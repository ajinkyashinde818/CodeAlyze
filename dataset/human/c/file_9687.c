#include <stdio.h>
#define NIL -1

struct Node {
  int p;
  int l;
  int r;
};
  
int n,D[100000];
struct Node ori[100000];

int rec(int ,int );
void result(int );

int main()
{
  int i,j,a,b,c,l,r,z=0,w,g;
  
  scanf("%d",&n);
  for(i=0;i<n;i++) ori[i].p=ori[i].l=ori[i].r=NIL;
  
  while(z<n){
    scanf("%d%d",&a,&b);
    for(j=0;j<b;j++){
      scanf("%d",&c);
      if(j==0) ori[a].l=c;
      else ori[l].r=c;
      l=c;
      ori[c].p=a;
    }
    z++;
  }

  for(i=0;i<n;i++){
    if(ori[i].p==NIL) r=i;
  }

  rec(r,0);

  for(i=0;i<n;i++){
     printf("node %d:",i);
  printf(" parent = %d,",ori[i].p);
  printf(" depth = %d,",D[i]);

  if(ori[i].p==NIL) printf(" root, ");
  else if(ori[i].l==NIL) printf(" leaf, ");
  else printf(" internal node, ");

  printf("[");
  
  for(g=0,w=ori[i].l;w!=NIL;g++,w=ori[w].r){
    if(g>0) printf(", ");
    printf("%d",w);
  } 
  printf("]\n");
  }
  
  return 0;
}

int rec(int u,int p){
  D[u]=p;
  if(ori[u].r!=NIL) rec(ori[u].r,p);
  if(ori[u].l!=NIL) rec(ori[u].l,p+1);
}

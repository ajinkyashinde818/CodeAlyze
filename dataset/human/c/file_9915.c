#include <stdio.h>

struct Node {int p,l,r;};

struct Node T[100005];
int n,D[100005];

void print(int u){
  int i,c;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("depth = %d, ",D[u]);

  if(T[u].p==-1) printf("root, ");
  else if(T[u].l==-1) printf("leaf, ");
  else printf("internal node, ");
  printf("[");
  c=T[u].l;
  for(i=0;c!=-1;i++){
    if(i!=0) printf(", ");
    printf("%d",c);
    c=T[c].r;
  }
  printf("]\n");
  
}

int re(int u,int p){
  D[u]=p;
  if(T[u].r!=-1) re(T[u].r,p);
  if(T[u].l!=-1) re(T[u].l,p+1);
}

int main(){
  int i,j,a,b,c,l,r;
  scanf("%d",&n);
  for(i=0;i<n;i++) T[i].p=T[i].l=T[i].r=-1;

  for(i=0;i<n;i++){
    scanf("%d%d",&a,&b);
    for(j=0;j<b;j++){
      scanf("%d",&c);
      if(j==0) T[a].l=c;
      else T[l].r=c;
      l=c;
      T[c].p=a;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].p==-1) r=i;
  }

  re(r,0);

  for(i=0;i<n;i++)print(i);

  return 0;
}

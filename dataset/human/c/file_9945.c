#include<stdio.h>
#define N 100000

struct Node{
  int p,l,r;
};
struct Node NT[N];
int D[N];
void SetDepth(int u,int p){
  D[u]=p;
  if(NT[u].r!=-1)SetDepth(NT[u].r,p);
  if(NT[u].l!=-1)SetDepth(NT[u].l,p+1);
}

int main(){
  int i,j,n,id,k,c,l,r;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    NT[i].p=-1;
    NT[i].l=-1;
    NT[i].r=-1;
  }

  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&c);
      if(j==0)NT[id].l=c;
      else NT[l].r=c;
      l=c;
      NT[c].p=id;
    }
  }
  for(i=0;i<n;i++){
    if(NT[i].p==-1)r=i;
  }
  SetDepth(r,0);

  for(i=0;i<n;i++){
    printf("node %d: ",i);
    printf("parent = %d, ",NT[i].p);
    printf("depth = %d, ",D[i]);
    if(NT[i].p==-1)printf("root, ");
    else if(NT[i].l==-1)printf("leaf, ");
    else printf("internal node, ");
    printf("[");
    for(j=0,c=NT[i].l;c!=-1;j++,c=NT[c].r){
      if(j==0)printf("%d",c);
      else printf(", %d",c);
    }
    printf("]\n");
  }
  return 0;
}

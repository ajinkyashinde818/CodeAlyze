#include<stdio.h>
#define N 100000

struct Node{
  int p,l,r;
};
struct Node NA[N];
int D[N];
void Set(int x,int p){
  D[x]=p;
  if(NA[x].r != -1)Set(NA[x].r,p);
  if(NA[x].l != -1)Set(NA[x].l,p+1);
}

int main(){

  int i,j,n,id;
  int k,c,l,r;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    NA[i].p=-1;
    NA[i].l=-1;
    NA[i].r=-1;
  }

  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&c);
      if(j==0)NA[id].l=c;
      else NA[l].r=c;
      l=c;
      NA[c].p=id;
    }
  }
  for(i=0;i<n;i++){
    if(NA[i].p==-1)r=i;
  }
  Set(r,0);

  for(i=0;i<n;i++){
    printf("node %d: ",i);
    printf("parent = %d, ",NA[i].p);
    printf("depth = %d, ",D[i]);
    if(NA[i].p==-1)printf("root, ");
    else if(NA[i].l==-1)printf("leaf, ");
    else printf("internal node, ");
    printf("[");
    for(j=0,c=NA[i].l;c!=-1;j++,c=NA[c].r){
      if(j==0)printf("%d",c);
      else printf(", %d",c);
    }
    printf("]\n");
  }
  return 0;
}

#include <stdio.h>
#define N 100001

struct Node{
  int p;
  int l;
  int r;
};
struct Node T[N];
int getDepth(int p){
  if(T[p].p == -1) return 0;
  return getDepth(T[p].p)+1;
}
int main()
{
  int n;
  int i,j;
  int sign;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].p=T[i].l=T[i].r=-1;
  }
  int k,c;
  int id;
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&k);
    for(j=0;j<k;j++){
      scanf("%d",&c);
      if(j==0){
	T[id].l=c;
	T[c].p=id;
	sign=c;
      }
      else{
	T[sign].r=c;
	T[c].p=id;
	sign=c;
      }
    }
  }
  int depth[N];
  for(i=0;i<n;i++)
    depth[i]=getDepth(i);
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,T[i].p,depth[i]);
    if(T[i].p==-1)
      printf("root, [");
    else if(T[i].l==-1)
      printf("leaf, [");
    else{
      printf("internal node, [");
    }
    if(T[i].l != -1){
      printf("%d",T[i].l);
      sign = T[i].l;
      while(1){
	if(T[sign].r==-1) break;
	printf(", %d",T[sign].r);
	sign = T[sign].r;
      }
    }
    printf("]\n");
  }
  return 0;
}

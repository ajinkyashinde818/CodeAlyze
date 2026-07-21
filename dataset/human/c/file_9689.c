#include<stdio.h>

struct Node{
  int p;
  int l;
  int r;
};
struct Node T[200002];

int getdepth(int a){
  if(T[a].p == -1){
    return 0;
  }
  return getdepth(T[a].p)+1;
}

int main(){
  int i,j,k,n,id,c,tmp;

  scanf("%d",&n);
  int depth[n];
  for(i=0;i<n;i++){
    T[i].p = T[i].l = T[i].r = -1;
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&k);
    for(j=0;j<k;j++){
      scanf("%d",&c);
      if(j==0){
        T[id].l=c;
        T[c].p=id;
        tmp=c;
      }
      else{
        T[tmp].r=c;
        T[c].p=id;
        tmp=c;
      }
    }
   }
    for(i=0;i<n;i++){
      depth[i]=getdepth(i);
    }
    for(i=0;i<n;i++){
      printf("node %d: parent = %d, depth = %d, ",i,T[i].p,depth[i]);
      if(T[i].p==-1){
        printf("root, [");
      }
      else if(T[i].l==-1){
        printf("leaf, [");
      }
      else{
        printf("internal node, [");
      }
      if(T[i].l != -1){
        printf("%d",T[i].l);
        tmp = T[i].l;
        while(1){
          if(T[tmp].r==-1) break;
          printf(", %d",T[tmp].r);
          tmp = T[tmp].r;
        }
       }
          printf("]\n");
      }
  return 0;
}

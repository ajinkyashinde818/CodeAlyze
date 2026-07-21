#include<stdio.h>
int n;
int id;
int t[100000];
int u[100000];
int v[100000];
int w[100000];
int tmp[100000];
 
void setdepth(int x){
  if(t[x]==-1){
    w[x]=0;
    return;
  }
  if(w[x]!=-1)return;
  setdepth(t[x]);
  w[x]=w[t[x]]+1;
}
 
void init(){
  int i;
  for(i=0;i<100000;i++){
    t[i]=-1;
    u[i]=-1;
    v[i]=-1;
    w[i]=-1;
  }
}
 
int main(){
  int i,j,k,pos;
 
  init();
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&tmp[j]);
      t[tmp[j]]=id;
      if(j>0)v[tmp[j-1]]=tmp[j];
    }
    if(k)u[id]=tmp[0];
  }
 
 
  for(i=0;i<n;i++){
    setdepth(i);
    printf("node %d: parent = %d, depth = %d, ",i,t[i],w[i]);
    if(w[i]==0)printf("root, ");
    else if(u[i]==-1)printf("leaf, ");
    else printf("internal node, ");
    pos=u[i];
    printf("[");
    if(pos!=-1){
      while(1){
    printf("%d",pos);
    pos=v[pos];
    if(pos==-1)break;
    printf(", ");
      }
    }
    printf("]\n");
     
  }
  return 0;
}

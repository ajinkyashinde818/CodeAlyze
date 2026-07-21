#include<stdio.h>
#define NIL -1
int parent[100001],cleft[100001],right[100001];
int depth(int i){
  int d=0;
  while(parent[i]!=NIL){
    d++;
    i=parent[i];
  }
  return d;
}
void printchildren(int i){
  int c=cleft[i];
  while(c!=NIL && right[c]!=NIL){
    printf("%d, ",c);
    c=right[c];
  }
  if(cleft[i]!=NIL)printf("%d",c);
}

int main(){
  int n;scanf("%d",&n);
  int i;
  for(i=0;i<=n-1;i++)parent[i]=cleft[i]=right[i]=NIL;
  for(i=0;i<=n-1;i++){
    int id,k;
    scanf("%d %d",&id,&k);
    int c[k+1],j;
    for(j=1;j<=k;j++)scanf("%d",&c[j]);
    if(k>=1){
      parent[c[1]]=id;
      cleft[id]=c[1];
    }
    for(j=2;j<=k;j++){
      parent[c[j]]=id;
      right[c[j-1]]=c[j];
    }
  }
    
    
  for(i=0;i<=n-1;i++){
    printf("node %d: parent = %d, depth = %d, ",i,parent[i],depth(i));
    if(parent[i]==NIL) printf("root, [");
    else if(cleft[i]==NIL) printf("leaf, [");
    else printf("internal node, [");
    printchildren(i);
    printf("]\n");
        
  }
    
  return 0;
}

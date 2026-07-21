#include<stdio.h>
#define NIL -1
#define n_max 100001
void pchild(int);
int parent[n_max],cleft[n_max],right[n_max];

int main(){
  int n, i, j, id, k;

  scanf("%d",&n);
  for(i=0;i<=n-1;i++)
    parent[i]=cleft[i]=right[i]=NIL;
  
  for(i=0;i<=n-1;i++){
    scanf("%d %d",&id,&k);

    int c[k+1];
    
    for(j=1;j<=k;j++){
      scanf("%d",&c[j]);
    }
    
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
    pchild(i);
    printf("]\n");
        
  }
    
  return 0;
}


int depth(int i){//深さをかえす
  int dep=0;
  while(parent[i]!=NIL){
    dep++;
    i=parent[i];
  }
  return dep;
}


void pchild(int i){//子供をプリントする
  int child=cleft[i];
  
  while(child!=NIL && right[child]!=NIL){
    printf("%d, ",child);
    child=right[child];
  }
  
  if(cleft[i]!=NIL)
    printf("%d",child);
}

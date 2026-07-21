#include <stdio.h>

#define MAX 100001
#define max(a,b) ((a) < (b) ? (b) : (a))

int par[MAX],sib[MAX],deg[MAX];
int height[MAX],dep[MAX];

void init(int);
int depth(int,int);

int main(){
  int n,i,id,l,r;

  scanf("%d" ,&n);
  init(n);

  for(i = 0 ; i < n ; i++){
    scanf("%d%d%d" ,&id ,&l ,&r);

    if(l != -1){
      par[l] = id;
      deg[id]++;
    }
    if(r != -1){
      par[r] = id;
      deg[id]++;
    }
if(l != -1 && r != -1){
  sib[l] = r;
  sib[r] = l;
 }
}

for(i = 0 ; i < n ; i++){
  dep[i] = depth(i,0);
 }

for(i = 0 ; i < n ; i++){
  printf("node %d: parent = %d, sibling = %d, "
         ,i, par[i], sib[i]);

  printf("degree = %d, depth = %d, height = %d, "
         , deg[i], dep[i], height[i]);

  if(par[i] == -1){
    printf("root\n");
  }else if(deg[i] != 0){
    printf("internal node\n");
  }else{
    printf("leaf\n");
  }
 }

return 0;
}

void init(int n){
  int i;

  for(i = 0 ; i < n ; i++){
    par[i] = sib[i] = -1;
    deg[i] = height[i] = 0;
  }
}

int depth(int x,int dep){
  height[x] = max(height[x],dep);
  if(par[x] == -1){
    return dep;
  }else{
    return depth(par[x],dep+1);
  }
}

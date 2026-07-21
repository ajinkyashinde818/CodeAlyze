#include <stdio.h>
 
#define M 100001
#define MAX(a,b) ((a) < (b) ? (b) : (a))
 
int par[M],sib[M],deg[M];
int height[M],deph[M];
 
void init(int);
int depth(int,int);
 
int main(void){
  int n,i,id,l,r,t;
 
  scanf("%d" ,&n); 
  init(n);  
 
  for(i = 0 ; i < n ; i++){
    scanf("%d%d%d" ,&id ,&l ,&t);
 

    if(l != -1){
      par[l] = id;
      deg[id]++;
    }
    if(t != -1){
      par[t] = id;
      deg[id]++;
    }
    if(l != -1 && t != -1){
      sib[l] = t;
      sib[t] = l;
    }
  }
 
  for(i = 0 ; i < n ; i++){
    deph[i] = depth(i,0);
  }
 
  for(i = 0 ; i < n ; i++){
    printf("node %d: parent = %d, sibling = %d, "
       ,i, par[i], sib[i]);
 
    printf("degree = %d, depth = %d, height = %d, "
       , deg[i], deph[i], height[i]);
     
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
  height[x] = MAX(height[x],dep);
  if(par[x] == -1){
    return dep;
  }else{
    return depth(par[x],dep+1);
  }
}

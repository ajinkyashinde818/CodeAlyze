#include <stdio.h>
#include <ctype.h>
     
int par[100000];
     
void init(int);
int dep(int);
int inp();
    
char *p;
char in[1500000];
int tree[100000][15],idx[100000];
    
int main(void){
  int n,i,j,id,k,c;
    
  fread(in,sizeof(in),1,stdin);  
  p = in;
    
  n = inp(); init(n);
  for(i = 0 ; i < n ; i++){
    id = inp();
    k = inp();
    for(j = 0 ; j < k ; j++){
      c = inp();
      par[c] = id;
      tree[id][idx[id]++] = c;
    }
  }
     
  for(i = 0 ; i < n ; i++){
    printf("node %d: parent = %d, depth = %d, "
           ,i,par[i],dep(i));
        
    if(par[i] == -1){
      printf("root, [");
    }else if(!idx[i]){
      printf("leaf, [");
    }else{
      printf("internal node, [");
    }
    
    for(j = 0 ; j < idx[i] ; j++){
      printf("%d",tree[i][j]);
      if(j < idx[i]-1) printf(", ");
    }
    puts("]");
  }
  return 0;
}
    
void init(int n){
  int i;
  for(i = 0 ; i < n ; i++){
    par[i] = -1;
  }
}
    
int dep(int x){
  if(par[x] == -1) return 0;
  return dep(par[x]) + 1;
}
    
int inp(){
  int v = 0;
  while(!isdigit(*p)) ++p;
  v = *p++&15;
  while(isdigit(*p)){
    v = (v<<3)+(v<<1)+(*p++&15);
  }
  return v;
}

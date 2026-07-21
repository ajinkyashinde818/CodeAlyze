#include <stdio.h>
#define MAX 100000
#define NIL -1

typedef struct{
  int p,l,r;
}Node;
 
Node T[MAX];
 
int depth(int x){
  if(T[x].p == NIL){
    return 0;
  }
  else{
    return depth(T[x].p) + 1;
  }       
}

void cprint(int y){
  if(y == NIL) return;

  if(T[y].r == NIL){
    printf("%d",y);
  }

  else{printf("%d, ",y);
  }

  if(T[y].r == NIL)return;
 
  cprint(T[y].r);
}
 
void print(int z){
 
  printf("node %d: parent = %d, depth = %d, %s, [",z,T[z].p,depth(z),T[z].p == NIL?"root":(T[z].l == NIL?"leaf":"internal node"));
  cprint(T[z].l);
  printf("]\n");
} 
 
 
int main(){
  int i,j,n,v,s,c,tmp;
   
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    T[i].p = NIL;
    T[i].l = NIL;
    T[i].r = NIL;
  }

  for(i = 0;i < n;i++){
    scanf("%d",&v);
    scanf("%d",&s);
    for(j = 0;j < s;j++){
      scanf("%d",&c);
      T[c].p = v;
      if(j == 0){
	T[v].l = c;
      }else{
	T[tmp].r = c;
      }
      tmp = c;     
    }
  } 
  for(i = 0;i < n;i++){
    print(i);
  }
  return 0;
}

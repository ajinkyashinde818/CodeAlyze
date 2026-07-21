#include <stdio.h>
#define MAX 26
typedef struct t{
  int p;
  int l;
  int r;
}tree;
int Depth(int);
void hantei(int,int,int);
int sibling(int,int);
int degree(int);
int height(int);
int max(int,int);
tree T[MAX];
int main(){
  
  int n,k,i,j,id,c,l,num = 0;
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    T[i].p = -1;
    T[i].l = -1;
    T[i].r = -1;
  }
  for(i = 0;i < n;i++){
    scanf("%d",&id);
      scanf("%d",&T[id].l);
      T[T[id].l].p = id;
      scanf("%d",&T[id].r);
      T[T[id].r].p = id;
  }
  for(i = 0;i < n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, "
	   ,i,T[i].p,sibling(i,n),degree(i),Depth(i),height(i));
    hantei(T[i].p,i,n);
    printf("\n");
  }
  return 0;
}
int Depth(int x){
  int d = 0;
  while(T[x].p != -1){
    x = T[x].p;
    d++;
  }
  return d;
}

void hantei(int p,int node,int n){
  int i,j,wr = 0,x;
  if(p == -1){
    printf("root");
    return;
  }
  if(T[node].l == -1 && T[node].r == -1){
    printf("leaf");
    
  }
  else{
    printf("internal node");
    
  }
}
int sibling(int node,int n){
  int i,j;
  for(i=0;i < n;i++){
    if(T[node].p == T[i].p && i != node){
      return i;
    }
  }
  return -1;
}
int degree(int node){
  int deg=0;
  if(T[node].r != -1){
      deg++;
  }
  if(T[node].l != -1){
    deg++;
  }
  return deg;
}
int height(int x){
  int dl = 0,dr = 0;
  if(T[x].l != -1){
      dl = 1+height(T[x].l);
  }
  if(T[x].r != -1){
    dr = 1+height(T[x].r);
  }
  return max(dl,dr);
}
int max(int x,int y){
  if(x > y)return x;
  return y;
}

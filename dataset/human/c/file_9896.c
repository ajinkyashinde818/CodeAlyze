#include<stdio.h>
 
typedef struct{
  int p,l,r;
} Node;
 
Node T[100000];
 
int n;
 
int depth(int a);
int print(int a);
 
int main(){
 
  int i,j,x,d,c,l;
 
  scanf("%d",&n);
  for(i=0;i<=n-1;i++) T[i].p = T[i].l = T[i].r = -1;
 
  for(i=0;i<n;i++){
    scanf("%d %d",&x,&d);
    for(j=0;j<d;j++){
      scanf("%d",&c);
      if(j==0){
	T[x].l=c;
      }

      else{
	T[l].r =c;
      }

      l=c;
      T[c].p=x;
    }
  }
 
  for ( i=0; i<n; i++ ) print(i);
  return 0;
}
 
int print(int a){
  int i, c;
  printf("node %d: parent = %d, depth = %d, ", a, T[a].p,depth(a));
 
  if(T[a].p==-1) printf("root, ");
  else if(T[a].l!=-1) printf("internal node, ");
  else printf("leaf, ");
 
  printf("["); 
 
  for(i=0, c=T[a].l; c!=-1; i++, c=T[c].r){
    if(i==0) printf("%d", c);
    else printf(", %d", c);
  }
  printf("]\n");
 
  return 0;
}
 
int depth(int a){
  int num=0,s=T[a].p;
  while(s!=-1){
    num++;
    s=T[s].p;
  }
  return num;
}

#include<stdio.h>
#define NIL -1
#define MAX 100000

typedef struct{
  int p,l,r;
}Node;

Node T[MAX];

int n;

int depth(int a){
  
  int num=0,s=T[a].p;
  
  while(s!=NIL){
    num++;
    s=T[s].p;
  }
  return num;
}

int main(){

  int i,j,x,d,c,l;

  scanf("%d",&n);
  
  for(i=0;i<n;i++) T[i].p = T[i].l = T[i].r = NIL;

  for(i=0;i<n;i++){
    scanf("%d %d",&x,&d);
    for(j=0;j<d;j++){
      scanf("%d", &c);
      if(j==0) T[x].l=c;
      else T[l].r =c;
      l=c;
      T[c].p=x;
    }
  }
  for(i=0;i<n;i++){
  printf("node %d: parent = %d, depth = %d, ", i, T[i].p,depth(i));

  if(T[i].p==NIL) printf("root, ");
  else if(T[i].l!=NIL) printf("internal node, ");
  else printf("leaf, ");

  printf("["); 

  for(j=0, c=T[i].l; c!=NIL; j++, c=T[c].r){
    if(j==0) printf("%d", c);
    else printf(", %d", c);
  }
  printf("]\n");
  }
  return 0;
}

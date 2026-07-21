#include<stdio.h>

typedef struct{int p,l,r;}Node;
Node T[100000];

int getD(int);
void printC(int,int);

int main(){
  int n,i,k,j,id,c,l,r;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].p = -1;
    T[i].l = -1;
    T[i].r = -1;
  }
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&c);
      if(j == 0) T[id].l = c;
      else T[l].r = c;
      l = c;
      T[c].p = id;
    }
  }
  for(i=0;i<n;i++){
    if(T[i].p == -1)r = i;
  }

  for(i=0;i<n;i++)printC(i,getD(i));
      
  return 0;
}

int getD(int u){
  int d=0;
  while(T[u].p != -1){
    u = T[u].p;
    d++;
  }
  return d;
}

void printC(int u,int d){
  int i,c;
  c = T[u].l;
  printf("node %d: ",u);
  printf("parent = %d, ",T[u].p);
  printf("depth = %d, ",d);

  if(T[u].p == -1)printf("root, ");
  else if(T[u].l == -1)printf("leaf, ");
  else printf("internal node, ");
  printf("[");
  i=0;
  while(c != -1){
    if(i)printf(", ");
    printf("%d",c);
    c = T[c].r;
    i++;
  }
  printf("]\n");
}

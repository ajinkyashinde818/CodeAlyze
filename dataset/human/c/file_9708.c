#include<stdio.h>
#include<stdlib.h>

#define NIL -1
#define MAX 100005

int getdep(int);
char* gettype(int);

typedef struct Node{
  int id;
  int k;
  int par;
  int dep;
  char* type;
  int* chi;
}Node;

Node T[MAX];
  
int main(){
  int n,i,j,u;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].id=NIL;
    T[i].par=NIL;
  }

  for(i=0;i<n;i++){
    scanf("%d",&u);
    T[u].id=u;
    scanf("%d",&T[u].k);
    if(T[u].k>0){
      T[u].chi=(int*)malloc(T[u].k*sizeof(int));
      for(j=0;j<T[u].k;j++){
	scanf("%d",&T[u].chi[j]);
	T[T[u].chi[j]].par=T[u].id;
      }
    }
  }

  for(i=0;i<n;i++){
    T[i].dep=getdep(i);
    T[i].type=gettype(i);
  }

  for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, %s, [",i,T[i].par,T[i].dep,T[i].type);
    if(T[i].k!=0){
      printf("%d",T[i].chi[0]);
      for(j=1;j<T[i].k;j++){
	printf(", %d",T[i].chi[j]);
      }
    }
    printf("]\n");
  }
  return 0;
}

int getdep(int u){
  int d=0;
  while(T[u].par != NIL){
    u=T[u].par;
    d++;
  }

  return d;
}

char* gettype(int u){
  if(T[u].par != NIL){
    if(T[u].k == 0)
      return "leaf";
    else
      return "internal node";
  }
  else
    return "root";
}

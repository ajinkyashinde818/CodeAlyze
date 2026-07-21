#include<stdio.h>
#define N 100000
struct Node{
  int p;
  int l;
  int r;
};
struct Node T[N];
int main(){
  int id,c,n,i,j,a,d[N];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].p = -1;
    T[i].l = N;
    T[i].r = N;
    d[i] = 0;
  }
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&c);
    if(c == 1){
      scanf("%d",&T[id].l);
      a = T[id].l;
      T[a].p = id;
    }
    else if(c > 1){
      scanf("%d",&T[id].l);
      a = T[id].l;
      for(j=1;j<c;j++){
	scanf("%d",&T[a].r);
	T[a].p = id;
	a = T[a].r;
      }
      T[a].p = id;
    }
  }
  for(i = 0;i<n;i++){
    a = T[i].p;
    while(1){
      if(a == -1){
	break;
      }
      else{
	a = T[a].p;
	d[i]++;
      }
    }
    printf("node %d: parent = %d, depth = %d,",i,T[i].p,d[i]);
    if(T[i].p == -1){
      if(T[i].l == N){
	printf(" root, []\n");
      }
      else{
	printf(" root, [%d",T[i].l);
	a = T[i].l;
	while(T[a].r != N){
	  printf(", %d",T[a].r);
	  a = T[a].r;
	}
	printf("]\n");
      }
    }
    else if(T[i].l == N)
      printf(" leaf, []\n");
    else{
      printf(" internal node, [%d", T[i].l);
      a = T[i].l;
      while(T[a].r != N){
	printf(", %d",T[a].r);
	a = T[a].r;
      }
      printf("]\n");
    }
  }
  return 0;
}

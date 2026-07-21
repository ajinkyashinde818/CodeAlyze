#include <stdio.h>
#define N 100000

struct Node{
  int p;
  int l;
  int r;
};

struct Node T[N];

int D[N];
 
int Depth(int x){
  int sum = 0;
  while(T[x].p != -1){
    sum++;
    x = T[x].p;
  }
  return sum;
}

int main(void){
  int n,i,j,k,c,s,node;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].p = T[i].l = T[i].r = -1;
  }

  for(i=0;i<n;i++){
    scanf("%d",&node);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&c);
      if(j==0){
	T[node].l = c;
	T[c].p = node;
	s = c;
      }else{
	T[s].r = c;
	T[c].p = node;
	s = c;
      }
    }
  }

  for(i=0;i<n;i++){
    D[i] = Depth(i);
  }

  for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d,",i,T[i].p,D[i]);

    if(T[i].p == -1) printf(" root, [");
    else if(T[i].l == -1) printf(" leaf, [");
    else printf(" internal node, [");

    if(T[i].l != -1){
      while(1){

	if(T[T[i].l].r == -1){
	  printf("%d",T[i].l);
	  break;
	}
	else{
	  printf("%d, ",T[i].l);
	  T[i].l = T[T[i].l].r;
	}
      }
    }
    printf("]\n");
  }
  return 0;
}

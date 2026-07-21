#include<stdio.h>

typedef struct {
  int node;
  int p;
  int type;
  int left;
  int right;
  int a;
} Node;

Node T[100000];
int A[100000];

int depth(int count,int p){
  count++;
  if(T[p].p == -1) return count;
  depth(count,T[p].p);
}

int main(){
  int n,i,j,k,l,m;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    T[i].a = 0;
    T[i].right = T[i].left = -1;
  }

  for(i = 0;i < n;i++){
    scanf("%d",&j);
    T[j].node = j;
    T[j].type = 2;
    scanf("%d",&k);
    if(k) T[j].type = 1;
    for(l = 0;l < k;l++){
      scanf("%d",&m);
      if(l == 0) T[j].left = m;
      A[l] = m;
      T[m].p = j;
      T[m].a = 1;
      if(l) T[A[l-1]].right = A[l];
    }
  }

  for(i = 0;i < n;i++){
    if(T[i].a == 0){
      T[i].p = -1;
      T[i].type = 0;
    }
  }

  for(i = 0;i < n;i++){
    k = 0;
    printf("node %d: parent = %d, depth = %d, ",T[i].node,T[i].p,depth(-1,T[i].node));
    if(T[i].type == 0) printf("root, ");
    else if(T[i].type == 1) printf("internal node, ");
    else printf("leaf, ");
    printf("[");
    for(j = T[i].left;j != -1;j = T[j].right){
        if(k) printf(", ");
        printf("%d",T[j].node);
        k++;
    }
    printf("]\n");
  }

  return 0;
}

#include<stdio.h>
#include<stdlib.h>

#define N 100000
#define NIL -1

typedef struct Node{
  int parent, child, side;
}node;

void calc(int, int);

node A[N];
int n, depth[N];

int main(){
  int i, j, num, ch_num, root, ch, a, b;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    A[i].parent = NIL;
    A[i].child = NIL;
    A[i].side = NIL;
  }

  for(i = 0; i < n; i++){
    scanf("%d%d", &num, &ch_num);

    for(j = 0; j < ch_num; j++){
      scanf("%d", &ch);
      
      if(j == 0)
        A[num].child = ch;

      else
        A[a].side = ch;

      a = ch;
      A[a].parent = num;
    }
  }

  for(i = 0; i < n; i++){
    if(A[i].parent == NIL)
      root = i;
  }
  
  calc(root, 0);

  for(i = 0; i < n; i++){

    printf("node %d: parent = %d, depth = %d, ", i, A[i].parent, depth[i]);

    if(A[i].parent == NIL)
      printf("root, ");

    else if(A[i].child == NIL)
      printf("leaf, ");

    else
      printf("internal node, ");

    printf("[");
    
    ch = A[i].child;
    j = 0;

    while(ch != NIL){
      if(j != 0)
        printf(", ");

      printf("%d", ch);

      ch = A[ch].side;
      j++;
    }

    printf("]\n");
  }
  
  return 0;
}

void calc(int i, int d){
  depth[i] = d;
  if(A[i].side != NIL)
    calc(A[i].side, d);
  if(A[i].child != NIL)
    calc(A[i].child, d+1);
}

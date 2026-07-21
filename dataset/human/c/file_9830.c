#include<stdio.h>
#define MAX 100000

 typedef struct {
  int parent;
  int left;
  int right;
}Tree;

Tree a[MAX];

int getDepth(int);

int main(){
  int i,j,n;
  int num,deg,child,k = 0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    a[i].parent = -1;
    a[i].left = -1;
    a[i].right = -1;
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&num,&deg);

    for(j=0;j<deg;j++){
      scanf("%d",&child);
      if(j==0) a[num].left=child;
      else a[k].right=child;
      k=child;
      a[child].parent=num;
    }
  }

  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, depth = %d",i,a[i].parent,getDepth(i));

    if(getDepth(i) == 0){
      printf(", root, [");
    }
    else if(a[i].left == -1){
      printf(", leaf, [");
    }
    else{
      printf(", internal node, [");
    }

    j=a[i].left;

    while(j != -1){
      printf("%d", j);
      j = a[j].right;

      if(j != -1){
    printf(", ");
      }
    }
    printf("]\n");
  }

  return 0;
}
int getDepth(int num){
   int depth = 0;

  while(a[num].parent != -1){
    num = a[num].parent;
    depth++;
  }
return depth;
}

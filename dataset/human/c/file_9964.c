#include <stdio.h>

typedef struct {
  int left;
  int right;
  int d;
  int p;
} node;

node a[100000];

int x(int y)
{
  
  if(a[y].d != -1){
    return a[y].d;
  }
  
  if(a[y].p == -1){
    a[y].d = 0;
    return 0;
  }
  
  a[y].d = x(a[y].p)+1;
  return a[y].d;
  
}


int main()
{

  int n, id, i, k, j, c1, c2;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    a[i].d = -1;
    a[i].p = -1;
    a[i].right = -1;
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&id,&k);
    if(k==0){
      a[id].left = -1;
    }
    else{
      for(j=0;j<k;j++){
	if(j==0){
	  scanf("%d",&c1);
	  a[id].left = c1;
	  a[c1].p = id;
	}
	else{
	  scanf("%d",&c2);
	  a[c2].p = id;
	  a[c1].right = c2;
	  c1 = c2;
	}
      }
    }
  }

  for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,a[i].p,x(i));
    if(a[i].p==-1){
      printf("root, [");
    }
    else if(a[i].left==-1){
      printf("leaf, [");
    }
    else{
      printf("internal node, [");
    }

    c1 = a[i].left;

    if(c1!=-1){
      while(1){
	c2 = a[c1].right;
	if(c2==-1){
	  printf("%d",c1);
	  break;
	}
	else{
	  printf("%d, ",c1);
	  c1 = c2;
	}
      }
    }

    printf("]\n");
  }

  return 0;
  
}

#include<stdio.h>
#define MAX 1000000

typedef struct{

  int x,y,z;

}Tree;


Tree a[MAX];

int Depth(int);

int main(){

  int i,j,n,num,d,c,k=0;


  scanf("%d",&n);

  for(i = 0; i < n ;i++){

    a[i].x = -1;
    a[i].y = -1;
    a[i].z = -1;
  }


  for(i = 0; i < n ;i++){

    scanf("%d%d",&num,&d);

    for(j = 0; j < d; j++){

      scanf("%d",&c);

      if(j == 0)a[num].y = c;

      else a[k].z = c;

      k = c;
      a[c].x = num;

    }
  }


  for(i = 0; i < n; i++){

    printf("node %d: parent = %d, depth = %d,",i,a[i].x,Depth(i));

    if(Depth(i) == 0) printf(" root, [");

    else if(a[i].y == -1) printf(" leaf, [");

    else printf(" internal node, [");

    j = a[i].y;

    while(j != -1){

      printf("%d",j);

      j = a[j].z;

      if(j != -1){

	printf(", ");
      }
    }

    printf("]\n");
  }

  return 0;
}



int Depth(int num){

  int dep = 0;

  while(a[num].x != -1){

    num = a[num].x;
    dep++;
  }

  return dep;
}

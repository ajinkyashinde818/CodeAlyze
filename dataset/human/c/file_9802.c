#include<stdio.h>

typedef struct{
  int p,l,r;
}node;



int main(){

  int i,j,k,n,id,d,c,a;

  node T[100000];

  scanf("%d",&n);

  for(i=0;i<n;i++)
    T[i].p = T[i].r = T[i].l = -1;

  for(i=0;i<n;i++){
    scanf("%d %d",&id,&k);

    for(j=0;j<k;j++){
      scanf("%d",&c);
      T[c].p = id;
      if(j == 0)T[id].l = c;
      else T[a].r = c;
      a = c;
    }

  }

  for(i=0;i<n;i++){
 
    a = T[i].p;
    d = 0;
    while(a != -1){
      d++;
      a = T[a].p;
    }

    printf("node %d: parent = %d, depth = %d, ",i,T[i].p,d);
    if(T[i].p == -1)printf("root, [");
    else if(T[i].l == -1)printf("leaf, [");
    else printf("internal node, [");

    a = T[i].l;
    if(a != -1){
      printf("%d",T[i].l);
      while(T[a].r != -1){
	printf(", %d",T[a].r);
	a = T[a].r;
      }
    }

    printf("]\n");

  }

    return 0;
}

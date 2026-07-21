#include<stdio.h>

int depth(int);
void P(int);

struct node{
  int p,l,r;
};

struct node tree[100005];
int n,D[100005];

main(void){

  int i,j,d,e,c,l,r;
   
  scanf("%d",&n);
   
  for (i=0;i<n;i++){
    tree[i].p=tree[i].l=tree[i].r=-1;
  }

  for(i=0;i<n;i++){
    scanf("%d %d",&e,&d);
    for(j=0;j<d;j++){
      scanf("%d",&c);
      tree[c].p=e;
       
      if(j==0){
	tree[e].l=c;
      }
      
      else if(j>=1){
	tree[r].r=c;
      }
      r=c;
      
    }
   }
   
  for(i=0;i<n;i++){
    D[i]=depth(i);
  }
 
  for(i=0;i<n;i++){
    P(i);
  }
  return 0;
}

int depth(int x){

  int d=0;
 
  while(tree[x].p>=0){
    x=tree[x].p;
    d=d+1;
  }
  return d;
}
void P(int y){
  if(tree[y].p==-1){
    printf("node %d: parent = %d, depth = %d, root, ",y,tree[y].p,D[y]);
  }
   
  else if(tree[y].l==-1){
    printf("node %d: parent = %d, depth = %d, leaf, ",y,tree[y].p,D[y]);
  }
   
  else printf("node %d: parent = %d, depth = %d, internal node, ",y,tree[y].p,D[y]);
   
  printf("[");
  int t;
  t = y;
  if(tree[t].l!=-1){
    printf("%d",tree[t].l);
    if(tree[tree[t].l].r==-1){
      printf("]\n");
    }
    else printf(",");
    t =tree[t].l;
    while(tree[t].r!=-1){
      printf(" %d",tree[t].r);
      if(tree[tree[t].r].r==-1){
	printf("]\n");
      }
      else printf(",");
      t=tree[t].r;
    }
  }
  else printf("]\n");
}

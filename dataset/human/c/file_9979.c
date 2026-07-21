#include<stdio.h>
struct Node{
  int a,b,c;
};
struct Node N[100000];
int h,o,S[100000];

int depth(int);

int main(){
  int i,j,l,m,n,q,e,y;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    N[i].a=-1;
    N[i].b=-1;
    N[i].c=-1;
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&l,&m);
    for(j=0;j<m;j++){
      scanf("%d",&q);
      if(j==0){
        N[l].b=q;
      }
      else{
        N[y].c=q;
      }
      y=q;
      N[q].a=l;
      }
    }
    for(i=0;i<n;i++){
      S[i]=depth(i);
    }
    for(i=0;i<n;i++){
      printf("node %d: ",i);
      printf("parent = %d, ",N[i].a);
      printf("depth = %d, ",S[i]);
      if(N[i].a==-1){
        printf("root, ");
      }
      else if(N[i].b==-1){
        printf("leaf, ");
      }
      else{
        printf("internal node, ");
      }
      printf("[");
      for(j=0,e=N[i].b;e!=-1;j++,e=N[e].c){
        if(j>0){
          printf(", ");
        }
        printf("%d",e);
      }
      printf("]\n");
    }
    return 0;
}

int depth(int r){
  int t=0;
  for(; N[r].a!=-1 ;t++){
    r=N[r].a;
  }
  return t;
}

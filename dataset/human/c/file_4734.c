#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
  int p,l,r;
}Tr;

Tr T[25];

int H(int);
int n;

int main(){
  int i,j,l,r,id;
  int s[25],deg[25],dep[25],h[25];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    T[i].p=T[i].l=T[i].r= s[i]=-1;
    deg[i]=dep[i]= h[i]=0;
  }

  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&l,&r);

    if(r!=-1){
      T[r].p=id;
      deg[id]++;
    }
    if(l!=-1){
      T[l].p=id;
      deg[id]++;
    }

    T[id].l=l;
    T[id].r=r;
    s[l]=r;
    s[r]=l;
  }

  for(i=0;i<n;i++){
    j=i;

    while(T[j].p!=-1){
      j=T[j].p;
      dep[i]++;
    }
    h[i]=H(i);
  }

  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,T[i].p,s[i],deg[i],dep[i],h[i]);

    if(T[i].p==-1){
      printf("root\n");
    }else if(T[i].l==-1 && T[i].r==-1){
      printf("leaf\n");
    }else{
      printf("internal node\n");
    }
  }

  return 0;
}

int H(int a){
  int i,c=0,x=0;

  for(i=0;i<n;i++){
    if(T[i].p==a){
      c=H(i)+1;

      if(c>x){
	x=c;
      }
    }
  }

  return x;
}

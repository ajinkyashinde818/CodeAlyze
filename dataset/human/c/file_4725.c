#include<stdio.h>
#define N 10000

void sD(int,int);
int sH(int);
int gS(int);

typedef struct{
  int p,l,r;
}Node;

Node T[N];
int n;
int D[N],H[N];

void sD(int a,int b){
  if(a==-1)return;
  D[a] = b;
  sD(T[a].l,b+1);
  sD(T[a].r,b+1);
}
int sH(int a){
  int x=0,y=0;
  if(T[a].l!=-1)x = sH(T[a].l)+1;
  if(T[a].r!=-1)y = sH(T[a].r)+1;
  return H[a]=(x>y?x:y);
}
int gS(int a){
  if(T[a].p == -1)return -1;
  if(T[T[a].p].l!=a && T[T[a].p].l != -1)return  T[T[a].p].l;
  if(T[T[a].p].r!=a && T[T[a].p].r != -1)return  T[T[a].p].r;
  return -1;
}

int main(){
  int i,v,l,r,d,root=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    T[i].p=-1;
  }
  for(i=0;i<n;i++){
    scanf("%d %d %d",&v,&l,&r);
    T[v].l=l;
    T[v].r=r;

    if(l!=-1)T[l].p=v;
    if(r!=-1)T[r].p=v;

  }
  for(i=0;i<n;i++){
    if(T[i].p==-1)root = i;
}
  sD(root,0);
  sH(root);

  for(i=0;i<n;i++){
    printf("node %d: " , i);
    printf("parent = %d, ",T[i].p);
    printf("sibling = %d, ",gS(i));
    d = 0;

    if(T[i].l != -1)d++;
    if(T[i].r != -1)d++;
    printf("degree = %d, " , d);
    printf("depth = %d, ", D[i]);
    printf("height = %d, ", H[i]);


    if(T[i].p == -1)printf("root\n");
    else if(T[i].l == -1 && T[i].r == -1)printf("leaf\n");
    else printf("internal node\n");
  }
  return 0;
}

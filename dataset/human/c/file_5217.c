#include<stdio.h>

#define MAX 100000

typedef struct{
  int p,r,l;
}Node;

Node T[MAX];
int a,d[MAX],h[MAX];


int sibling(int);
void depth(int,int);
int height(int);
void print(int);


int main()
{
  int a,b,r,l,c=0;
  int i;
  
  scanf("%d",&a);
  
  for(i=0;i<a;i++){
    T[i].p=-1;
  }
  
  for(i=0;i<a;i++){
    scanf("%d%d%d",&b,&l,&r);
    T[b].l=l;
    T[b].r=r;
    if(r!=-1) T[r].p=b;
    if(l!=-1) T[l].p=b;
  }
  
  for(i=0;i<a;i++){
    if(T[i].p==-1) c=i;
  }
  
  depth(c,0);
  height(c);
  
  for(i=0;i<a;i++){
    print(i);
  }
  
  return 0;
}


void depth(int a, int b)
{
  if(a==-1) return;
  
  d[a]=b;
  depth(T[a].l,b+1);
  depth(T[a].r,b+1);
}


int height(int a)
{
  int r=0,l=0;
  
  if(T[a].r!=-1) r=height(T[a].r)+1;
  if(T[a].l!=-1) l=height(T[a].l)+1;
  if(T[a].r==-1 && T[a].l==-1) return 0;
  if(l>r) return h[a]=l;
  else return h[a]=r;
}


int sibling(int a)
{
  if(T[a].p==-1) return -1;
  if(T[T[a].p].l!=a && T[T[a].p].l!=-1) return T[T[a].p].l;
  if(T[T[a].p].r!=a && T[T[a].p].r!=-1) return T[T[a].p].r;
  return -1;
}


void print(int a)
{
  int s=0;
  
  printf("node %d: parent = %d,",a,T[a].p);
  printf(" sibling = %d,",sibling(a));
  
  if(T[a].l!=-1) s++;
  if(T[a].r!=-1) s++;
  
  printf(" degree = %d,",s);
  printf(" depth = %d, height = %d, ",d[a],h[a]);
  
  if(T[a].p==-1) printf("root\n");
  else if(T[a].l==-1 && T[a].r==-1) printf("leaf\n");
  else printf("internal node\n");
}

#include<stdio.h>
#define n 100

struct Node{
  int l,r,p;
};
struct Node t[n];
int m;
int d[n],h[n];

int depth(int u){
  int a=0;
  while(1){
    u=t[u].p;
    if(u==-1)break;
    a++;
  }
  return a;
}
int sibling(int u){
  if(t[u].p==-1) return -1;
    if(t[t[u].p].l!=u && t[t[u].p].l!=-1) return t[t[u].p].l;
  if(t[t[u].p].r!=u && t[t[u].p].r!=-1) return t[t[u].p].r;
  return -1;
}

void print(int i){
  int a=0;
  printf("node %d: ",i);
  printf("parent = %d, ",t[i].p);
  printf("sibling = %d, ",sibling(i));
  if(t[i].l!=-1)a++;
  if(t[i].r!=-1)a++;
    printf("degree = %d, ",a);
  printf("depth = %d, ",d[i]);
  printf("height = %d, ",h[i]);
  if(t[i].p==-1){
    printf("root\n");
  }
  else if(t[i].l==-1 && t[i].r==-1){
    printf("leaf\n");
  }
  else {
    printf("internal node\n");
  }
}

int main(){
  int i,r,l,x,p;
  scanf("%d",&m);
  for(i=0;i<m;i++){
    t[i].p=-1;
  }

  for(i=0;i<m;i++){
          scanf("%d%d%d",&x,&l,&r);
    t[x].l=l;
    t[x].r=r;
    if(l!=-1)t[l].p=x;
    if(r!=-1)t[r].p=x;
  }

  for(i=0;i<m;i++){
    d[i]=depth(i);
    h[i]=0;
  }
  
  for(i=0;i<m;i++){
    if(t[i].l==-1 && t[i].r==-1){
      h[i]=0;
      p=t[i].p;
      int a=1;
      while(1){
        if(p==-1)break;
        if(h[p]<a)h[p]=a;
        a++;
        p=t[p].p;
      }
    }
  }
  for(i=0;i<m;i++){
    print(i);
  }
  return 0;
}

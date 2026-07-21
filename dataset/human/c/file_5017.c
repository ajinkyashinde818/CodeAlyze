#include<stdio.h>
#define MAX 10000
#define NO -1
typedef struct Node{
  int p,l,r;
}S;
S tree[MAX];
int getdepth(int x){
  int d=0;
  while(tree[x].p!=NO){
    x=tree[x].p;
    d++;
  }
  return d;
}
int getheight(int y){
  int h1=0,h2=0;
  if(tree[y].l!=NO)h1=getheight(tree[y].l)+1;
  if(tree[y].r!=NO)h2=getheight(tree[y].r)+1;
  if(h1>h2)return h1;
  else return h2;
}
int getsibling(int x){
  if(tree[x].p==NO)return NO;
  if(tree[tree[x].p].l!=x && tree[tree[x].p].l!=NO)return tree[tree[x].p].l;
  if(tree[tree[x].p].r!=x && tree[tree[x].p].r!=NO)return tree[tree[x].p].r;
  return NO;
}
void out(int y){
  int i,j;
  printf("node %d: ",y);
  printf("parent = %d, ",tree[y].p);
  printf("sibling = %d, ",getsibling(y));
  int d=0;
  if(tree[y].l!=NO)d++;
  if(tree[y].r!=NO)d++;
  printf("degree = %d, ",d);
  printf("depth = %d, ",getdepth(y));
  printf("height = %d, ",getheight(y));
  if(tree[y].p==NO)printf("root\n");
  else if(tree[y].l==NO && tree[y].r==NO)printf("leaf\n");
  else printf("internal node\n");
}
int main(){
  int n,i,j,a,b,c;
  scanf("%d",&n);
  for(i=0;i<n;i++)tree[i].p=tree[i].r=tree[i].l=NO;
  for(i=0;i<n;i++){
    scanf("%d%d%d",&a,&b,&c);
    tree[a].l=b;
    tree[a].r=c;
    if(b!=NO)tree[b].p=a;
    if(c!=NO)tree[c].p=a;
  }
  for(i=0;i<n;i++)if(tree[i].p==NO)j=i;
  getheight(j);
  for(i=0;i<n;i++)out(i);
  return 0;
}

#include<stdio.h>
#define NTL -1
#define M 25
typedef struct tree{
  int p;
  int l;
  int r;
}tree;
int depth(int,tree *);
int hei(int,tree *);
int sib(int,tree *);
int deg(int, tree *);
int type(int,tree *);
int h[M];
int main(){
  int n,i,j,now,chi,bchi,num;
  /*scan n*/
  scanf("%d",&n);
  tree t[n];
  /*NTL*/
  for(i=0;i<n;i++){
    t[i].p=NTL;
  }
  /*scan tree*/
  for(i=0;i<n;i++){
    scanf("%d",&now);
    scanf("%d %d",&t[now].l,&t[now].r);
    if(t[now].l!=NTL) t[t[now].l].p=now;
    if(t[now].r!=NTL) t[t[now].r].p=now;
  }
  /* print*/
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, ",i,t[i].p,sib(i,t));
    printf("degree = %d, depth = %d, height = %d, ",deg(i,t),depth(i,t),hei(i,t) );
    if(type(i,t) == 1){
      printf("root\n");
    }
    else if(type(i,t) == 2){
      printf("internal node\n");
    }
    else if(type(i,t) == 3)printf("leaf\n");
  }
  return 0;
}
int depth(int num,tree *t){
  int d=0;
  while(t[num].p != NTL){
    d++;
    num = t[num].p;
  }
  return d;
}
int hei(int now,tree *t){
  int hl=0;
  int hr=0;
  if(t[now].l!=-1) hl=hei(t[now].l,t)+1;
  if(t[now].r!=-1) hr=hei(t[now].r,t)+1;
  if(hl>hr) h[now]=hl;
  else h[now]=hr;
  return h[now];
}

int sib(int now,tree *t){
  if(t[now].p==-1) return -1;
  if(t[t[now].p].l!=now && t[t[now].p].l!=-1){
    return t[t[now].p].l;
  }
  else if(t[t[now].p].r!=now && t[t[now].p].r!=-1){
    return t[t[now].p].r;
  }
  else return -1;
}

int deg(int now,tree *t){
  int deg=0;
  if(t[now].l!=-1){
    deg++;
  }
  if(t[now].r!=-1){
    deg++;
  }
  return deg;
}
int type(int num,tree *t){
  if(t[num].p == NTL) return 1;/*root*/
  else if(t[num].l != NTL || t[num].r != NTL) return 2;/*internal*/
  else if(t[num].l == NTL && t[num].r == NTL) return 3;/*leaf*/
  return 3;
}

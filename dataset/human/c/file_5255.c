#include<stdio.h>

typedef struct{
  int p,l,r,d,h,s;
}N;

N T[30];
int rec1(int r,int p){
  T[r].d = p;
  if(T[r].r!=-1) rec1(T[r].r,p+1);
  if(T[r].l!=-1) rec1(T[r].l,p+1);
}
int rec2(int a){
  int l,r;
  if(a==-1) return 0;
  if(T[a].l==-1 && T[a].r==-1) return 0;
  l = rec2(T[a].l)+1;
  r = rec2(T[a].r)+1;
  return l > r ? l : r;
}
int main(){

  int n,id,l,r;
  int i;
  int degree;
  int a;
  scanf("%d",&n);
  for(i=0;i<n;i++) T[i].r = T[i].l = T[i].p = T[i].s = -1;
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d%d",&l,&r);
    T[id].l = l;
    T[id].r = r;
    T[l].p = T[r].p = id;
    T[l].s = r;
    T[r].s = l;
  }
  for(i=0;i<n;i++) if(T[i].p==-1) a = i;
  rec1(a,0);
  for(i=0;i<n;i++) T[i].h = rec2(i);
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, ",i,T[i].p,T[i].s);
    degree = 0;
    if(T[i].l!=-1) degree++;
    if(T[i].r!=-1) degree++;
    printf("degree = %d, depth = %d, height = %d, ",degree,T[i].d,T[i].h);
    if(T[i].p==-1) printf("root");
    else if(T[i].r!=-1 || T[i].l!=-1) printf("internal node");
    else printf("leaf");
    printf("\n");
  }

  return 0;
}

#include<stdio.h>
#define MAX 100000
struct Node{
  int p,l,r;
};
struct Node T[MAX];
int dp[MAX],f[MAX];

void SetDe(int x,int c){
  if(x==-1)return;
  dp[x]=c;                                                        
  SetDe(T[x].r,c+1);
  SetDe(T[x].l,c+1);
}

int SetHei(int x){
  int k1=0,k2=0;
  if(T[x].l!=-1)k1=SetHei(T[x].l)+1;
  if(T[x].r!=-1)k2=SetHei(T[x].r)+1;
  if(k1>k2)return f[x]=k1;
  else return f[x]=k2;
}
int GetSibling(int x){
  if(T[x].p==-1)return -1;
  if(T[T[x].p].l!=x && T[T[x].p].l!=-1)return T[T[x].p].l;
  if(T[T[x].p].r!=x && T[T[x].p].r!=-1)return T[T[x].p].r;
  return -1;
}
int main(){
  int i,n,id;
  int le,ri,ro,deg;  
  scanf("%d",&n);
  for(i=0;i<n;i++)T[i].p=-1;
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d",&le);
    scanf("%d",&ri);
    T[id].l=le;
    T[id].r=ri;
    if(le!=-1)T[le].p=id;
    if(ri!=-1)T[ri].p=id;
  }
  for(i=0;i<n;i++){
    if(T[i].p==-1)ro=i;
  } 
  SetDe(ro,0);
  SetHei(ro);
  for(i=0;i<n;i++){
    deg=0;
    printf("node %d: ",i);
    printf("parent = %d, ",T[i].p);
    printf("sibling = %d, ",GetSibling(i));
    if(T[i].l!=-1) deg++;
    if(T[i].r!=-1) deg++;
    printf("degree = %d, ",deg);
    printf("depth = %d, ",dp[i]);
    printf("height = %d, ",f[i]);
    if(T[i].p==-1)printf("root\n");
    else if(T[i].l==-1 && T[i].r==-1)printf("leaf\n");
    else printf("internal node\n");				       
    }
  return 0;
}

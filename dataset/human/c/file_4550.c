#include<stdio.h>
typedef struct{
  int p,l,r,d,h,s;
}Node;
Node A[30];
int rec(int r,int p){
  A[r].d = p;
  if(A[r].r!=-1) rec(A[r].r,p+1);
  if(A[r].l!=-1) rec(A[r].l,p+1);
}
int rec2(int a){
  int l,r;
  if(a==-1) return 0;
  if(A[a].l==-1 && A[a].r==-1) return 0;
  l = rec2(A[a].l)+1;
  r = rec2(A[a].r)+1;
  return l > r ? l : r;
}
int main(){
  
  int n,id,l,r;
  int i;
  int degree;
  int a;
  scanf("%d",&n);
  for(i=0;i<n;i++) A[i].r = A[i].l = A[i].p = A[i].s = -1;
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d%d",&l,&r);
    A[id].l = l;
    A[id].r = r;
    A[l].p = A[r].p = id;
    A[l].s = r;
    A[r].s = l;
  }
  for(i=0;i<n;i++) if(A[i].p==-1) a = i;
  rec(a,0);
  for(i=0;i<n;i++) A[i].h = rec2(i);
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, ",i,A[i].p,A[i].s);
    degree = 0;
    if(A[i].l!=-1) degree++;
    if(A[i].r!=-1) degree++;
    printf("degree = %d, depth = %d, height = %d, ",degree,A[i].d,A[i].h);
    if(A[i].p==-1) printf("root");
    else if(A[i].r!=-1 || A[i].l!=-1) printf("internal node");
    else printf("leaf");
    printf("\n");
  }
    
  return 0;
}

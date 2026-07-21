#include<stdio.h>
#define N 25

typedef struct{
  int p;
  int sib;
  int left;
  int right;
  int deg;
  int dep;
  int hei;
  
}Node;

Node T[N];

void depth(int,int);
void height(int,int);

int main(){
  int n,i,j,l,r,key;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
   T[i].p=-1;
   T[i].left=-1;
   T[i].right=-1;
   T[i].sib=-1;
   }
  for(i=0;i<n;i++){
    scanf("%d",&key);
    scanf("%d",&l);
    scanf("%d",&r);
    T[key].left=l;
    T[key].right=r;
    if(l!=-1 && r==-1){
    T[l].p=key;
       T[l].sib=r;
    }
    else if(l==-1 && r!=-1){
      T[r].p=key;
      T[r].sib=l;
     }
    else if(l!=-1 && r!=-1){
       T[l].p=key;
       T[l].sib=r;
       T[r].p=key;
       T[r].sib=l;
    }

    if(l==-1 && r==-1) T[key].deg=0;
    else if(l==-1 || r==-1) T[key].deg=1;
    else T[key].deg=2;
  }
  for(i=0;i<n;i++){
    if(T[i].p==-1) {
    T[i].dep=0;
    depth(i,T[i].dep);
    }
    if(T[i].left==-1 && T[i].right==-1) {
    T[i].hei=0;
    height(i,T[i].hei);
    }
  }
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,T[i].p,T[i].sib,T[i].deg,T[i].dep,T[i].hei);
    if(T[i].p==-1) printf("root\n");
    else if(T[i].deg==0) printf("leaf\n");
    else printf("internal node\n");
  }
  return 0;
}

void depth(int id,int count){
  T[id].dep=count;
  if(T[id].left==-1 && T[id].right==-1)return;
  else if(T[id].left==-1) depth(T[id].right,T[id].dep+1);
  else if(T[id].right==-1) depth(T[id].left,T[id].dep+1);
  else   { depth(T[id].left,T[id].dep+1);
          depth(T[id].right,T[id].dep+1);
   }
}

void height(int id,int count){
  if(T[id].hei<=count){
  T[id].hei=count;
  }
  if(T[id].p==-1) return;
  else {
       height(T[id].p,T[id].hei+1);
   }
}

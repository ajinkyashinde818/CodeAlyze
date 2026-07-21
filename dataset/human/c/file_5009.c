#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
  int p;
  int r;
  int l;
  int s;
} Node;
int hfunc(Node *,int,int);

int main(){
  int n,i,j,degree,num,point,c1,c2,temp,a,depth=0,sum=0,height;
 
  Node T[25];
  for(i=0;i<25;i++){
    T[i].p=T[i].r=T[i].l=T[i].s=-1;
  }
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d%d",&point,&c1,&c2);
    if(c1!=-1)sum++;
    if(c2!=-1)sum++;
    T[point].l=c1;
    T[point].r=c2;
    if(c1!=-1){
    T[c1].s=c2;
    T[c1].p=point;
    }
    if(c2!=-1){
    T[c2].s=c1;
    T[c2].p=point;
    }
  
  }
    
    

  
  for(i=0;i<=sum;i++){
    depth=height=degree=0;
    j=i;
    while(T[j].p!=-1){
      depth++;
      j=T[j].p;
    }
    j=i;
    height=hfunc(T,i,0);

    
     if(T[i].l!=-1)
       degree++;
     
     if(T[i].r!=-1)
	  degree++;
    
     
     
   
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,T[i].p,T[i].s,degree,depth,height);
    if(T[i].p==-1) printf("root");
    else if(T[i].l==-1&&T[i].r==-1)printf("leaf"); 
  else printf("internal node");
   
    printf("\n");
  }
  return 0;
}
int hfunc(Node T[],int i,int height){
  int lh=0,rh=0;
  if(T[i].l==-1 &&T[i].r==-1)
    return height;
  if(T[i].l!=-1)
    lh=hfunc(T,T[i].l,height+1);
  if(T[i].r!=-1)
    rh=hfunc(T,T[i].r,height+1);
  if(lh>rh)
    return lh;
  else
    return rh;
}

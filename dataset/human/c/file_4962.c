#include<stdio.h>

#define MAX 100000

typedef struct{
  int p;
  int l_child;
  int r_child;
} node;

int depth[MAX], height[MAX];
node T[MAX];

void getDepth(int,int);

int main(){
  int c,i,n,r,p,id,left,right,sib,deg;
    
  scanf("%d",&n);

  for(i=0;i<n;i++) T[i].p=T[i].l_child=T[i].r_child=-1;

  for(i=0;i<n;i++){
    scanf("%d%d%d",&id,&left,&right);
    T[id].l_child=left;
    T[id].r_child=right;
    if(left!=-1) T[left].p=id;
    if(right!=-1) T[right].p=id;
  }

  for(i=0;i<n;i++){
    if(T[i].p==-1)r=i;
    if(T[i].l_child==-1 && T[i].r_child==-1){ 
      height[i]=0;
      p=T[i].p;
      c=1;
      while(1){
	if(p==-1)break;
	if(height[p]<c) height[p]=c;
	c++;
	p=T[p].p;
      }
    }
  }

  getDepth(r,0);

  

  for(i=0;i<n;i++){
    p=T[i].p;
    if(p==-1) sib=-1;
    else{
      if(T[p].l_child==i) sib=T[p].r_child;
      else sib=T[p].l_child;
    }

    deg=0;
    if(T[i].l_child!=-1) deg++;
    if(T[i].r_child!=-1) deg++;
    
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,T[i].p,sib,deg,depth[i],height[i]);

    if(T[i].p==-1) printf("root\n");

    else if(T[i].l_child==-1 && T[i].r_child==-1) printf("leaf\n");
      
    else printf("internal node\n");
  }

  return 0;
}

void getDepth(int u,int p){
  int right,left;
  depth[u]=p;
  if(T[u].r_child!=-1) getDepth(T[u].r_child,p+1);
  if(T[u].l_child!=-1) getDepth(T[u].l_child,p+1);
}

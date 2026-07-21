#include<stdio.h>
#define nil -1

typedef struct{
  int p;
  int left;
  int right;
  int sibling;
  int depth;
  int height;
  int degree;
  
}Node;
Node N[100000];

void CalcDepth(int,int);

int main(){

  int i,j,n,c,left,right,degree,tmp,root;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    N[i].p=N[i].left=N[i].right=N[i].sibling=nil;
    N[i].depth=N[i].height=N[i].degree=0;
  }
  
  for(i=0;i<n;i++){
    scanf("%d %d %d",&tmp,&left,&right);
    N[tmp].left=left;
    N[tmp].right=right;
    if(left!=-1&&right!=-1){
      N[right].p=tmp;
      N[right].sibling=left;
      N[left].sibling=right;
      N[left].p=tmp;
      N[tmp].degree=2;
    }
    else if(left!=-1&&right==-1){
      N[left].p=tmp;
      N[tmp].degree=1;
    }
    else if(left==-1&&right!=-1){
      N[right].p=tmp;
      N[tmp].degree=1;
    }
  }

  for(i=0;i<n;i++)if(N[i].p==nil)root=i;
  CalcDepth(n,root);
 
  for(i=0;i<n;i++){
   printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, "
	  ,i,N[i].p,N[i].sibling,N[i].degree,N[i].depth,N[i].height);
   if(N[i].p==nil)printf("root\n");
   else if(N[i].left==nil&&N[i].right==nil)printf("leaf\n");
   else printf("internal node\n");
 }
  return 0;
}


void CalcDepth(int n ,int p){

 int i,j,k,d,h;

  for(i=0;i<n;i++){
    if(i==p)N[i].depth=0;
    else if(N[i].depth==0) {
      for(j=N[i].p,d=1;j!=p;j=N[j].p){
	d++;
      }
      N[i].depth=N[N[i].sibling].depth=d;
      if(N[i].left==nil&&N[i].right==nil){
	h=0;
	j=i;
	while(1){
	  j=N[j].p;
	  h++;
	  if(N[j].height<=h)N[j].height=h;
	  if(j==p) break;
	}
      }
      }
    }
  }

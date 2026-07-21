#include<stdio.h>
typedef struct{
  int son[2];//子
  int reach;
  int parent;
  int sibling;
  int degree;
  int height;
}node;

node B[100];
int n,x;

int parent(int num){//parent input
  int i,j,r=-1;
  for(i=0;i<n;i++){
    for(j=0;j<2;j++){
      if(num==B[i].son[j]){
	r=i;
	return r;
      }
    }
  }
  return r;
}

int reach(int num){//reach input
  int i,r=0;
  for(i=0;i<n;i++){
    if(B[num].parent==-1)return r;
    else {
      num=B[num].parent;
      r++;
    }
  }
}

int sibling(int num){//sibling input
  int i,j,r=-1;
  for(i=0;i<n;i++){
    if(i!=num){
      if(B[num].parent==B[i].parent){
	r=i;
	return r;
      }
    }
  }
  return r;
}
/////////////////////////////////////////////////////////////////////////////
int height(int num,int r,int parent){//height input

  int i,j,deep=0;
  for(i=0;i<n;i++){
    if(deep<B[i].reach){
      for(j=B[i].parent;;j=B[j].parent){
	if(j==num){
	  deep=B[i].reach;
	  break;
	}
	if(B[j].parent==-1)break;
      }
    }
  }
  return deep;
}
///////////////////////////////////////////////////////////////////////////
int main(){
  int i,j,k,a,count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    B[i].parent=-1;
  }
  for(i=0;i<n;i++){
    scanf("%d",&a);
    for(j=0;j<2;j++){
      scanf("%d",&k);
      B[a].son[j]=k;
      B[k].parent=a;
      if(k!=-1)count++;    
    }
    B[a].degree=count;
    count=0;
  }
  /* 
  for(i=0;i<n;i++){
    B[i].parent=parent(i);
  }
  */
  for(i=0;i<n;i++){
    B[i].reach=reach(i);
  }
  
  for(i=0;i<n;i++){
    B[i].sibling=sibling(i);
  }
  
  for(i=0;i<n;i++){
    if(B[i].son[0]==-1&&B[i].son[1]==-1)B[i].height=0;
    else B[i].height=height(i,0,B[i].parent)-B[i].reach;
  }
 
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,B[i].parent,B[i].sibling,B[i].degree,B[i].reach,B[i].height);
    if(B[i].parent==-1)printf("root\n");
    else if(B[i].son[0]==-1&&B[i].son[1]==-1)printf("leaf\n");
    else printf("internal node\n");
  }
  return 0;
}

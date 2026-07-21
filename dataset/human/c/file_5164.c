#include <stdio.h>
#include <string.h>
#define N 100000
int height(int);
struct Node{
  int parent;
  int left;
  int right;
};
struct Node T[N];
int H[N];
int main(){
  
  int n,j,p,i,d,s,t,a,id,b,k,l,r,re,re1,sum,ty,MAX=0;
  
  scanf("%d",&n);
  
  

  for(i=0;i<n;i++){
    T[i].right=T[i].left=T[i].parent=-1;
  }
  
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d%d",&l,&r);
    T[id].left=l;
    T[l].parent=id;
    T[id].right=r;
    T[r].parent=id;
    
  }

  for(i=0;i<n;i++){
    if(T[i].parent==-1)
      ty=i;
  
  }
  
  height(ty);
  
  for(i=0;i<n;i++){
    if(T[i].parent==-1){
      printf("node %d: parent = -1, sibling = -1, degree = ",i);
      if(T[i].left!=-1&&T[i].right!=-1)
	printf("2, ");
      else if(T[i].left!=-1&&T[i].right==-1)
	printf("1, ");
      else if(T[i].left==-1&&T[i].right!=-1)
	printf("1, ");
      else printf("0, ");

      printf("depth = 0, height = ");

     
 
      printf("%d, root\n",H[i]);
    }
    
    else if(H[i]==0){
      s=0;
      b=T[i].parent;
      printf("node %d: parent = %d, sibling = ",i,T[i].parent);
      if(i==T[b].right)
	printf("%d, ",T[b].left);
      else printf("%d, ",T[b].right);

      printf("degree = ");
      if(T[i].left!=-1&&T[i].right!=-1)
	printf("2, ");
      else if(T[i].left!=-1&&T[i].right==-1)
	printf("1, ");
      else if(T[i].left==-1&&T[i].right!=-1)
	printf("1, ");
      else printf("0, ");
      printf("depth = ");
	
      a=T[i].parent;
      while(a!=-1){
	s++;
	a=T[a].parent;
      }
      printf("%d, height = ",s);
      
      
      printf("%d, leaf\n",H[i]);
    }
    
    else{
      s=0;
      b=T[i].parent;
      
      printf("node %d: parent = %d, sibling = ",i,T[i].parent);
      if(i==T[b].right)
	printf("%d, ",T[b].left);
      else printf("%d, ",T[b].right);
      printf("degree = ");
      if(T[i].left!=-1&&T[i].right!=-1)
	printf("2, ");
      else if(T[i].left!=-1&&T[i].right==-1)
	printf("1, ");
      else if(T[i].left==-1&&T[i].right!=-1)
	printf("1, ");
      else printf("0, ");
      printf("depth = ");
	
      a=T[i].parent;
      while(a!=-1){
	s++;
	a=T[a].parent;
      }
      
      printf("%d, height = ",s);
      

      printf("%d, internal node\n",H[i]);
    }
  }
  return 0;
}

int height(int pp){
  int a=0,b=0;

  if(T[pp].right!=-1)
    a=height(T[pp].right)+1;
  if(T[pp].left!=-1)
    b=height(T[pp].left)+1;
  if(a>b)
    H[pp]=a;
  else
    H[pp]=b;

  return H[pp];
}

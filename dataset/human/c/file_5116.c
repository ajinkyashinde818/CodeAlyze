#include <stdio.h>
#define MAX 100000
#define N 2
typedef struct node{
  int pare;
  int left;
  int right;
  int sib;
  int deg;
  int hei;
}Node;

Node a[MAX];
int depth[MAX];
void searchdep(int,int);
int searchhei(int);
int main(){
  int n,i,j,num,tmp,count;
  scanf("%d",&n);
  
  for(i = 0;i<n ;i++){
    a[i].left = -1;
    a[i].right =-1;
    a[i].pare = -1;
    a[i].sib = -1;
    a[i].hei = 0;
  }

  for(i = 0 ;i<n ;i++){
    scanf("%d",&num);
    count=0;
    for(j = 0;j<N;j++){
      scanf("%d",&tmp);
      if(tmp ==-1){
	continue;
      }
      if(j ==0) {
	a[num].left = tmp;
	count++;
	if(a[num].left !=-1){
	  a[a[num].left].sib = a[num].right;
	}
	if(a[num].right!=-1){
	  a[a[num].right].sib = a[num].left;
	}
      }
      else {
	a[num].right= tmp;
	count++;
	if(a[num].left !=-1){
	  a[a[num].left].sib = a[num].right;
	}
	if(a[num].right!=-1){
	  a[a[num].right].sib = a[num].left;
	}
      }
      if( tmp !=-1){
	a[tmp].pare =num;
      }
      a[num].deg = count;
    }
  }
  for(i = 0;i<n;i++){
    if(a[i].pare ==-1)
      searchdep(i,0);
  }
  for(i = 0 ;i<n;i++){
    a[i].hei = searchhei(i);
  }

 
  for(i = 0 ;i<n;i++){
    if(a[i].pare ==-1){
      printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, root\n",i,a[i].pare,a[i].sib,a[i].deg,depth[i],a[i].hei);
    }
    else if(a[i].right ==-1 && a[i].left==-1){
      printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, leaf\n",i,a[i].pare,a[i].sib,a[i].deg,depth[i],a[i].hei);
    }
    else if(a[i].right !=-1 ||  a[i].left!=-1){
      printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, internal node\n",i,a[i].pare,a[i].sib,a[i].deg,depth[i],a[i].hei);
    }
  }
  return 0;
}

void searchdep(int b,int c){
  depth[b] = c;
  if(a[b].left != -1){
    searchdep(a[b].left,c+1);
  }
  if(a[b].right !=-1){
    searchdep(a[b].right ,c+1);
  }
}

int searchhei(int d){
  int b=0,c=0;
  if(a[d].left ==-1 && a[d].right ==-1){
    return 0;
}
  if(a[d].right!=-1){
  b = searchhei(a[d].right);
  }
  if(a[d].left !=-1){
  c = searchhei(a[d].left);
  }
  if(b>=c){
    return b+1;
  }
  else{ return c+1;}
}

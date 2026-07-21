#include<stdio.h>
#define MAX 100000
typedef struct{
  int parent,left,right;
}Node;

Node T[MAX];
int n,dep[MAX];

void print(int value){
  int i,j;
  printf("node %d: parent = %d, depth = %d, ",value,T[value].parent,dep[value]);

  if(T[value].parent==-1)printf("root, ");
  else if(T[value].left==-1)printf("leaf, ");
  else printf("internal node, ");

  printf("[");
  for(i=0,j=T[value].left;j!=-1;i++,j=T[j].right){
    if(i>0)printf(", ");
    printf("%d",j);
  }
  printf("]\n");
}

void setdep(int value,int p){
  dep[value]=p;
  if(T[value].right!=-1)setdep(T[value].right,p);
  if(T[value].left!=-1)setdep(T[value].left,p+1);
}
int main(){
  int i,j,id,k,c,left,right;
  scanf("%d",&n);
  for(i=0;i<n;i++)T[i].parent=T[i].left=T[i].right=-1;
  for(i=0l;i<n;i++){
    scanf("%d%d",&id,&k);
      for(j=0;j<k;j++){
	scanf("%d",&c);
	if(j==0)T[id].left=c;
	else T[left].right=c;
	left=c;
	T[c].parent=id;
      }
  }
  for(i=0;i<n;i++){
    if(T[i].parent==-1)right=i;
  }
  setdep(right,0);
  for(i=0;i<n;i++)print(i);
  return 0;
}

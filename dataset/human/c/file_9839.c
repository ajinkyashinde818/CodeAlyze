#include<stdio.h>

#define N 100000
 
typedef struct{
  int de;
  int pa;
  int ll;
  int sib;
}node;
  
node A[100000];
int n;
 
int depth(int now){
  int dep = 0; 
  while(1){
    if(A[now].pa == -1)return dep;
    else {
      now=A[now].pa;
      dep++;
    }
  }
}
 
void init(){
  int i;
  for(i=0;i<n;i++){
    A[i].pa=-1;
    A[i].ll=-1;
    A[i].sib=-1;
  }
  return;
}
 
int main(int argc,char *argv[]){
  int i,j,now,leaf,k;
   
  scanf("%d",&n);
  init();
  for(i=0;i<n;i++){
    scanf("%d",&now);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&leaf);
      if(j==0){
    A[now].ll=leaf;
    A[leaf].pa=now;
      }
      else {
    A[now].sib=leaf;
    A[leaf].pa=A[now].pa;
      }  
      now=leaf;
    }
  }
  for(i=0;i<n;i++){
    A[i].de=depth(i);
  }
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, depth = %d, ",i,A[i].pa,A[i].de);
    if(A[i].pa==-1)printf("root, ");
    else if(A[i].ll==-1)printf("leaf, ");
    else printf("internal node, ");
    printf("[");
    for(j=A[i].ll;j!=-1;j=A[j].sib){
      if(j==A[i].ll)printf("%d",j);
      else printf(", %d",j);
    }
    printf("]\n");
  }
  return 0;
}

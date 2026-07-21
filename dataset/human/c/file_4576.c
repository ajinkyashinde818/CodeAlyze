#include<stdio.h>
#define MAX 25

typedef struct node{
  int p;
  int left;
  int right;
  int sib;
  int deg;
}Node;

int Depth[MAX];
int Height[MAX];
Node node[MAX];

void depth(int x, int y){
  Depth[x]=y;
  if(node[x].left!=-1)depth(node[x].left,y+1);
  if(node[x].right!=-1)depth(node[x].right,y+1);
}

int height(int x, int y){
  int i=0;
  int j=0;

  if(node[x].left==-1 && node[x].right==-1)return 0;
  if(node[x].left!=-1)i=height(node[x].left,y+1);
  if(node[x].right!=-1)j=height(node[x].right,y+1);

  if(i>=j)return i+1;
  else return j+1;


}

int main(){
  int n;
  int i,j;
  int id;
  int a;

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    node[i].p=-1;
    node[i].left=-1;
    node[i].right=-1;
    node[i].sib=-1;
    node[i].deg=0;
  }

  for(i=0;i<n;i++){
    scanf("%d",&id);

    for(j=0;j<2;j++){
      scanf("%d",&a);
      if(j==0){
	if(a!=-1){
	  node[id].left=a;
	  node[id].deg++;
	}
      }

      else {
	if(a!=-1){
	  node[id].right=a;
	  node[id].deg++;
	}
	if(node[id].left!=-1)node[node[id].left].sib=node[id].right;
	if(node[id].right!=-1)node[node[id].right].sib=node[id].left;

    }

    if(a!=-1)node[a].p=id;
  }

  }



  for(i=0;i<n;i++){
    if(node[i].p==-1)depth(i,0);
    Height[i]=height(i,0);
  }


  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,node[i].p,node[i].sib,node[i].deg,Depth[i],Height[i]);

    if(node[i].right==-1 && node[i].left==-1 && node[i].p!=-1)printf("leaf\n");
    else if(node[i].p==-1)printf("root\n");
    else printf("internal node\n");
  }

  return 0;
}

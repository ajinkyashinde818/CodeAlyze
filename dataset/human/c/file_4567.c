#include<stdio.h>
#include<stdlib.h>


int height[25];

/*child[0]???left???child[1]???right?????????*/
typedef struct Node{
  int jisuu;
  int child[2];
  int parent;
  int sib;
}Node;



int get_dep(Node *node,int soeji){
  int dep=0;
  Node x;
  x=node[soeji];
  while(x.parent!=-1){
    x=node[x.parent];
    dep++;
  }
  return dep;
}


int get_height(Node *node,int soeji){
  if(height[soeji]!=-1) return height[soeji];
  int res=0,ress=0;
  if(node[soeji].child[0]!=-1){
    if(height[node[soeji].child[0]]!=-1) res=1+height[node[soeji].child[0]];
    else res=1+get_height(node,node[soeji].child[0]);
  }
  if(node[soeji].child[1]!=-1){
    if(height[node[soeji].child[1]]!=-1) ress=1+height[node[soeji].child[1]];
    else ress=1+get_height(node,node[soeji].child[1]);
  }
  if(res <ress) height[soeji]=ress;
  else height[soeji]=res;
  return height[soeji];
}

  
  


int main(){
  int n,i,j,bangou;
  scanf("%d",&n);
  for(i=0;i<n;i++) height[i]=-1;
  Node *node;
  node=malloc(n*sizeof(Node));
  for(i=0;i<n;i++) node[i].sib=-1;
  for(i=0;i<n;i++){
    scanf("%d",&bangou);
    node[bangou].parent=-1;
    scanf("%d %d",&(node[bangou].child[0]),&(node[bangou].child[1]));
    node[bangou].jisuu=0;
    if(node[bangou].child[0]!=-1) node[bangou].jisuu++;
    if(node[bangou].child[1]!=-1) node[bangou].jisuu++;
    if(node[bangou].jisuu==2){
      node[node[bangou].child[0]].sib=node[bangou].child[1];
      node[node[bangou].child[1]].sib=node[bangou].child[0];
    }
  }
  int cnt=0;
  for(i=0;i<n;i++){
    for(j=0;j< node[i].jisuu;j++){
        node[node[i].child[j]].parent=i;
        cnt+=1;
    }
    if(node[i].jisuu==1 && node[i].child[0]==-1) node[node[i].child[1]].parent=i;
    if(cnt==n-1) break;
  }
  for(i=0;i<n;i++) get_height(node,i);
  
  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d",i,node[i].parent,node[i].sib,node[i].jisuu,get_dep(node,i),height[i]);
    if(node[i].parent==-1) printf(", root");
    else if(node[i].jisuu==0) printf(", leaf");
    else printf(", internal node");
    printf("\n");
  }
  return 0;
}

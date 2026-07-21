#include<stdio.h>
#define MAX 25
typedef struct node{
  int p;//parents
  int left;
  int right;
  int sib;
  int deg;
}Node;
void depth(int,int);
int height(int,int);
Node node[MAX];//nodeの大きさ
int D[MAX];
int H[MAX];
int main(){
  int n,i,num,j,tmp;
 scanf("%d",&n);//節の入力
  for(i=0;i<n;i++){//初期化
    node[i].p=-1;
    node[i].left=-1;
    node[i].right=-1;
    node[i].sib=-1;
    node[i].deg=0;
  }
  for(i=0;i<n;i++){
    scanf("%d",&num);
    for(j=0;j<2;j++){
      scanf("%d",&tmp);
      if(j==0){
	if(tmp!=-1){
	node[num].left=tmp;
	node[num].deg++;
	}
      }
      else{
	if(tmp!=-1){
	 node[num].right=tmp;
	 node[num].deg++;
	}
	if(node[num].left!=-1){//左側の要素が存在するとき	 
	  node[node[num].left].sib=node[num].right;
	}
	if(node[num].right!=-1){//右側の要素が存在するとき
	  node[node[num].right].sib=node[num].left;
	}

	
      }
      if(tmp!=-1){
      node[tmp].p=num;
      }
    }
    
  }
for(i=0;i<n;i++){
    if(node[i].p==-1){
      
      depth(i,0);
   
     
    }
  H[i]=  height(i,0);
 }

  
   for(i=0;i<n;i++){
     printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,node[i].p,node[i].sib,node[i].deg,D[i],H[i]);
     if(node[i].left==-1 && node[i].right==-1 && node[i].p!=-1){
       printf("leaf\n");
     }
     else if(node[i].p==-1){
       printf("root\n");
     }
     else {
       printf("internal node\n");
     }
     
   }
   return 0;
}
void depth(int u,int p){
  D[u]=p;
   if(node[u].left !=-1){
    depth(node[u].left,p+1);
   
    }
    if(node[u].right!=-1){
    depth(node[u].right,p+1);
   
     }
}
int height(int u, int p){
  int i=0,j=0;
  if(node[u].left==-1 &&node[u].right==-1){//reafの時高さ0
    return 0;
  }
  if(node[u].left!=-1){//左に移動
      i=height(node[u].left,p+1);
    }
  if(node[u].right!=-1){//右に移動
      j= height(node[u].right,p+1);     
    }
  if(i>=j)return i+1;//i+1,j+1を返すことでその時の高さが分かる
    else return j+1;
    
}

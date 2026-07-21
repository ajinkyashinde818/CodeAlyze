#include<stdio.h>

int parent[100001];
int flag[100001];
int sibling[100001];
int degree[100001];
int Left[100001];
int Right[100001];
int depth(int);
int height(int);
int n;
int main()
{
  int i,left,right,id;
  
  scanf("%d",&n);

  for(i=0; i<n; i++){
    parent[i] = -1;
    flag[i] = 1;
    sibling[i] = -1;
    degree[i] = 0;
  }

  for(i=0; i<n; i++){
    scanf("%d%d%d",&id,&left,&right);

    if(left!=-1){
      //Left[id]=left;
      parent[left]=id;
      sibling[left]=right;
      degree[id]++;
     }
    
    if(right!=-1){
      //Right[id]=right;
      parent[right]=id;
      sibling[right]=left;
      degree[id]++;
    }
  }
  
  for(i=0; i<n; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,parent[i],sibling[i],degree[i],depth(i),height(i));
    if(depth(i)==0)
      printf("root\n");
    else if(degree[i]==0)
      printf("leaf\n");

    else printf("internal node\n");
  }
  return 0;
}

int depth(int i){
  if(parent[i] == -1)return 0;
  else return depth(parent[i])+1;
}

int height(int i){
  int j,He,count=0;

  if(degree[i] == 0)return 0;

  else{
    for(j=0; j<n; j++){
      if(parent[j]==i){
	He = height(j)+1;
	if(He>count)count=He;
      }
    }
  }
    return count;
}

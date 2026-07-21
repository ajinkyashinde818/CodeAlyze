#include<stdio.h>

int parent[100001];
int count[100001];
int root[10000][10000];
int flag[100001];
int depth(int);

int main()
{
  int i,n,k,id,c,node;

  scanf("%d",&n);
  
  for(i=0; i<n; i++){
    parent[i] = -1;
    flag[i] = 1;
  }
  
  for(i=0; i<n; i++){
    scanf("%d %d",&id,&k);
    count[id]=k;
    node=0;
    while(k-->=1){
      scanf("%d",&c);
      root[id][node++]=c;
      parent[c]=id;
      flag[id]=0;
    }
  } 
    
    for(i=0; i<n; i++){
      int j,l;
      printf("node %d: parent = %d, depth = %d, ",i,parent[i],depth(i));
      if(flag[i]==1 && depth(i)==0){
	printf("root, []\n");
      }

      else if(flag[i] == 1)
	printf("leaf, []\n");

      else if(depth(i) == 0){
	printf("root, [");
	for(j=0; j<count[i]-1; j++){
	    printf("%d, ",root[i][j]);
	    }
	  printf("%d]\n",root[i][j]);
	  l=j+1;
      }

      else{
	printf("internal node, [");
	for(j=0; j<count[i]-1; j++){
	    printf("%d, ",root[i][j]);
	    }
	  printf("%d]\n",root[i][j]);
      }
    }
    return 0;
}

int depth(int i){
  if(parent[i] == -1)return 0;
  else return depth(parent[i])+1;
}

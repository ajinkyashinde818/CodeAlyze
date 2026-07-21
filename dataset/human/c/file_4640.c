#include <stdio.h>
typedef struct node{
  int p,lc,rc,b;
  
} node;

node tree[100000];

int max(int a,int b){
  if(a>b)return a;
  else return b;
}

int getdepth(int x){
  if(tree[x].p==-1){
    return 0;
  } else{
    return getdepth(tree[x].p)+1;
  }
}

int getheight(int x){
  int ans=0,l=tree[x].lc,r=tree[x].rc;
  if(l!=-1)ans=max(ans,getheight(l)+1);
  if(r!=-1)ans=max(ans,getheight(r)+1);
  return ans;
}

int main(){

 
  int n,d,d2,k,l,id;
  int i,j;

  for(i=0;i<100000;i++){
    tree[i].p=-1;
    tree[i].lc=-1;
    tree[i].rc=-1;
    tree[i].b=-1;
  }
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&id);
    scanf("%d%d",&tree[id].lc,&tree[id].rc);
    tree[tree[id].lc].p=id;
    tree[tree[id].rc].p=id;
    tree[tree[id].lc].b=tree[id].rc;
    tree[tree[id].rc].b=tree[id].lc;
    

  }


  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d,",i,tree[i].p,tree[i].b);
    if(tree[i].lc==-1&&tree[i].rc==-1){
      printf(" degree = 0");
    } else if(tree[i].lc==-1||tree[i].rc==-1){
      printf(" degree = 1");
    } else{
      printf(" degree = 2");
    }
    printf(", depth = %d",getdepth(i));
    printf(", height = %d, ",getheight(i));
    if(tree[i].p==-1){
      printf("root");
    } else if(tree[i].lc==-1&&tree[i].rc==-1){
      printf("leaf");
    } else {
      printf("internal node");
    }
    printf("\n");
  }
  
  return 0;
}

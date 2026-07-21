#include<stdio.h>
#define N 25

struct Tree{
  int id;
  int left,right;
  int p,s;
  int dep,deg;
  int h;
};

int main(){
  int in,n,i,s1,s2;
  int pa,pc,hc,he;

  struct Tree tree[N];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    tree[i].p=-1;
    tree[i].s=-1;
    tree[i].deg=0;
    tree[i].h=0;
  }

  for(i=0;i<n;i++){
    scanf("%d",&in);
    tree[in].id=in;
    scanf("%d %d",&tree[in].left,&tree[in].right);
    if(tree[in].left!=-1&&tree[in].right!=-1){
      tree[in].deg=2;
    }else if(tree[in].left!=-1||tree[in].right!=-1){
      tree[in].deg=1;
    }

    s1=tree[in].left;
    s2=tree[in].right;
    tree[s1].p=tree[in].id;
    tree[s2].p=tree[in].id;
    tree[s1].s=s2;
    tree[s2].s=s1;
  }

  for(i=0;i<n;i++){
    if(tree[i].p==-1){
      tree[i].dep=0;
    }else{
      pa=tree[i].p;
      pc=1;
    
      while(tree[pa].p!=-1){
	pc++;
	pa=tree[pa].p;
      }
      tree[i].dep=pc;
    }
  }



  for(i=0;i<n;i++){
    if(tree[i].deg==0){
      hc=0;
      tree[i].h=hc;
      pa=tree[i].p;

      while(pa!=-1){
	hc++;
	if(tree[pa].h<=hc){
	  tree[pa].h=hc;
	  pa=tree[pa].p;
	}
      }
    }
  }

  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d,",i,tree[i].p,tree[i].s,tree[i].deg,tree[i].dep,tree[i].h);
    if(tree[i].p==-1){
      printf(" root\n");
    }else if(tree[i].left==-1&&tree[i].right==-1){
      printf(" leaf\n");
    }else{
      printf(" internal node\n");
    }
  }

  return 0;
}

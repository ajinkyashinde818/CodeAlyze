#include<stdio.h>
typedef struct{
  int parent;
  int left;
  int right;
} tree;
tree t[10000];

int gh(int);
int main(){
  int a,b,c,e,f,id,m;
  int dp = 0;
  int dg = 0;
  int hei = 0;

    scanf("%d",&a);

  for(b = 0; b < a; b++){
    t[b].parent = -1;
  }

  for(b = 0; b < a; b++){
    scanf("%d%d%d",&id,&e,&f);
    t[id].left = e;
    t[id].right = f;
    if(e != -1 && f != -1){
      t[e].parent = id;
      t[f].parent = id;
    }
    else if(e != -1 && f == -1){
      t[e].parent = id;
    }
    else if(e == -1 && f != -1){
      t[f].parent = id;
    }
  }


  for(b = 0; b < a; b++){
    printf("node %d: parent = %d, ",b,t[b].parent);
    if(t[b].parent == -1){
      printf("sibling = -1, ");
    }
    else if(t[t[b].parent].left == b){
      printf("sibling = %d, ",t[t[b].parent].right);
    }
    else{
      printf("sibling = %d, ",t[t[b].parent].left);
    }
    printf("degree = ");
    if(t[b].left != -1 && t[b].right != -1){
      printf("2, ");
    }
    else if(t[b].left == -1 && t[b].right == -1){
      printf("0, ");
    }
    else{
      printf("1, ");

    }
      m = b;
      while(t[m].parent != -1){
	dp++;
	m = t[m].parent;
      }

      printf("depth = %d, ",dp);
      dp = 0;

      /* if(t[b].left == 0 && t[b].right == 0 && t[b].parent == -1){
	printf(" root, []");
	return 0;
	}*/

      printf("height = ");
      hei = gh(b);
      printf("%d,",hei);


      if(t[b].parent == -1){
	printf(" root\n");
      }
      else if(t[b].left == -1 && t[b].right == -1){
	printf(" leaf\n");
      } 
      else{
	printf(" internal node\n");
      }
    }
    return 0;
  
}
   


int gh(int i){

  int n = 0, m = 0;
  if(t[i].left == -1 && t[i].right == -1){
    return 0;
  }

  if(t[i].left != -1){
    n = gh(t[i].left)+1;
  }
  if(t[i].right != -1){
    m = gh(t[i].right)+1;
  }
  if(n > m){
    return n;
  }
  else{
    return m;
      }
}

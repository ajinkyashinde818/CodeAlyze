# include<stdio.h>
# include<stdlib.h>

typedef struct{
  int parent;
  int right;
  int left;
  int sibling;
  int degree;
}BT;

BT bt[26];
int n;



int CH(int g){
  int a = 0,b = 0;
  if(bt[g].degree == 0)return 0;

  if(bt[g].right != -1) a = CH(bt[g].right)+1;

  if(bt[g].left != -1) b = CH(bt[g].left)+1;

  if(a>b)return a;

  else return b;

  
 }

int main(){
  int i,j,num,depth = 0;
 

  
  scanf("%d",&n);

  for(i=0;i<n;++i){
    bt[i].parent = -1;
    bt[i].sibling = -1;
    bt[i].degree = 0;
  }
  for(i=0;i<n;i++){
    scanf("%d",&num);
    scanf("%d%d",&(bt[num].left),&(bt[num].right));

    if(bt[num].left != -1 &&bt[num].right != -1){
      bt[bt[num].left].parent = num;
      bt[bt[num].right].parent = num;
      bt[bt[num].left].sibling = bt[num].right;
      bt[bt[num].right].sibling = bt[num].left;
      bt[num].degree = 2;
    }
    else if(bt[num].left != -1){
      bt[bt[num].left].parent = num;
      bt[num].degree = 1;
    }
    else if(bt[num].right != -1){
      bt[bt[num].right].parent = num;
      bt[num].degree = 1;
    }
  }

  for(i=0;i<n;i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, "
	   ,i,bt[i].parent,bt[i].sibling,bt[i].degree);

    num = i;
    while(bt[num].parent != -1){
      depth++;
      num = bt[num].parent;
    }
    printf("depth = %d, height = %d, ",depth,CH(i));
    depth = 0;
    
    if(bt[i].parent == -1) printf("root\n");
    else if(bt[i].left == -1 && bt[i].right == -1) printf("leaf\n");
    else printf("internal node\n");
  }
}

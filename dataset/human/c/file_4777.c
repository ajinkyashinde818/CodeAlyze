#include<stdio.h>
#define N 100000
#define ROOT -1

typedef struct{
  int p;
  int left;
  int right;
}node;

node Tree[N];

int num;
/*??±???*/
int Depth(int);
/*??????*/
int Height(int);

/*main??¢??°*/
int main(){

  int i, a, b, id, tmp;
  int dep[N], hei[N], sib[N], deg[N];

  scanf("%d", &num);

  /*?????????*/
  for(i = 0; i < num; i++){
    Tree[i].left = ROOT;
    Tree[i].p =ROOT;
    Tree[i].right = ROOT;
    deg[i] = hei[i] = 0;
    sib[i] = deg[i] = ROOT;
  }

  /*????????????*/
  for(i = 0; i < num; i++){
    scanf("%d %d %d", &id, &a, &b);

    /*??????????????????*/
    if(a == ROOT && b == ROOT){
      deg[id] = 0;
    }
      /*???????????????*/
    else if (a != ROOT && b == ROOT){
      Tree[a].p = id;
      Tree[id].left = a;
      deg[id] = 1;
    }
      /*???????????????*/
    else if(a == ROOT && b != ROOT){
      deg[id] = 1;
      Tree[b].p = id;
      Tree[id].right = b;
    }
    /*??????????????????*/
    else{
      sib[a] = b;
      sib[b] = a;
      deg[id] = 2;
      Tree[a].p = id;
      Tree[b].p = id;
      Tree[id].left = a;
      Tree[id].right = b;

    }
  }


  /*??±?????¨??????????¨????*/
  for(i = 0; i < num; i++){
    dep[i] = Depth(i);
    hei[i] = Height(i);
  }


  /*??¨???*/
  for(i = 0; i < num; i++){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", i, Tree[i].p, sib[i], deg[i], dep[i], hei[i]);


    /*??????????¨????*/
    if(Tree[i].p == ROOT){printf("root\n");}
    else if(Tree[i].left == ROOT && Tree[i].right == ROOT){printf("leaf\n");}
else{printf("internal node\n");}
  }
  return 0;
}


/*??????*/
int Height(int p){
  int i;
  int cnt;
  int max = 0;

  for(i = 0; i < num; i++){
    if(Tree[i].p == p){
      cnt = Height(i) + 1;
      if(cnt > max) max = cnt;
    }
  }
  return max;
}
/*??±???*/

int Depth(int p){
  if(Tree[p].p == ROOT)return 0;
  else return Depth(Tree[p].p)+1;
}

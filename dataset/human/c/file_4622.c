#include<stdio.h>
#define NIL -1

typedef struct{
  int parent,sibling,leftgaki,rightgaki,degree;
}Node;

Node tree[100001];
int count=0,count3=0; //再帰関数、子供表示用
int count2[100001];
int n;
int retdepth(int id){ //再帰で根っこまでの長さを計る
  if (tree[id].parent==NIL){
    return count/2;
  } else {
    count++;
    return retdepth(tree[id].parent);
  }
}

void retheight(int id,int countid,int startdepth,int depth){ //逆に葉っぱまでの長さを返す
  int i,newcountid;
  for (i=1;i<n;i++){
    if (count2[i]==0){
      newcountid=i;
      break;
    }
  }
  //printf("->tree[%d]search. countid=%d, newcountid=%d, left=%d,right=%d.height=%d\n",id,countid,newcountid,tree[id].leftgaki,tree[id].rightgaki,count2[countid]);
  if (tree[id].leftgaki!=NIL && tree[id].rightgaki!=NIL){
    count2[countid]++;
    count2[newcountid]=depth-startdepth+1;
    retheight(tree[id].leftgaki,countid,startdepth,depth+1);
    retheight(tree[id].rightgaki,newcountid,startdepth,depth+1);
  } else if (tree[id].leftgaki!=NIL){
    count2[countid]++;
    retheight(tree[id].leftgaki,countid,startdepth,depth+1);
  } else if (tree[id].rightgaki!=NIL){
    count2[countid]++;
    retheight(tree[id].rightgaki,countid,startdepth,depth+1);
  } else {
    count3=countid;
  }

}

int returnheight(int id,int depth){
  int i,ret=0;
  for (i=0;i<n;i++){
    count2[i]=0;
  }
  retheight(id,0,depth,depth);
  for(i=0;i<count3+1;i++){
    if(ret<count2[i]){
      ret = count2[i];
    }
  }
  return ret;

}


int main(){
  int i,j,nownode,deg,leftgaki,rightgaki;

  scanf("%d",&n);
  for (i=0;i<n;i++){
    tree[i].parent=tree[i].degree=tree[i].sibling=tree[i].leftgaki=tree[i].rightgaki=NIL;
    //NILで初期化を行う
  }

  for (i=0; i<n; i++){
    scanf("%d%d%d",&nownode,&leftgaki,&rightgaki);
    count=0;
    if (leftgaki!=-1){
      tree[leftgaki].parent=nownode;
      tree[leftgaki].sibling=rightgaki;
      tree[nownode].leftgaki=leftgaki;
      count++;
    }
    if (rightgaki!=-1){
      tree[rightgaki].parent=nownode;
      tree[rightgaki].sibling=leftgaki;
      tree[nownode].rightgaki=rightgaki;
      count++;
    }
    tree[nownode].degree=count;
  }

  //---------------------
  //表示部分
  
  for(i=0; i<n; i++){
    count=count3=0;
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,tree[i].parent,tree[i].sibling,tree[i].degree,retdepth(i),returnheight(i,retdepth(i)));
    if(tree[i].parent == NIL){
      printf("root\n");
    } else if(tree[i].leftgaki == NIL && tree[i].rightgaki == NIL){
      printf("leaf\n");
    } else {
      printf("internal node\n");
    }
  }
  
  return 0;
}

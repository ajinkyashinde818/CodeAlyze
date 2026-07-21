/*根付き２分木 T の各節点uについての情報を出力するプログラム*/
#include<stdio.h>

/*マクロ*/
#define NIL -1
#define V 10000

/*グローバル変数*/
int n = 0;

/*構造体（Tree）*/
typedef struct Node{
  int parent;
  int left;
  int right;
  int sibling;
  int height;
  int depth;
  
}node;

 node T[V];

/*プロトタイプ宣言*/
void setHeight(int );
void treePrint(int );



/*main*/
int main(){
  int i, j;//counter
  int id=0, l_child=0, r_child=0, flag=0, u =0;

  //節点を決める
  scanf("%d",&n);

  /*Treeの初期設定*/
  for(i = 0; i < n; i++) {
    T[i].parent = NIL;
    T[i].left = NIL;
    T[i].right = NIL;
    T[i].sibling = NIL;
  }

  //節点の数だけキーボード入力
 for(i = 0; i < n; i++) {

   scanf("%d %d %d",&id,&l_child,&r_child);

   //数が変更されたところに子供を作り、それを親とする。
   if( l_child!= NIL && r_child ==NIL){
     T[id].left = l_child;
     T[l_child].parent = id;
   }

   if(r_child != NIL && l_child == NIL){
    T[id].right = r_child; 
    T[r_child].parent = id;
   }

   if(l_child != NIL && r_child != NIL){
     T[id].left = l_child;//左子供作成
     T[l_child].parent = id;//左子供→親とする
     T[id].right = r_child; //右子供作成
     T[r_child].parent = id;//右子供→親とする
     T[l_child].sibling = r_child;//右と左は兄弟
     T[r_child].sibling = l_child;//左と右は兄弟(互いに認識させる)
   }
 }
 //ここまで


 //depthを作る
 for(i = 0 ;i < n ;i++) {
    u = i;

  while(1)
    {
    if(T[u].parent == NIL)  {
      break;
    }
    
    flag++;
    u = T[u].parent;
    }

    T[i].depth = flag;
    flag = 0;
  }
 //ここまで

  for(i = 0 ;i < n ;i++) {

    treePrint(i);
  }

  return 0;

}
 
/*節点の高さを求める関数*/
void setHeight(int n) {
  int i,j;//counter
  int flag2;//根の高さを格納する変数

  for(i = 0; i < n; i++) {
   
    if(T[i].right == NIL && T[i].left == NIL){
      T[i].height == 0;

      for(j = i, flag2 = 1; j != NIL; flag2++) {

	j = T[j].parent;

	if(T[j].height < flag2) {
	  T[j].height = flag2;
	}
	
      }
    }
  }
 
}



/*結果を出力する関数*/
void treePrint(int i){
  
   printf("node %d: parent = %d, sibling = %d, ",i,T[i].parent,T[i].sibling);

   printf("degree = ");

   if(T[i].right == NIL && T[i].left == NIL) {
     printf("0, ");
   }

   else if(T[i].right == NIL || T[i].left == NIL) {
     printf("1, ");
   }

   else {
     printf("2, ");
   }

   setHeight(n);

   printf("depth = %d, height = %d,",T[i].depth,T[i].height);

   if(T[i].parent == NIL) {
     printf(" root\n");
   }

   else if(T[i].left == NIL && T[i].right == NIL) {
     printf(" leaf\n");
   }

   else {
     printf(" internal node\n");
   }
   
}

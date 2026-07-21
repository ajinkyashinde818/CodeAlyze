#include<stdio.h>
#define MAX 200000

void insert(int, int);
int r_search();
void rec(int, int);
void print();

struct Node{
  int parent;
  int child;
  int sibling;
};

int n;
struct Node Node[MAX];//それぞれのノードは構造体で保存する
int Depth[MAX];//各ノードの深さを配列に格納する

int main(){
  int Node_num, Node_Index;//これから入力するノードの数とノードの番号を記録
  int node, child, root;
  int i, j;
  
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    Node[i].parent = -1;
    Node[i].sibling = -1;
    Node[i].child = -1;//構造体のノードを全て初期化する
  }

  //ノードの中にデータを入れていく
  for(i = 0; i < n; i++){
    scanf("%d %d", &Node_Index, &Node_num);
    insert(Node_Index, Node_num);
  }

  //rootがどこなのかを探索する
  root = r_search();

  //それぞれのノードの深さを配列に記録する
  rec(root, 0);

  //出力していく
  print();
  
  return 0;
}

void insert(int Node_Index, int Node_num){
  int child, node;
  int i, j;

  for(i = 0; i < Node_num; i++){
    scanf("%d", &node);
    
    if(i == 0){
      Node[Node_Index].child = node;
    }else{
      Node[child].sibling = node;
    }
    
    child = node;
    Node[node].parent = Node_Index;
  }
}

int r_search(){
  int i;
  for(i = 0; i < n; i++){
    if(Node[i].parent == -1){
      return i;
    }
  }
  return 0;//ここのelseはあんまり意味がないかも
}

void rec(int node, int depth){
  Depth[node] = depth;
  if(Node[node].sibling != -1){
    //右の兄弟に同じ深さを設定する
    rec(Node[node].sibling, depth);
  }

  if(Node[node].child != -1){
    //一番左の子供に自分の深さ+1を設定する
    rec(Node[node].child, depth + 1);
  }
}

void print(){
  int i, j;
  int child;
  
  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, depth = %d, ", i, Node[i].parent, Depth[i]);
    if(Node[i].parent == -1){
      printf("root, ");
    }else if(Node[i].child == -1){
      printf("leaf, ");
    }else{
      printf("internal node, ");
    }
    
    child = Node[i].child;
    printf("[");
    for(j = 0; child != -1; j++){
      if(j != 0)printf(", ");
      printf("%d",child);
      child = Node[child].sibling;
    }
    printf("]\n");
  }
}

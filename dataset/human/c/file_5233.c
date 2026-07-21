#include<stdio.h>
#define MAX 200000

struct gNode{
  int parent;
  int left;
  int right;
};

void S_Depth(int, int);//深さを調べる
int S_Height(int);//高さを調べる
int S_Sibling(int);//兄弟がいるかどうか調べる
int r_search();//rootを調べる
void print();

int n;
int Depth[MAX];//深さの記録用
int Height[MAX];//高さの記録用
struct gNode Node[MAX];//ノードは配列で記録

int main(){
  int i;
  int id, left, right, root;

  scanf("%d",&n);
  //ここでノードの初期化をする
  for(i = 0; i < n; i++){
    Node[i].parent = -1;
    Node[i].left = -1;
    Node[i].right = -1;
  }

  for(i = 0; i < n; i++){
    scanf("%d%d%d", &id, &left, &right);
    Node[id].left = left;
    Node[id].right = right;

    //親を設定(left,rightが存在するとき、親は必ず存在する)
    if(left != -1) Node[left].parent = id;
    if(right != -1) Node[right].parent = id;
  }

  //rootを調べる
  root = r_search();

  S_Depth(root, 0);
  S_Height(root);

  //出力する〜
  print();

  return 0;
}

int r_search(){
  int i;

  for(i = 0; i < n; i++){
    if(Node[i].parent == -1) return i;
  }

  return 0;
}

void S_Depth(int id, int depth){
    if(id == -1) return;//親の接点が葉の場合

    Depth[id] = depth;
    S_Depth(Node[id].left, depth + 1);
    S_Depth(Node[id].right, depth + 1);
}

int S_Height(int id){
    int h1, h2;

    h1 = h2 = 0;
    if(Node[id].left != -1){
        h1 = S_Height(Node[id].left) + 1;
    }
    if(Node[id].right != -1){
        h2 = S_Height(Node[id].right) + 1;
    }
    return Height[id] = (h1 > h2) ? h1 : h2;
}

int S_Sibling(int id){
    if(Node[id].parent == -1) return -1;//rootの場合
    //自分が右の子どもだった場合
    if(Node[Node[id].parent].right != id && Node[Node[id].parent].right != -1){
        return Node[Node[id].parent].right;
    }
    //自分が左の子どもだった場合
    if(Node[Node[id].parent].left != id && Node[Node[id].parent].left != -1){
        return Node[Node[id].parent].left;
    }

    return -1;//親が一つに子供しか産んでない場合
}

void print() {
    int i;
    int degree;

    for(i = 0; i < n; i++){
        printf("node %d: parent = %d, sibling = %d, ", i, Node[i].parent, S_Sibling(i));//兄弟は関数でサーチ

        //兄弟の数を把握！
        degree = 0;
        if(Node[i].left != -1) degree++;
        if(Node[i].right != -1) degree++;

        printf("degree = %d, depth = %d, height = %d, ", degree, Depth[i], Height[i]);

        if(Node[i].parent == -1){
            printf("root\n");
        }else if(Node[i].left == -1 && Node[i].right == -1){
            printf("leaf\n");
        }else{
            printf("internal node\n");
        }
    }
}

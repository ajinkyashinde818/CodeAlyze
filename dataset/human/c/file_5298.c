#include<stdio.h>
#include<stdlib.h>

#define MAX 100000
#define NIL -1
struct node{int p,l,r;};

struct node T[MAX];
int n,D[MAX],H[MAX];

void setDepth(int,int);
int setHeight(int);
int getSibling(int);
void print(int);

int main(void){
    int i,v,l,r,root=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){//入力する部分の配列のみ初期化する
        T[i].p=NIL;
    }
    for(i=0;i<n;i++){//入力
        scanf("%d %d %d",&v,&l,&r);
        T[v].l=l;
        T[v].r=r;
        if(l!=NIL) T[l].p=v;//左の子供の親を設定
        if(r!=NIL) T[r].p=v;//右の子供の親を設定
    }
    for(i=0;i<n;i++){
        if(T[i].p==NIL) root=i;//根の値(id)を教えてあげる
    }
    setDepth(root,0);//rootnodeからそれぞれのidの深さを設定
    setHeight(root);//それぞれのidの高さを再帰により設定
    for(i=0;i<n;i++){
        print(i);
    }
    return 0;
}
void setDepth(int id,int d){
    if(id==NIL) return;//存在しなかったらreturn
    D[id]=d;
    setDepth(T[id].l,d+1);
    setDepth(T[id].r,d+1);
}
int setHeight(int id){
    int hl=0,hr=0;
    if(T[id].l!=NIL){
        hl=setHeight(T[id].l)+1;
    }
    if(T[id].r!=NIL){
        hr=setHeight(T[id].r)+1;
    }
    if(hl>hr) H[id]=hl;
    else H[id]=hr;
    return H[id];
}
int getSibling(int id){//兄弟を出力用に探す
    if(T[id].p==NIL) return NIL;//id=0のとき親はいない(親はNIL)かつ兄弟もいない
    if(T[T[id].p].l!=id && T[T[id].p].l!=NIL){//idの親の左の子を確認して、id自身ではなくかつNILでなかった場合
        return T[T[id].p].l;//その子はidの兄弟なので返してあげる
    }
    if(T[T[id].p].r!=id && T[T[id].p].r!=NIL){//idの親の右の子を確認して、id自身ではなくかつNILでなかった場合
        return T[T[id].p].r;//その子はidの兄弟なので返してあげる
    }
    return NIL;//条件以外の場合は兄弟がいないのでNILを返す
}
void print(int id){
    int degree=0;
    if(T[id].l!=NIL) degree++;
    if(T[id].r!=NIL) degree++;
    printf("node %d: ",id);
    printf("parent = %d, ",T[id].p);
    printf("sibling = %d, ",getSibling(id));
    printf("degree = %d, ",degree);
    printf("depth = %d, ",D[id]);
    printf("height = %d, ",H[id]);
    if(T[id].p==NIL) printf("root\n");//親がいなかったらroot
    else if(T[id].l==NIL && T[id].r==NIL) printf("leaf\n");//左右どっちも子供がいなかったらleaf
    else printf("internal node\n");
}

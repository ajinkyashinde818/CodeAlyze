#include<stdio.h>

typedef struct{
  int left;
  int right;
  int parent;
}node;

int main(){
  node T[100000];
  int d,n,i,j,k,id,num,c,cnt,p;

  scanf("%d",&n);
 for(i=0;i<n;i++){
   T[i].right = T[i].left = T[i].parent = -1;
 }
  for(i=0;i<n;i++){
    scanf("%d%d",&id,&k);
    
    for(j=0;j<k;j++){
      scanf("%d",&c);
      T[c].parent = id;
      if(j == 0) T[id].left = c;
      else T[p].right = c;
      p = c;
    }
  }
  for(i=0;i<n;i++){
    cnt = 0;
    p = T[i].parent;
    // printf("%d\n",p);
    while(p != -1){
      p = T[p].parent;
  cnt++;
    }
    
      printf("node %d: parent = %d, depth = %d, ",i,T[i].parent,cnt);

      if(T[i].parent == -1)printf("root, [");
      else if(T[i].left == -1)printf("leaf, [");
      else printf("internal node, [");

      p = T[i].left;
      if(p != -1){
	printf("%d",p);
	while(T[p].right != -1){
	  printf(", %d",T[p].right);
	  p = T[p].right;
	}
      }
      
      printf("]\n");
    
  }
    return 0;
  }



/*
根付き木

与えられた根付き木 T
の各節点 u

について、以下の情報を出力するプログラムを作成してください。

    u

の節点番号
u
の親の節点番号
u
の深さ
u
の節点の種類（根、内部節点または葉）
u

    の子のリスト

ここでは、与えられる木は n
個の節点を持ち、それぞれ 0 から n−1

の番号が割り当てられているものとします。
入力

入力の最初の行に、節点の個数 n
が与えられます。続く n

行目に、各節点の情報が次の形式で１行に与えられます。

id
k c1 c2 ... ck

id
は節点の番号、k は次数を表します。c1 c2 ...ck は 1 番目の子の節点番号、... k

番目の子の節点番号を示します。
出力

次の形式で節点の情報を出力してください。節点の情報はその番号が小さい順に出力してください。

node id
: parent = p, depth = d, type, [c1...ck

]

p
は親の番号を示します。ただし、親を持たない場合は -1 とします。d

は節点の深さを示します。

type

は根、内部節点、葉をそれぞれあらわす root、internal node、leaf の文字列のいずれかです。ただし、根が葉や内部節点の条件に該当する場合は root とします。

c1
...ck

は子のリストです。順序木とみなし入力された順に出力してください。カンマ空白区切りに注意してください。出力例にて出力形式を確認してください。
制約

    1≤n≤100,000

節点の深さは 20 を超えない。
任意の２つの節点間には必ず経路が存在する。
*/

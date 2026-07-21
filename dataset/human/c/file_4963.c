#include <stdio.h>
struct tree{
  int id;
  int left;
  int right;
  int p;
  int s;
  int dep;
  int deg;
  int h;
};

int main(){
  int in,n,i,j,si1,si2,pa,pc,hc,he;
  struct tree num[25];

  scanf("%d",&n); //節点の数の入力

//親、兄弟の初期値をー１、次数、高さの初期値を０に設定する
  for(i=0;i<n;i++){
    num[i].p=-1;
    num[i].s=-1;
    num[i].deg=0;
    num[i].h=0;
  }


  //左右の子供の設定
  for(i=0;i<n;i++){
    scanf("%d ",&in);
    num[in].id=in;
    scanf("%d %d",&num[in].left,&num[in].right);
    if(num[in].left!=-1 && num[in].right!=-1) num[in].deg=2;
    else if(num[in].left!=-1 || num[in].right!=-1) num[in].deg=1;

    si1=num[in].left;
    si2=num[in].right;
    num[si1].p=num[in].id;
    num[si2].p=num[in].id;
    num[si1].s=si2;
    num[si2].s=si1;
  }

  //depthを求める
  for(i=0;i<n;i++){
    if(num[i].p==-1)num[i].dep=0;
    
    else {
    pa=num[i].p;
    pc=1;
 
      while(num[pa].p!=-1){
  
      pc++;
      pa=num[pa].p;
      }
    
    num[i].dep=pc;
    }
  }

 

  //heightを求める
  for(i=0;i<n;i++){
    if(num[i].deg==0){
      hc=0;
      num[i].h=hc;
      pa=num[i].p;
      // pa=num[i].p;
      while(pa!=-1){
	hc++;
	if(num[pa].h<=hc) num[pa].h=hc;

	pa=num[pa].p;
      }
    }
  }


  for(i=0;i<n;i++){
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d,",
	 i,num[i].p,num[i].s,num[i].deg,num[i].dep,num[i].h);
  if(num[i].p==-1)printf(" root\n");
  else if(num[i].left==-1 && num[i].right==-1) printf(" leaf\n");
  else  printf(" internal node\n");
  }


  return 0;
}

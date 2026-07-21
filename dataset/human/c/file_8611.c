#include<stdio.h>

int main(){
int N;
int i;
int X[100010]={0};
int k;
scanf("%d\n",&N );//ボタンの個数読み込み
int a[100000];
for (i = 0; i < N; i++) {//a[i]に値を読み込み
    scanf("%d\n",&a[i] );
    a[i]--;
}
k=0;
for (i = 0; i < N; i++) {
  /* code */

  if(X[k]==1){
    printf("%d\n",-1 );
    return 0;
  }
X[k]++;
k=a[k];
  if(k==1){
    break;
  }
}
printf("%d\n",i+1 );


return 0;






}

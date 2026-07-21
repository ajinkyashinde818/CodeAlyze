#include <stdio.h>

int main()
{
 int i,j,n,max,min;

 /*整数ｎを入力*/
 scanf("%d",&n);
 int R[n];

 /*R(t)を入力*/
for(i=0;i<n;i++)
    {
     scanf("%d",&R[i]);
    }   

 /*最大値最小値の初期値入力*/
 min=R[0];
 max=R[1]-min;

for(i=2;i<n;i++){
     /*最大値最小値の更新*/
    if(R[i-1]<min){
        min=R[i-1];
    }
    if(R[i]-min>max){
        max = R[i]-min;
    }
    
}
 /*最大値の表示*/
printf("%d\n",max);
    
    return 0;
}

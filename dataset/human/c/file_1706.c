#include <stdio.h>

int main(void) {
    int num,num_A[21],num_B[21],num_C[20],ans=0,temp,i;
    scanf("%d",&num);
    for (i=0;i<num;i++) {  //Aの要素を代入する
        scanf("%d",&num_A[i]);
    }
    for (i=0;i<num;i++) {  //Bの要素を代入する
        scanf("%d",&num_B[i]);
    }
    for (i=0;i<num-1;i++) {  //Cの要素を代入する
        scanf("%d",&num_C[i]);
    }
    for (i=0;i<num;i++) {
        ans+=num_B[num_A[i]-1];  //i番目の評価を足す
        if (i>0 && num_A[i]-temp==2) {  //連番の料理を食べた時の処理
            ans+=num_C[temp];
        }
        temp=num_A[i]-1;  //料理の番号を記録
    }
    printf("%d\n",ans);
    return 0;
}

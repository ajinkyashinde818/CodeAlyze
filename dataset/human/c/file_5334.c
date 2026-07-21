#include <stdio.h>
void zeros(int* a);
int p(int a,int b);

int main(void)
{
    int n=0,m=0,x=0,price=0,min=1200001,count=1;
    int c[12]={},A[12][12]={},total[12]={};

    scanf("%d %d %d",&n,&m,&x);
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
        for(int j=0;j<m;j++){
            scanf("%d",&A[i][j]);
        }
    }
    for(int i=0;i<p(2,n);i++){
        zeros(total);
        price=0;
        count=1;
        for(int j=0;j<n;j++){
            if((i&count)==count){
                price+=c[j];
                for(int k=0;k<m;k++){
                    total[k]+=A[j][k];
                }
            }
            count*=2;
        }
        for(int l=0;l<m;l++){
            if(total[l]<x) break;
            if(l==(m-1) && min>price){
                min=price;
            }
        }
    }
    if(min==1200001){
        printf("-1");
    } else {
        printf("%d",min);
    }
    return 0;
}

void zeros(int* a){
    for(int i=0;i<12;i++){
        a[i]=0;
    }
}

int p(int a,int b){
    int temp=a;
    for(int i=0;i<b;i++){
        temp*=a;
    }
    return temp;
}

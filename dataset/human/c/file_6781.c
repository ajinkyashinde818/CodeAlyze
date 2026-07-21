#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define NUM 200020
#define MAX 1000000010

int stock[NUM]={0};

//長さlenの丸太が何本とれるか
int available(int len, int n)
{
    int j;
    int r=0;
    for(j=0;j<n;j++)
    {
        r+= ceil((double)stock[j]/(double)len);
    }
    //printf("len:%d ->%d\n",len,r);
    return r;
}

int main() {
    int n = 0,k=0;
    int i, j;
    int x = 0;
    scanf("%d %d", &n,&k);

    for (i = 0; i < n; i++) {
        scanf("%d", &(stock[i]));
    }

    //にぶたん
    int hi,lo,mid;
    hi = MAX;
    lo =0;

    while(hi-1 > lo)
    {
        mid =(hi+lo)/2;
        if(available(mid,n) > k+n){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    if(k==0)
    {
        int max=0;
        for(i=0;i<n;i++)
        {
            if(stock[i]>max)max=stock[i];
        }
        printf("%d",max);
        return 0;
    }
    /*
    else
    {
        int l;
        for(l=lo;l>0;l--)
        {
            if(available(l,n)!=(n+k))break;
        }
        printf("%d",l+1);
        return 0;
    }
     */
    printf("%d",lo+1);
}

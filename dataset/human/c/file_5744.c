int max(int a,int b){
    if(a>b)return a;
    else return b;
}

int min(int a,int b){
    if(a<b)return a;
    else return b;
}

#include<stdio.h>
int main(){
    int r[200000],n,maxv=-2000000000,minv;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&r[i]);

    minv=r[0];
    
    for(int i=1;i<n;i++){
        maxv=max(maxv,r[i]-minv);
        minv=min(minv,r[i]);
    }
    printf("%d\n",maxv);
    return 0;
}

#include<stdio.h>
#include<math.h>

int max(int a,int b){
    if(a <= b) return b;
    else return a;
}

int min(int a,int b){
    if(a <= b) return a;
    else return b;
}

int main(){
    int n,i,minv;
    int maxv = -2147483648;
    int Rt[200000];
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&Rt[i]);
    
    minv = Rt[0];
    
    for(i=1;i<n;i++){
        maxv = max(maxv,Rt[i]-minv);
        minv = min(minv,Rt[i]);
    }
    printf("%d\n",maxv);
}

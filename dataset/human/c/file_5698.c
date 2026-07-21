#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int a[200005],b[200005],c[200005];
int main(){
    int t;
    while( scanf("%d",&t)!=EOF){
        int i;
        for(i=1;i<=t;i++){
            scanf("%d",&a[i]);
        }
        b[0]=1e9+1;
        for(i=1;i<=t;i++){
            if(a[i]<b[i-1]) b[i]=a[i];
            else b[i]=b[i-1];
        }
        c[t+1]=0;
        for(i=t;i>=1;i--){
            if(a[i]>c[i+1]) c[i]=a[i];
            else c[i]=c[i+1];
        }
        int max_num=-1e9-1;
        for(i=1;i<t;i++){
            if(c[i+1]-b[i]>max_num) max_num=c[i+1]-b[i];
        }
        printf("%d\n",max_num);
    }
    return 0;
}

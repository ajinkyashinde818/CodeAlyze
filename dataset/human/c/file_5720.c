#include<stdio.h>

int main(){
    int n,i,min=0,ans=-1000000001;
    int a[200000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(i==0)min=a[i];
        else if(a[i]!=min && ans<a[i]-min)ans=a[i]-min;
        else if(a[i]==min && ans<0)ans=a[i]-min;
        if(min>a[i] && i!=n-1)min=a[i];
    }
    printf("%d\n",ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

void Swap(int *x, int *y);

int main(){
    int n; cin>>n;
    int a[n];   for(int i=0;i<n;i++)cin>>a[i];

    long long int ans=0;
    int minusNum=0;

    for(int i=0;i<n;i++){
        if(a[i]<0){
            minusNum++;
            a[i]*=-1;
        }
    }
    
    int small=a[0];
    for(int i=0;i<n;i++){
        ans+=a[i];
        small=min(small,a[i]);
    }

    if(minusNum %2 !=0)ans-=small*2;


    cout<<ans<<endl;
    return 0;
}


void Swap(int *x,int *y){
    int i=*x;
    *x=*y;
    *y=i;
}

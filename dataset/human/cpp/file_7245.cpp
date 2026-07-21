#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
 
 

int main (){
    long long l[300000] = {0};
    long long ans[300000] = {0};
    int n,k;
    int i; 
    long long temp[300000] = {0};
    long long wa = 0;
    long long min = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&l[i]);
        wa += l[i];
        if(i == 0){
            temp[i] = l[i];
        }else{
            temp[i] = temp[i-1] + l[i];
        }
    }
    
    for(i=0;i<n-1;i++){
        ans[i] = 2*temp[i] - wa;
        if(ans[i] < 0){
            ans[i] *= -1;
        }
    }
    min = ans[0];
    for(i=1;i<n-1;i++){
        if(ans[i] < min){
            min = ans[i];
        }
    }
    /*for(i=0;i<n;i++){
        printf("%lld\n",ans[i]);
    }*/
    printf("%lld\n",min);
    
    return 0;
}

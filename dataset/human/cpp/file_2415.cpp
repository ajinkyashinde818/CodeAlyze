#include<iostream>
#include<cstdint>

using namespace std;

int main(void){
    int n;
    cin>>n;
    bool negativeodd=0;
    int64_t a[n];
    int64_t sum=0,min=1000000000;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]<0){
            negativeodd=!negativeodd;
            a[i]*=-1;
        }
        sum+=a[i];
        if(min>a[i])min=a[i];
    }
    if(negativeodd){
        cout<<(sum-2*min)<<endl;
    }else{
        cout<<sum<<endl;
    }
    return 0;
}

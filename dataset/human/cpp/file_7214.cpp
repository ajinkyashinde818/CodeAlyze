#include<iostream>
using namespace std;
int main(void){
    int n;
    cin>>n;
    int a[200000]={0};
    for(int i(0);i<n;i++){
        cin>>a[i];
    }
    long long araiguma(0);
    for(int i(1);i<n;i++){
        araiguma += a[i];
    }
    long long sunuke(a[0]);
    long long min_diff(abs(araiguma-sunuke));
    long long diff;
    for(int i(1);i<n-1;i++){
        araiguma -= a[i];
        sunuke += a[i];
        diff = abs(araiguma - sunuke);
        if(diff<min_diff)min_diff = diff;
    }
    cout<<min_diff<<endl;
    return 0;
}

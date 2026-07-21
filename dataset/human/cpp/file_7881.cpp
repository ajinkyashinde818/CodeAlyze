#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n, x=0, sum=0, ans;
    cin >> n;
    vector<long long int> vec(n);
    for(int i=0 ; i<n ; i++){
        cin >> vec.at(i);
        sum+=vec.at(i);
    }
    if(sum-2*vec.at(0)>0){
        ans = sum-2*vec.at(0);
    }else{
        ans = 2*vec.at(0)-sum;
    }
    for(int j=0 ; j<n-1 ; j++){
        x+=vec.at(j);
        if(sum-2*x<0){
            if(ans>2*x-sum){
                ans=2*x-sum;
            }
        }else{
            if(ans>sum-2*x){
                ans=sum-2*x;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

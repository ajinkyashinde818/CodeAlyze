#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include<vector>
#include<iomanip>
#include<map>
#include <queue>
#include<cmath>

using namespace std;

void prime(vector<int> &num, int n){
    for(int i=0;i<=n;i++){
        num[i] = 1;
    }
    num[0] = 0;
    num[1] = 0;
    num[2] = 1;

    for(int i=2;i<=sqrt(n);i++){
        if(num[i] == 1){
            for(int j=2;j<=n/i;j++){
                num[i*j] = 0;
            }
        }
    }
}

int main(void){

    int n;
    cin>>n;

    int count = 0;
    long long int sum = 0;
    long long int min = pow(10,10);

    for(int i=0;i<n;i++){
        long long int a;
        cin>>a;
        if(abs(a) < min) min = abs(a);
        sum += abs(a);
        if(a<0) count++;
        //cout<<sum <<" ";
    }

    if(count%2==0) cout<<sum<<endl;
    else cout<<sum-2*min<<endl;
    
    return 0;

}

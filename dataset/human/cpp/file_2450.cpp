#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<vector>

using namespace std;
int N=2e5+10,inf=1e9;

int main(){
	long long N,zero=0,plus=0,minus=0,ans=0,mini=1e9,tmp;
    cin >> N;
    vector<long> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
        if(A[i]==0){
            zero++;
        }else if(A[i]>0){
            plus++;
        }else{
            minus++;
        }
        tmp = abs(A[i]);
        mini = min(mini,tmp);
    }
    //cout << minus << endl;
    for(int i=0;i<N;i++){
        if(A[i]<0){
            ans -= A[i];
        }else{
            ans += A[i];
        }
    }

    if(zero>0){
        cout << ans << endl;
    }else{
        if(minus%2==1){
            //cout << "OK" << endl;
            ans -= mini*2;
        }
         cout << ans << endl;
    }
    return 0;
}

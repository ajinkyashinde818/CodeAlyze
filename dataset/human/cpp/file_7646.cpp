#include<iostream>
using namespace std;

int main(){
    long long N,ai;
    cin >> N;
    long long a[N];
    long long sum, total, ans, tmp;

    total=0;
    for(long long i=0; i<N; i++){
        cin >> a[i];
        total+=a[i];
    }

    sum=0;

    for(long long i=0; i<N-1; i++){
        sum+=a[i];
        tmp= abs(total-2*sum);
        if(i==0){
            ans=tmp;
        }else{
            ans= min(ans,tmp);
        }
        //cout << "i sum total total-sum tmp ans " << i << " " << sum << " " << total << " " << total-sum << " " << tmp << " " << ans << endl; 
    }

    cout << ans << endl;

    return 0;
}

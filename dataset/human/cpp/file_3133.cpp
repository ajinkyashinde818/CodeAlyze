#include<bits/stdc++.h>
using namespace std;

long dp(int N, vector<int> &val){
    return 0;
}

long clever(int N, vector<int> &val){

    int minus_num=0;
    for(int i=0; i < N; i++){
        if(val.at(i) < 0){
            minus_num += 1;
            val.at(i) *= -1;
        }
    }
    if(minus_num%2==0){
        long res = accumulate(val.begin(), val.end(), 0L);
        return res;
    }else{
        long res = accumulate(val.begin(), val.end(), 0L);// - ;
        long dif = *min_element(val.begin(),val.end());
        return res-2*dif;
    }
}

int main(){
    int N;
    cin >> N;
    std::vector<int> value(N);
    for(int i=0; i < N; i++){
        cin >> value.at(i);
    }
    long res;
    // res = dp(N, value);
    res = clever(N, value);

    cout << res << endl;
    return 0;
}

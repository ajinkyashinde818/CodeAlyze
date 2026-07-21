#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> vec(N);
    vector<long long> ruiseki(N);
    vector<long long> araiguma(N-1);
    vector<long long> balance(N-1);




    for(int i=0;i<N;i++){
        cin>>vec[i];
        if(i==0){
            ruiseki[i]=vec[i];
        }else{
            ruiseki[i]=ruiseki[i-1]+vec[i];
        }
    }

    long long max=ruiseki[N-1];

    ruiseki.pop_back();

    for(int i=0;i<ruiseki.size();i++){
        araiguma[i]=max-ruiseki[i];
    }

    for(int i=0;i<N-1;i++){
        balance[i]=abs(araiguma[i]-ruiseki[i]);
    }

    cout<<*min_element(balance.begin(),balance.end())<<endl;

}

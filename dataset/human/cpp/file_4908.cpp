#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

int main(){
    int N,R;//コンテスト参加回数と表示レーティング
    std::cin>>N>>R;
    int x;//内部レーティング
    if (N>=10){
        x = R;
    }
    else{
        x=R+100*(10-N);
    }
    std::cout<<x<<std::endl;
    return 0;
}

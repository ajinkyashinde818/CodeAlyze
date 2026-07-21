#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;
using Pos = std::pair<int, int>;
//cout<<fixed<<std:cout<<fixed<<setprecision(2)<<Max<<endl;
constexpr int mod = 1e9 + 7;

int N,M;
vector<string> A,B;

bool check(int i,int j){
    for(int k=i;k<i+M;++k){
        for(int l=j;l<j+M;++l){
            if(k>=N || l>+N || A[k][l]!=B[k-i][l-j])return false;
        }
    }
    return true;
}

int main() {
    cin>>N>>M;
    A.resize(N);
    B.resize(M);
    for(auto& str:A)
        cin>>str;
    for(auto& str:B)
        cin>>str;

    bool ans=false;
    for(int i=0;i<N-M+1;++i){
        for(int j=0;j<N-M+1;++j){
            if(check(i,j)){
                ans=true;
                break;
            }
        }
    }

    if(ans)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}

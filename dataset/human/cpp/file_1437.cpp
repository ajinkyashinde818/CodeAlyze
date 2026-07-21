#include<iostream>
#include<set>
#include <bitset>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include <cstdio>
#include<algorithm>
#include <sstream>
#include<string>
#include<string.h>
#include <cmath>
#include <iomanip>
#include <string>
#include<list>
#include <limits>
#include <numeric>
#include <type_traits>
#define int long long
#define ll long long
#define mod  1000000007
#define inf 1e17
#define rep(i,j,n) for(int i=j;i<n;i++)
#define P pair<int,int>
#define ps push_back
double pi = 3.141592653589793;
using namespace std;
int z=0;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
//ここから始めよう
signed main(){
    int n;cin>>n;
    vector<int>v;
    int sum=0;int k=0;
    for(int i=1;sum<n;i++){
        sum+=i;
        if(sum==n){
            cout<<"Yes"<<endl;k=i+1;cout<<k<<endl;
        }
        else if(sum>n){
            cout<<"No"<<endl;return 0;
        }
    }
    int used[114514]={};
    int maxi=0;
    rep(i,0,k){
        int count=i;
        cout<<k-1<<" ";
        rep(j,0,count){
            cout<<used[j]+1<<" ";used[j]++;
        }
        int use=0;
        while(count<k-1){
            if(!use)used[i]=maxi;
            use=true;
            count++;cout<<maxi+1<<" ";maxi++;
        }cout<<endl;
    }return 0;
}

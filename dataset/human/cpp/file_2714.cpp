#include<iostream>
#include<cmath>
#include<vector>
#include<bitset>
#include<bitset>
#include<string>
#include<utility>
#include<queue>

using namespace std;
long long int gcd(long long int a,long long int b);
int main(){
    int n;
    cin >> n;
    // vector<long long int> a(n);
    long long int aps;
    // vector<long long int> gcdm(n);
    long long int sum=0;
    pair<int ,long long int> maxminus=make_pair(-1000000001,-1);
    int minusnum=0;
    pair<int ,long long int> minnm= make_pair(1000000001,-1);
    long long int a;
    for(int i=0;i<n;i++){
        cin >> a;
        if(a<0){
            minusnum++;
            sum-=a;
            if(a>maxminus.first)maxminus=make_pair(a,i);
        }else{
            sum+=a;
            if(a<minnm.first)minnm=make_pair(a,i);
        }
    }
    
    if(minusnum&1){
        if(minusnum==n){
            sum += 2*(maxminus.first);
        }else if(minnm.first+maxminus.first>0)sum += 2*(maxminus.first);
        else if(minnm.first+maxminus.first<=0)sum -= 2*(minnm.first);
    }
    cout << sum << endl;
    return 0;
}
long long int gcd(long long int a,long long int b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    else return gcd(b,a%b);
}

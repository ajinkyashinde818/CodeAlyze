#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

long long MOD = 1000000007;

int main(){
    int N;
    cin >> N;
    vector<long long> A(N,0);
    long long sum_=0;
    for(int i=0; i<N; i++){
        long long a;
        cin >> a;
        A[i]=a;
        sum_+=a;
    }
    sort(A.begin(),A.end());

    for(int i=0; i+1<N; i+=2){
        long long tmp=sum_-2*A[i]-2*A[i+1];
        if(tmp>sum_){
            sum_=tmp;
        }else{
            break;
        }
    }
    cout << sum_ << endl;

}

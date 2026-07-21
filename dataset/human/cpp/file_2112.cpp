#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int COUNT(vector<long long>A){
    int count=0;
    sort(A.begin(), A.end());
    for(int i=0; A[i]<0; i++){
        count++;
    }
    return count;
}


int main(){
    int N; cin >> N;
    vector<long long>A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    long long min=1000000000;
    long long res=0;
    int count = COUNT(A);
    for(int i=0; i<N; i++){
            res += abs(A[i]);
            min = (abs(A[i])<min?abs(A[i]):min);
    }
    
    if(count%2!=0){
        res-=2*min;
    }
    
    cout << res << endl;

    
}

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <regex>
#include <map>
#include <set>
using namespace std;
int main(){
    int N;
    cin >> N;
    
    int A[100000] = {};
    int a[100000] = {};
    int Count = 0;
    for(int i=0;i<N;i++){
        cin >> A[i];
        a[i] = abs(A[i]);
        if(A[i]<=0){
            Count++;
        }
    }
    
    long long ans = 0;
    
    
    if(Count%2==0){
        for(int i=0;i<N;i++){
            ans = ans+a[i];
        }
        }else{
            sort(a,a+N);
            for(int i=1;i<N;i++){
                ans = ans + a[i];
        }
            ans = ans - a[0];
    }
    
    cout << ans << endl;
    return 0;
}

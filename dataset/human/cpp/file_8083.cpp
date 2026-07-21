#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int N;
    cin >> N;
    long int a[N];
    long long int ans = 0;
    for(int i = 0;i<N;i++){
        cin >> a[i];
        ans += a[i];
    }
    
    long long int temp = 0,A;


    for(int i = 0;i<N-1;i++){
        //ans -= a[i];
        temp += a[i];
        
        A = min(A,abs(ans-temp*2));
    }


    cout << A << endl;


    return 0;
}

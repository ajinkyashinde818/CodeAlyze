#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <map>
using namespace std;
int main(void){
    int n;
    cin >> n;
    int num = 0;
    long int dis = LONG_MAX;
    long int sum = 0;
    for(int i=0; i<n; i++){
        long int a;
        cin >> a;
        sum += labs(a);
        if(a < 0){
            num++;
        }
        if(labs(a) < dis){
            dis = labs(a);
        }
    }
    
    long int ans;
    if(num%2 == 0){
        ans = sum;
    }else{
        ans = sum - 2*dis;
    }
    cout << ans << endl;
}

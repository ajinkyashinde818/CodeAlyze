#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    cin >> n;
    
    long long sum[200000] = {0};
    int i;
    for(i = 0; i < n; i++){
        cin >> sum[i];
        if(i != 0){
            sum[i] += sum[i - 1];
        }
    }
    
    long long end = sum[n - 1];
    
    sort(sum + 1, sum + n - 1);
    i = 1;
    while(sum[i] < end / 2 && i <= n - 2){
        i++;
    }
    
    if(i == n - 1){
        cout << abs(end - 2 * sum[n - 2]) << endl;
        return 0;
    }
    
    if(i >= 2 && abs(end - 2 * sum[i]) <= abs(end - 2 * sum[i - 1])){
        cout << abs(end - 2 * sum[i]) << endl;
    }else{
        cout << abs(end - 2 * sum[i - 1]) << endl;
    }
    
    return 0;
}

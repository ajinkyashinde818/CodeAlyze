#include <iostream>
using namespace std;

int main(void)
{
    int i;
    int n;
    long long sum;
    long long temp;
    long long ans;
    long long kotae;
    cin >> n;
    long long a[n];
    for(i = 0; i < n; i++){
        cin >> a[i];
    }
    sum = 0;

    for(i = 0; i < n; i++){
        sum = sum +a[i];
    }

    kotae = 2*a[0] - sum;
    if(kotae < 0){
        kotae = kotae * -1;
    }

    temp = a[0];
    for(i = 1; i < n-1; i++){
        ans = 0;
        temp = temp + a[i];
        ans = 2*temp - sum;
        //絶対値処理
        if(ans < 0){
            ans = ans * -1;
        }
        if(ans < kotae){
            kotae = ans;
        }
        if(kotae == 0){
            break;
        }
        
    }

    cout << kotae << endl;

    return 0;
}

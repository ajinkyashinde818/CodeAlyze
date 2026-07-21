#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    long ans = 0;
    int min = 2000000000;
    int count = 0;
    for(int i=0;i<n;i++){
        if(a[i] < 0){
            count++;
            ans += (-a[i]);
            if(min > (-a[i])){
                min = (-a[i]);
            }
        }
        else{
            ans += a[i];
            if(min > a[i]){
                min = a[i];
            }
        }
    }
    if(count%2 == 0){
        cout << ans << endl;
    }
    else{
        ans = ans - 2*min;
        cout << ans << endl;
    }
}

#include<iostream>

using namespace std;

long int abs_(long int x){
    if (x > 0) {
        return x;
    }else{
        return -x;
    }
    
}

int main(){
    int n;
    cin >> n;
    long int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    bool flag0 = false;
    int mcount = 0;
    long int sm = 0;
    long int mn = 1000000001;
    for(int i = 0; i < n; i++){
        if (a[i] == 0) {
            flag0 = true;
        }
        if (a[i] < 0) {
            mcount++;
        }
        if (abs_(a[i]) < mn) {
            mn = abs_(a[i]);
        }
        sm += abs_(a[i]);
    }
    // cout << mn << '\n';
    // cout << sm << '\n';
    // cout << mcount << '\n';
    if (flag0) {
        cout << sm << '\n';
    }else if (mcount % 2 == 0) {
        cout << sm << '\n';
    }else if (mcount % 2 == 1) {
        cout << sm - 2 * mn << "\n";
    }
    
    
    
}

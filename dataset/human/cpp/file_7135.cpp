#include<iostream>
#include<vector>
using namespace std;

long n, x, y, _min, sum = 0;

int main(){
    cin >> n;
    vector<int> a(n,0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum = sum + a[i];
    }
    x = 0;
    y = sum;
    for(int j = 0; j < n - 1; j++){
        x = x + a[j];
        y = y - a[j];
        if(j == 0){
            _min = abs(x - y);
        }
        if(_min > abs(x - y)){
            _min = abs(x - y);
        }
    }
    cout << _min << endl;
}

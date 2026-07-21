#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <long> a(n);
    vector <long> add(n);
    long min;
    long total;
    cin >> a[0];
    add[0] = a[0];
    for(int i = 1 ; i < n ; i++){
        cin >> a[i];
        add[i] = add[i-1] + a[i];
    }
    min = abs(add[0] - (add[n-1] - add[0]));
    for(int i = 1 ; i < n-1 ; i++){
        total = abs(add[i] - (add[n-1] - add[i]));
        if(min > total){
            min = total;
        }
    }

    cout << min << endl;
    return 0;
}

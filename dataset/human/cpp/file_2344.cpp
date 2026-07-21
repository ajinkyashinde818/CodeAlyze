#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int n;
    cin >> n;

    int a[n];
    int minus_count = 0;
    for(int i=0; i<n; i++){
        int new_num;
        cin >> new_num;
        if(new_num < 0){
            minus_count ++;
            new_num = - new_num;
        }

        a[i] = new_num;
    }
    sort(a, a+n);

    long long int res = 0;

    if(minus_count % 2 == 0){

        for(int i=0; i<n; i++){
            res = res + (long long int)a[i];
        }
    }else{
        for(int i=1; i<n; i++){
            res = res + (long long int)a[i];
        }
        res = res - a[0];
    }

    cout << res << endl;


    return 0;
}

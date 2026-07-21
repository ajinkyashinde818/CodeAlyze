#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
    int r , g , b, n ;
    cin >> r >> g >> b >> n ;
    
    int ans =  0 ;
    for(int i = 0 ; i < 3001 ; i++){
        for(int j = 0 ; j < 3001 ; j ++ ){
           if((n - r *i - g * j) % b == 0 &&(n - r *i - g * j) >= 0 ){
               ans ++ ;
           }
        }
    }

    cout << ans << endl;
    return 0;
}

#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int r;
    int g;
    int b;
    cin >> r >> g >> b >> n;
    int res = 0;
    for (int i = 0; i < n/r+1; i++){
        for(int j = 0; j < (n-(i*r))/g+1; j++){
            if((n-(r*i)-(g*j))%b == 0){
                res++;
            }                     
        }
    }
    cout << res;
}
    // for (int i = 0; i < ; i++){
        
    // }

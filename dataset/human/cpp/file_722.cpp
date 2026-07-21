#include <bits/stdc++.h>
using namespace std;


int main(){


    long long r, g, b, n, i, j;

    long long k = 0;

 
    cin >> r >> g >> b >> n;


    for( i = 0 ; i * r < n + 1 ; i = i + 1 ){

         for( j = 0 ; i * r + j * g < n + 1 ; j = j + 1 ){

              if( ( n - i * r - j * g ) % b == 0 ) k += 1;

              }

         }


    cout << k << endl;


    return 0;


    }

//#include <bits/stdc++.h>

#include <iostream>
//#include <cmath>
//#include <vector>

using namespace std;

int main(){
    int R, G, B, N;
    int sum, count;
    count = 0;
    cin >> R >> G >> B >> N;
    for(int i = 0; i< N/R+1; i++){
        for(int j = 0; j< (N-R*i)/G+1; j++){
            if((N - R * i - G * j) % B == 0){
                
                count++;
                continue;
            }
        }
    }
    cout << count << endl;
    return 0;

}

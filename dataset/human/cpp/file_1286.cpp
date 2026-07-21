#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <math.h>

using namespace std;



int main(){
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int count=0;
    int t=n/r+1;
    
    for (int i=0;i<t;i++){// 赤の個数
        for (int j=0;;j++){// 緑の個数
            int a=n-r*i-g*j;
            if (a<0) break;
            if (a%b==0) count++;
        }
    }
    cout << count << endl;
}

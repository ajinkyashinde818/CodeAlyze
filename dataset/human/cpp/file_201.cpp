#include <bits/stdc++.h>
#include <string.h>
#include<vector>
using namespace std;

int main() {
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int mx,my,mz;
    mx = N/R;
    my = N/G;
    mz = N/B;
    int cnt = 0;
    for(int i=0;i<=mx;i++){
        for(int j=0;j<=my;j++){
                int sum;
                sum = R*i+G*j;
                if((N-sum)%B==0 && N-sum>=0){
                    cnt+=1;
                }
                if(sum>=N)break;

            
        }
    }


    cout << cnt <<endl;
}

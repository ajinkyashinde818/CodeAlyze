#include <bits/stdc++.h>

using namespace std;

int main(){
    int R, G, B, N; cin >> R >> G >> B >> N;

    vector<int> rgb(3, 0);
    rgb[0] = R;
    rgb[1] = G;
    rgb[2] = B;

    int rmax = N/R;
    int gmax = N/G;
    int bmax = N/B;

    int count = 0;
    for(int i=0; i<=rmax; i++){
        for(int j=0; j<=gmax; j++){
            int left = N - i*R - j*G;
            if(left >= 0 && left % B == 0){
                count += 1;
            }
        }
    }
    cout << count << endl;
}

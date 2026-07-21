#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main(){
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    vector<int> rgb;
    rgb.push_back(R);
    rgb.push_back(G);
    rgb.push_back(B);
    sort(rgb.begin(), rgb.end());
    
    int count = 0;
    for(int i = 0; i <= N/rgb[0]; i++){
        int amari = N - rgb[0]*i;
        //cout << rgb[0] * i << " amari " << amari << endl;
        if(amari == 0){

            count++;
            continue;
        }
        for(int j = 0; j <= amari/rgb[1]; j++){
            int amari2 = amari - rgb[1]*j;
            //cout << rgb[0] * i << ", " << rgb[1]*j << "amari " << amari2 << endl;
            if(amari2 == 0){
                count++;
                continue;
            }
            if(amari2 < 0)continue;
            if(amari2%rgb[2] == 0)count++;
        }
    }
    cout << count;


    return 0;
}

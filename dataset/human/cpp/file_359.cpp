#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long N;
    vector<long> RGB(3);
    vector<long> RGBmax(3);

    for(long i = 0; i < 3; i++) {
        cin >> RGB[i];
    }
    cin >> N;

    sort(RGB.begin(), RGB.end(), greater<long>());
    for(long i = 0; i < 3; i++) {
        RGBmax[i] = N / RGB[i];
    }

    long cnt = 0;
    for(long i = 0; i < RGBmax[0] + 1; i++) {
        if(i * RGB[0] > N) break;
        for(long j = 0; j < RGBmax[1] + 1; j++) {
            if(i * RGB[0] + j * RGB[1] > N) break;
            if((i * RGB[0] + j * RGB[1] - N) % RGB[2] == 0) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}

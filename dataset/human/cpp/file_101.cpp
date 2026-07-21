#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int r, g, b, n;cin>>r>>g>>b>>n;
    vector<int> rgb{r, g, b};
    sort(rgb.begin(), rgb.end());

    int big, mid, small;
    big = rgb[2];
    mid = rgb[1];
    small = rgb[0];

    int acc = 0;
    for (int i=0;i<=n/big;i++){
        int temp_1 = n - big * i;
        for (int j=0;j<=temp_1/mid;j++){
            int temp_2 = temp_1 - mid * j;
            if (temp_2 % small == 0){
                acc++;
            }
        }
    }
    cout << acc << endl;
    return 0;

}

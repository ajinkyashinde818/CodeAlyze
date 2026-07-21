#include <iostream>
using namespace std;
int main(void){
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int cnt = 0;
    for(int i = 0;i * r <= n;i++){
        for(int j = 0;j * b <= n - r * i;j++){
            if((n - r * i - b * j) % g == 0){
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}

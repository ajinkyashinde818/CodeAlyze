#include<iostream>
using namespace std;

int main(){
    int R,G,B,N;

    cin >> R >> G >> B >> N;

    int ans = 0;

    for(int i = 0; i*R <= N; i++ ){
        //RによりNの総数が減らされた状態でスタート
        for(int j = 0; j*B <= N-R*i; j++){
            if( (N-R*i - B*j)%G == 0 ){
                ans++;
            }
        }
    }
    cout << ans << endl;

    // G*k = N-R*i - B*j
}

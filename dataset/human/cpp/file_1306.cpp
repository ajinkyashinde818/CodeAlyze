#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
// #include <numeric> // gcdとかlcmとか C++17から
#include <time.h> // time_t timer; time(&timer); でtimerに現在時刻が代入される．
#include <unistd.h> // sleep関数．引数は秒単位．
using namespace std;

typedef long long ll;

ll my_gcd(ll a, ll b){
	return (b==0) ? a : my_gcd(b, a%b);
}

ll my_lcm(ll a, ll b){
	return a*b / my_gcd(a,b);
}

ll factorial(ll a){
	ll ans = 1;
	for(ll i=a; i>0; i--){
		ans *= i;
	}
	return ans;
}

ll pow(ll a, ll b) {
	ll a_powered = 1;
	for (int i=0; i<b; i++) {
		a_powered *= a;
	}
	return a_powered;
}


int main(int argc, char *argv[]){
    int R,G,B,N;
    cin >> R >> G >> B >> N;

    if(R == 1 && G == 1 && B == 1){
        int ans = (N+2)*(N+1)/2;
        cout << ans << endl;
        return 0;
    }

    if(
        (R == 2 && G == 1 && B == 1) ||
        (R == 1 && G == 2 && B == 1) ||
        (R == 1 && G == 1 && B == 2)
    ){
        int ans = 0;
        for(int i=0; i <= N/2; i++){
            ans += N-2*i+1;
        }

        cout << ans << endl;
        return 0;
    }

    int ans=0;
    for(int r=0; r <= N/R; r++){
        for(int g=0; g <= (N-R*r)/G; g++){
            for(int b=0; b <= (N-R*r-G*g)/B; b++){
                int ball_num = R*r + G*g + B*b;
                if(ball_num == N){
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
}

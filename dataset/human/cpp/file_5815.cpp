#include<bits/stdc++.h>
/*
*/

using namespace std;

typedef pair<long long int, vector<long long int>> PLVL;


class combination{
public:

//Nの最大値がわかれば代入する
	combination(long long int combinationThreshold = 1e7){
		( *this ).combinationThreshold = combinationThreshold + 2;
	}

	//a^p % mod
	long long int powmod(long long int A, long long int P, long long int M = LLONG_MAX){
		long long int ans = 1;
		long long int mul = A;
		for( ; P > 0; P >>= 1, mul = ( mul*mul ) % M ){
			if( ( P & 1 ) == 1 ) ans = ( ans*mul ) % M;
		}
		return ans;
	}

	//nCk mod m
	long long int cb(long long int N, long long int K, long long int M = LLONG_MAX){
		if( N < combinationThreshold ){// 事前計算O(N)、答えるのはO(1)
			if( inv.size() == 0 ){
				inv = vector<long long int>(combinationThreshold);
				inv[1] = 1;
				for( long long int i = 2; i < combinationThreshold; i++ ){
					inv[i] = M - ( M / i )*inv[M%i] % M;
				}
				fact = vector<long long int>(combinationThreshold);
				fact[0] = 1;
				revFact = vector<long long int>
					(combinationThreshold);
				revFact[0] = 1;
				for( long long int i = 1; i < combinationThreshold; i++ ){
					fact[i] = ( fact[i - 1] * i ) % M;
					revFact[i] = ( revFact[i - 1] * inv[i] ) % M;
				}
			}
			return ( ( ( fact[N] * revFact[K] ) % M )*revFact[N - K] ) % M;
		} else{
			return cbOnce(N, K, M);
		}
	}

	//一回だけなら最速 O(K + log(M))
	long long int cbOnce(long long int N, long long int K, long long int M = LLONG_MAX){
		if( K > N / 2 ) return cbOnce(N, N - K, M);
		long long int ans = 1;
		long long int div = 1;
		for( long long int i = 0; i < K; i++ ){
			ans *= N - i;
			ans %= M;
			div *= i + 1;
			div %= M;
		}
		ans *= powmod(div, M - 2, M);
		return ans % M;
	}

private:
	vector<vector<long long int>>C;//3000以下の答え
	vector<long long int>fact;//階乗
	vector<long long int>revFact;//階乗の逆元
	vector<long long int>inv;//mod pでの逆元

	long long int combinationThreshold;//Nの最大値がわかれば入れる。
};

int main(){
	long long int N, C;
	cin >> N >> C;
	vector<pair<long long int, long long int>>D(N);
	long long int ans = 0, now = 0, len = 0;
	vector<long long int>memo1(N), memo2(N);
	len = 0;
	now = 0;
	for( size_t i = 0; i < N; i++ ){
		cin >> D[i].first >> D[i].second;
		now -= D[i].first - len;
		len = D[i].first;
		now += D[i].second;
		if( i ){
			memo1[i] = max(now, memo1[i - 1]);
		} else{
			memo1[i] = now;
		}
		ans = max(ans, now);
	}

	len = C;
	now = 0;
	for( int i = N - 1; i >= 0; i-- ){
		now -= len - D[i].first;
		now += D[i].second;
		len = D[i].first;
		if( i != N - 1 ){
			memo2[i] = max(now, memo2[i + 1]);
		} else{
			memo2[i] = now;
		}
		ans = max(ans, now);
	}

	len = 0;
	now = 0;
	for( size_t i = 0; i < N; i++ ){
		now -= ( D[i].first - len ) * 2;
		len = D[i].first;
		now += D[i].second;
		if( i + 1 < N ){
			ans = max(ans, now + memo2[i + 1]);
		}
	}

	len = C;
	now = 0;
	for( int i = N - 1; i >= 0; i-- ){
		now -= ( len - D[i].first ) * 2;
		len = D[i].first;
		now += D[i].second;
		if( i - 1 >= 0 ){
			ans = max(ans, now + memo1[i - 1]);
		}
	}
	/*
	for( size_t i = 0; i < N; i++ ){
		cout << memo1[i] << " ";
	}
	cout << endl;
	for( size_t i = 0; i < N; i++ ){
		cout << memo2[i] << " ";
	}
	cout << endl;
	*/
	cout << ans << endl;
}

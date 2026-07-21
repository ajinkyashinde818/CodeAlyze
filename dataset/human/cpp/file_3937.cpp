#include<bits/stdc++.h>
using namespace std;




typedef pair<long double, long double> point;
typedef pair<point, long double >circle;

int main() {
	point S, T;
	cin >> S.first >> S.second >> T.first >> T.second;
	long long int N;
	cin >> N;
	vector<circle>D( N + 2 );
	for( size_t i = 0; i < N; i++ ) {
		cin >> D[i].first.first >> D[i].first.second >> D[i].second;
	}
	D[N] = make_pair( S, 0 );
	D[N + 1] = make_pair( T, 0 );
	vector<vector<long double>>M( N + 2, vector<long double>( N + 2, LDBL_MAX / 6 ) );
	for( size_t i = 0; i < N + 2; i++ ) {
		M[0][0] = 0;
	}
	for( size_t i = 0; i < N + 2; i++ ) {
		for( size_t j = i + 1; j < N + 2; j++ ) {
			M[i][j] = max( sqrtl( powl( (D[i].first.first - D[j].first.first), 2 ) + powl( (D[i].first.second - D[j].first.second), 2 ) ) - (D[i].second + D[j].second), 0.L );
			M[j][i] = M[i][j];
		}
	}
	priority_queue<pair<long double, long long int>, vector<pair<long double, long long int>>, greater<pair<long double, long long int>>>que;
	que.push( make_pair( 0, N ) );
	vector<long double>ans( N + 2, LDBL_MAX / 6 );
	ans[N] = 0;
	while( que.size() ) {
		auto now = que.top(); que.pop();
		if( now.second == N + 1 ) {
			cout << fixed << setprecision( 20 ) << now.first << endl;
			break;
		}
		if( ans[now.second] != now.first ) {
			continue;
		}
		for( size_t i = 0; i < N + 2; i++ ) {
			if( ans[i] > now.first + M[now.second][i] ) {
				ans[i] = now.first + M[now.second][i];
				que.push( make_pair( ans[i], i ) );
			}
		}
	}

}

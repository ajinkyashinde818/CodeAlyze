#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main(){
	int n, m;
	std::cin >> n >> m;

	using image = std::vector<std::string>;
	image As( n ), Bs( m );

	for( auto&a : As )
		std::cin >> a;
	for( auto&b : Bs )
		std::cin >> b;

	bool ans = true;
	for( int i{}; i <= n - m; ++i )
	{
		for( int j{}; j <= n - m; ++j )
		{
			ans = true;
			for( int k{}; k < m; ++k )
			{
				const auto x = As[i+k].substr( j, m ) == Bs[k];
				ans &= x;
//				std::cout << i << " " << j << " " << k << " => " << ( ans ? "t" : "f" ) << "\n";
			}
			if( ans )
				break;
		}
		if( ans )
			break;
	}


	std::cout << ( ans ? "Yes" : "No" ) << "\n";

	return 0;
}

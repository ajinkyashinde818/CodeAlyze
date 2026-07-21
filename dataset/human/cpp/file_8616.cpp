#include <iostream>
#include <string>

int main()
{
	std::string A[50], B[50];
	int N, M;

	std::cin >> N >> M;
	int i;
	for( i = 0; i < N; i++ ){
		std::cin >> A[i];
	}
	for( i = 0; i < M; i++ ){
		std::cin >> B[i];
	}

	int j;
	//A中にBを探すための始点を指定
	for( i = 0; i < N - M + 1; i++ ){
		for( j = 0; j < N - M + 1; j++ ){
			//AとBの一致を一列ずつ見る
			int k;
			for( k = 0; k < M; k++ ){
				if( A[i + k].substr(j, M) != B[k] ){	//文字列.substr(始点の位置, 切り出す文字数)
					break;
				}
				if( k == M - 1 ){
					std::cout << "Yes" << std::endl;
					return 0;
				}
			}
		}
	}

	std::cout << "No" << std::endl;

	return 0;
}

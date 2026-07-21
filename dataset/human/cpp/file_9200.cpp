#include <iostream>
using namespace std;

int main(){
	int N, M;
	char A[50][50], B[50][50];
	int count;
	
	cin >> N >> M;
	for(int j=0; j<N; ++j)
		for(int i=0; i<N; ++i)
			cin >> A[j][i];
	for(int j=0; j<M; ++j)
		for(int i=0; i<M; ++i)
			cin >> B[j][i];
	
	for(int j=0; j+M<=N; ++j){
		for(int i=0; i+M<=N; ++i){
			count = 0;
			
			for(int y=0; y<M; ++y){
				for(int x=0; x<M; ++x){
					if(A[j+y][i+x] == B[y][x]) ++count;
				}
			}
			if(count == (M*M)){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}

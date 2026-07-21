/*input
3 2
#.#
.#.
#.#
#.
.#
*/

#include <iostream>
#include <vector>

using namespace std;

void display(vector<vector<int>> &M){
	for(int i=0;i<M.size();i++){
		for(int j=0;j<M[i].size();j++){
			cout << M[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int N, M;

	cin >> N >> M;

	vector<vector<int>> A(N);
	vector<vector<int>> B(M);

	for(int i=0;i<N;i++){
		string temp;
		A[i].resize(N);
		cin >> temp;
		for(int j=0;j<temp.size();j++){
			A[i][j] = temp[j] == '#';
		}
	}

	// display(A);

	for(int i=0;i<M;i++){
		string temp;
		B[i].resize(M);
		cin >> temp;
		for(int j=0;j<temp.size();j++){
			B[i][j] = temp[j] == '#';
		}
	}

	// display(B);

	for(int i=0;i<N-M+1;i++){
		for(int j=0;j<N-M+1;j++){
			for(int p=0;p<M;p++){
				for(int q=0;q<M;q++){
					if(A[i+p][j+q] != B[p][q]) goto next;
				}
			}
			cout << "Yes" << endl;
			return 0;
		next:
			int hoge = 0;
		}
	}

	cout << "No" << endl;
	return 0;
}

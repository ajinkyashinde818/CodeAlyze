#include <iostream>
using namespace std;
 
string substring(string text, int low, int digit){
    string output = "";
    for(int i = low; i < low + digit; i++){
        output.push_back(text[i]);
    }

    return output;
}
 
int main(){
    int N;
    int M;
    cin >> N >> M;
    string A[N];
    string B[M];
    bool ok = false;
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 0; i < M; i++){
        cin >> B[i];
    }
    for(int i = 0; i < N - M + 1; i++){
        for(int j = 0; j < N - M + 1; j++){
            bool ok = true;
            for(int k = 0; k < M; k++){
            	for(int l = 0; l < M; l++){
            		if(A[i + k][j + l] != B[l][k]){
            			ok = false;
            			break;
            		}
            	}
            	if(!ok){
            		break;
            	}
            }
            if(ok){
            	cout << "Yes" << endl;
            	return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}

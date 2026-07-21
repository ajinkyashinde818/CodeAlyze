#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int M,N;
    cin >> N >> M;
    
    char a[100][100],b[100][100];
    
    for(int i = 0;i < N;i++){
    	for(int j = 0;j < N;j++){
        	cin >> a[i][j];
        }
    }
    for(int i = 0;i < M;i++){
    	for(int j = 0;j < M;j++){
        	cin >> b[i][j];
        }
    }
   
    
    for(int i = 0;i < N - M + 1;i++){
    	for(int j = 0;j < N - M + 1;j++){
        	bool flag = true;
            for(int k = 0;k < M;k++){
            	for(int l = 0;l < M;l++){
                	if(a[k+i][l+j] != b[k][l]){
                    	flag = false;
                    }
                }
            }
            if(flag){
           		cout << "Yes" << endl;
				return 0;
			}
        }
    }
    
    cout << "No" << endl;
    
    
	return 0;
}

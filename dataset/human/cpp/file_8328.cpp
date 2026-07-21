#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    string S[50], T[50];

    bool flag;

    for(int i=0; i<N; i++){
	cin >> S[i];
    }

    for(int i=0; i<M; i++){
	cin >> T[i];
    }

    
    for(int x=0; x<N; x++){
	for(int y=0; y<N; y++){
	    flag = true;
	    for(int xM=0; xM<M; xM++){
		for(int yM=0; yM<M; yM++){
		    if(y+yM>=N || x+xM>=N || S[x+xM][y+yM]!=T[xM][yM]){
			flag = false;
			break;
		    }		    
		}
	    }
	    if(flag){
		cout <<"Yes"<<endl;
		return 0;
	    }
	}
    }

    cout <<"No"<<endl;


}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string p;
	int N,M;
	vector<vector<string>> NN,MM;
	cin >>N>>M;
	string sbuf;
	vector<string> vbuf;
	for(int i =0;i<N;i++){
		cin >> sbuf;
		vbuf.clear();
		for(int j=0;j<N;j++){
			vbuf.push_back(sbuf.substr(j,1));
		}
		NN.push_back(vbuf);
	}
	for(int i =0;i<M;i++){
		cin >> sbuf;
		vbuf.clear();
		for(int j=0;j<M;j++){
			vbuf.push_back(sbuf.substr(j,1));
		}
		MM.push_back(vbuf);
	}
	
	bool fit = true;
	for(int x = 0;x<N-M+1;x++){
		for(int y = 0;y<N-M+1;y++){
			fit =true;
			for(int i  =0;i<M;i++){
				for(int j =0;j<M;j++){
					if(NN[i+x][j+y] != MM[i][j])
						fit = false;
					if(!fit)
						break;
				}
				if(!fit)
					break;
			}
			if(fit)
				break;
		}
		if(fit)
			break;
	}
	
	
	if(fit)
		cout<< "Yes";
	else
		cout<<"No";

	
	return 0;
}

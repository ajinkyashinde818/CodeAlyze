#include <iostream>
using namespace std;

int main(void){
	char n[50][50], m[50][50];
	int nn, nm, cou;

	cin >> nn >> nm;
	for(int i=0; i<nn; i++){
		cin >> n[i];
	}
	for(int i=0; i<nm; i++){
		cin >> m[i];
	}
	for(int h=0; h<=nn-nm; h++){
		for(int i=0; i<=nn-nm; i++){
			cou=0;
			for(int j=0; j<nm; j++){
				for(int k=0; k<nm; k++){
					if(n[j+h][k+i]!=m[j][k]){
						cou=-1;
					}
					if(cou==-1){
						break;
					}else if(++cou==nm*nm){
						cout << "Yes" << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "No" << endl;
}

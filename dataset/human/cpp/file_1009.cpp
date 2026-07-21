#include<iostream>

using namespace std;




int main(){
	int R,G,B,N;
  	cin >> R >> G >> B >>N;
  	int cont = 0;
	for(int i = 0; i <= N/R; i++){
		for(int j = 0; j <= N/G; j++){
    		if((-R*i-G*j+N)%B==0&&-R*i-G*j+N>=0){
              	cont++;
            	//cout << i << j << endl;
            }
    	}    	
    
    }
  	cout << cont << endl;
}

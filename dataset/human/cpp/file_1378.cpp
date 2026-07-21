#include<iostream>
using namespace std;

int main(){
	int R, G, B, N;
  	cin >> R >> G >> B >> N;
  	
  	int count = 0;
  	for(int r=0; r<=N/R; r++){
    	for(int g=0; g<=N/G; g++){
          	int tmp =N-R*r-G*g;
            if(tmp%B==0 && tmp>=0 && tmp/B>=0){
                count ++;
        }
        }
    }
  	cout << count << endl;
}

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
	int N;
	long long int menor, soma, esq=0, dir=0;
	cin >> N;
	int Cards[N];
	
	
	for(int i=0; i<N; i++) {
		cin >> Cards[i];
		dir += Cards[i];
	}
	esq += Cards[0];
	dir -= Cards[0];
	
	
	if(esq - dir < 0)
		menor = dir - esq;
	else
		menor = esq - dir;
	
	
	for(int i=1; i<N-1; i++) {
		esq += Cards[i];
		dir -= Cards[i];
		soma = esq - dir;
		
		if(soma < 0)
			soma *= -1;
		
		
		if(soma < menor)
			menor = soma;
	}
	
	cout << menor << endl;
	return 0;
}

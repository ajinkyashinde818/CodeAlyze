#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>//for queue and priority_queue
#include <fstream>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#define endl "\n"
typedef long long ll;
using namespace std;
void Lancer() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
bool isPrime(ll n){
	if (n == 2 || n == 3 || n == 5)
		return true;
	else if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n == 1)
		return false;
	else {
		for (int i = 5; i <= sqrt(n); i += 2){
			if (n%i == 0)
				return false;
		}
		return true;
	}
}

char img[57][57], temp[57][57];
int main(){
	Lancer();
	ll n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> img[i][j];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			cin >> temp[i][j];

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (temp[0][0] == img[i][j]){
				if (i + m <= n && j + m <= n){
					bool ch = true;
					for (int k = 0; k < m; k++){
						for (int c = 0; c < m; c++){
							if (temp[k][c] != img[i + k][j + c]){
								ch = false;
								break;
							}
						}
					}
					if (ch){
						cout << "Yes";
						return 0;
					}
				}
			}
		}
	}
	cout << "No";
	cout << endl;
	return 0;
}

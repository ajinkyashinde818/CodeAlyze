#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <tuple>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <ctime>
#define rep(i, n) for(i = 0; i < n; i++)
using namespace std;
typedef tuple<int, int, int> T;
typedef pair<int, int> P;
 
int n;
int a[200000];
int b[200000];
int cntA[200001];
int cntB[200001];
priority_queue<T> queA;	//(count(num, A+B), count(num, A), num)
priority_queue<T> queB; //(count(num, A+B), count(num, B), num)
bool eraseA[200001];
vector<P> pa;			//(numA, numB)
 
signed main() {
	int i;
	clock_t start_time = clock();
	
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	
	rep(i, n) {
		cntA[a[i]]++;
		cntB[b[i]]++;
	}
	
	for (i = 1; i <= n; i++) {
		if (cntA[i] > 0) {
			queA.push(T(cntA[i] + cntB[i], i, cntA[i]));
		}
		else {
			eraseA[i] = true;
		}
		if (cntB[i] > 0) {
			queB.push(T(cntA[i] + cntB[i], i, cntB[i]));
		}
	}
	
	while (!queA.empty()) {
		T tupA = queA.top(); queA.pop();
		T tupB = queB.top(); queB.pop();
		
		if (get<1>(tupA) == get<1>(tupB)) {
			if (queB.empty()) {
				cout << "No" << endl;
				return 0;
			}
			T tupB2 = queB.top(); queB.pop();
			
			//use(tupA, tupB2)
			pa.push_back(P(get<1>(tupA), get<1>(tupB2)));
			if (get<2>(tupA) - 1 > 0) {
				queA.push(T(get<0>(tupA) - 1, get<1>(tupA), get<2>(tupA) - 1));
			}
			else {
				eraseA[get<1>(tupA)] = true;
			}
			queB.push(T(get<0>(tupB) - 1, get<1>(tupB), get<2>(tupB)));
			
			if (get<2>(tupB2) - 1 > 0) {
				queB.push(T(get<0>(tupB2) - 1, get<1>(tupB2), get<2>(tupB2) - 1));
			}
			if (eraseA[get<1>(tupB2)] == false) {
				if ((double)(clock() - start_time) / CLOCKS_PER_SEC < 0.2) {
					vector<T> vec;
					while (!queA.empty()) {
						T now = queA.top(); queA.pop();
						if (get<1>(now) == get<1>(tupB2)) {
							vec.push_back(T(get<0>(now) - 1, get<1>(now), get<2>(now)));
							break;
						}
						else {
							vec.push_back(now);
						}
					}
					rep(i, vec.size()) {
						queA.push(vec[i]);
					}
				}
			}
		}
		else {
			//use(tupA, tupB)
			pa.push_back(P(get<1>(tupA), get<1>(tupB)));
			if (get<2>(tupA) - 1 > 0) {
				queA.push(T(get<0>(tupA) - 1, get<1>(tupA), get<2>(tupA) - 1));
			}
			else {
				eraseA[get<1>(tupA)] = true;
			}
			if (get<2>(tupB) - 1 > 0) {
				queB.push(T(get<0>(tupB) - 1, get<1>(tupB), get<2>(tupB) - 1));
			}
		}
	}
 
	sort(pa.begin(), pa.end());
	
	cout << "Yes" << endl;
	for (int i = 0; i < (int)pa.size(); i++) {
		cout << pa[i].second;
		if (i + 1 < pa.size()) cout << " ";
	}
	cout << endl;
	return 0;
}

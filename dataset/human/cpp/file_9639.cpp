#include<iostream>
#include<vector>
using namespace std;

bool search_small_area(vector<vector<char>>a,vector<vector<char>>b,int i,int j) {
	for (int k(0); k < b.size(); k++) {
		for (int l(0); l < b.size(); l++) {
			if (a[i + k][j + l] != b[k][l])return false;
		}
	}
	return true;
}

bool search_large_area(vector<vector<char>>a,vector<vector<char>>b) {
	int search_length = a.size() - b.size() + 1;
	for (int i(0); i < search_length; i++) {
		for (int j(0); j < search_length; j++) {
			if (search_small_area(a, b, i, j))return true;
		}
	}
	return false;
}

int main(void) {
	int n, m;
	cin >> n >> m;
	vector<vector<char>>a;
	vector<vector<char>>b;
	for (int i(0); i < n; i++) {
		vector<char>tmp_vector;
		for (int j(0); j < n; j++) {
			char tmp;
			cin >> tmp;
			tmp_vector.push_back(tmp);
		}
		a.push_back(tmp_vector);
	}
	for (int i(0); i < m; i++) {
		vector<char>tmp_vector;
		for (int j(0); j < m; j++) {
			char tmp;
			cin >> tmp;
			tmp_vector.push_back(tmp);
		}
		b.push_back(tmp_vector);
	}
	if (search_large_area(a, b))cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

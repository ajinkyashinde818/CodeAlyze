#include<bits/stdc++.h>

using namespace std;

double Value;
string HexInput, BinaryInput;

const string ConvertTable[16] = {
	"0000","0001","0010","0011",
	"0100","0101","0110","0111",
	"1000","1001","1010","1011",
	"1100","1101","1110","1111",
};


void changeToBinary() {
	int index;

	BinaryInput = "";
	for (int i = 0; i < 8; ++i) {
		switch (HexInput[i]) {
			case 'a':index = 10; break;
			case 'b':index = 11; break;
			case 'c':index = 12; break;
			case 'd':index = 13; break;
			case 'e':index = 14; break;
			case 'f':index = 15; break;
			default :index = HexInput[i] - '0'; break;
		}
		BinaryInput += ConvertTable[index];
	}
	reverse(BinaryInput.begin(), BinaryInput.end());
	//cout << "outBinary:" << BinaryInput << endl;
}

void solve() {
	int countOfFraction;
	
	Value = 0;
	countOfFraction = 1;
	for (int i = 0; i < 7; ++i) {
		if (BinaryInput[6-i] != '0') {
			Value += pow(0.5, i + 1);
			countOfFraction = i + 1;
		}
	}
	//cout << Value << " : cnt=" << countOfFraction << endl;

	for (int i = 7; i < 31; ++i) {
		if (BinaryInput[i] != '0') {
			Value += pow(2, i-7);
		}
	}
	if (BinaryInput[31] == '1') {
		cout << "-";
	}
	cout << fixed << setprecision(countOfFraction) << Value << endl;
}

int main() {
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> HexInput;
		changeToBinary();
		solve();
	}
	
	return 0;
}

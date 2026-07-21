#include <bits/stdc++.h>

using namespace std;

int Molecule, Denominator;
string InputInfo;


void getDataWithoutBrackets() {
	int pos, cnt, acc;
	int num, num1;
	stringstream ss;

	pos = InputInfo.find('.');
	cnt = InputInfo.size() - 1 - pos;
	ss << InputInfo.substr(pos + 1, cnt);
	ss >> num;
	//cout << "num=" << num << endl;
	acc = 1;
	if (num != 0) {
		acc = pow(10, cnt);
	}
	//cout << "acc=" << acc << endl;
	ss.clear();
	ss << InputInfo.substr(0, pos);
	ss >> num1;
	num += num1*acc;
	//cout << "num_=" << num << endl;
	Molecule = num;
	Denominator = acc;
}

void getDataWithBrackets(int pos) {
	int posPoint, cnt, cntInter;
	int num, num1;
	string tmp, tmpInter;
	stringstream ss;

	posPoint = InputInfo.find('.');
	cntInter = pos - posPoint - 1;
	//cout << cntInter << endl;
	cnt = InputInfo.size() - 1 - posPoint - 2;
	//cout << cnt << endl;

	tmpInter = InputInfo.substr(0, pos);
	tmpInter.erase(tmpInter.find('.'), 1);
	//cout << tmpInter << endl;
	ss << tmpInter;
	ss >> num;
	//cout << num << endl;

	tmp = tmpInter + InputInfo.substr(pos + 1, InputInfo.size() - 1 - pos - 1);
	//cout << tmp << endl;
	ss.clear();
	ss << tmp;
	ss >> num1;
	//cout << num1 << endl;
	Molecule = num1 - num;
	Denominator = pow(10, cnt) - pow(10, cntInter);
}

int getGcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return getGcd(b, a%b);
}

int main() {
	int gcd, pos;

	cin >> InputInfo;
	pos = InputInfo.find('(');
	if (pos == string::npos) {
		getDataWithoutBrackets();
	}
	else {
		getDataWithBrackets(pos);
	}
	//cout << Molecule << " : " << Denominator << endl;
	gcd = getGcd(Molecule, Denominator);
	//cout << "gcd=" << gcd << endl;
	cout << Molecule / gcd << "/" << Denominator / gcd << endl;

	return 0;
}

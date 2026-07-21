#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
#include <sstream>
#include<map>

using namespace std;

int CalcSaidaiKouyakusu(int a, int b)
{
	int A = max(a, b);
	int B = min(a, b);

	while (1)
	{
		if (A % B == 0)
		{
			return B;
		}
		int tmp = A % B;
		A = B;
		B = tmp;
	}
	return 0;
}

int main() {

	int N;
	cin >> N;

	vector<int> vNum(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> vNum[i];
	}

	bool isKisu = false;
	for (int i = 0; i < N; i++)
	{
		if (vNum[i] < 0)
		{
			isKisu = !isKisu;
		}
	}
	for (int i = 0; i < N; i++)
	{
		vNum[i] = abs(vNum[i]);
	}

	sort(vNum.begin(), vNum.end());
	//reverse(vNum.begin(), vNum.end());

	long long retValue = 0;
	for (int i = 0; i < vNum.size(); i++)
	{
		if (isKisu && i == 0)
		{
			retValue -= abs(vNum[i]);
		}
		else
		{
			retValue += abs(vNum[i]);
		}
	}

	cout << retValue << endl;
	return 0;
}

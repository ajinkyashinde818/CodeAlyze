#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main(void) {

	bool firstlet = true;

	long long n, num = 1, i, j, tmp, first;
	string s;

	cin >> n >> s;

	long long d[n];

	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
	}

	//num = n;
	//tmp = n;

	sort(s.begin(),s.end());

	for (int i = 0; i < n; i++)
	{
		if (firstlet == true) {
			d[i] = 1;
			first = i;
		}
		else {
			d[i] = 0;

			d[first]++;
		}

		if (i != n - 1) {
			if (s[i] != s[i + 1]) {
				firstlet = true;
			}
			else {
				firstlet = false;
			}
		}

		//cout << i << " " << d[i] << " " << "\n";
	}



	/*	for (j = i + 1; j < n; j++)
		{
			if (i != n - 1) {
				if (s[i] == s[j]) {

					d[i]++;
					d[j] = 0;
					//printf("i=%d,j=%d\n", i, j);

				}
			}
		}
	}*/


	for (int i = 0; i < n; i++)
	{
		if (d[i] != 0) {
			num = num *(d[i]+1);

			num = num % ((long long)(pow(10, 9)) + 7);
		}

		//printf("d[%d]=%d,num=%d\n",i,d[i], num);
		
	}

	num--;

	//num = int(pow(2, tmp));

	cout << num << "\n";

	return 0;
}

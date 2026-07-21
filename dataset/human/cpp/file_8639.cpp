#include <iostream>
#include<sstream>
#include<vector>
#include<iterator>
using namespace std;

int main(void)
{
	int N, M;
	cin >> N >> M;

	vector<string> A(N), B(M);
	for(int i=0; i<N; i++)
		cin >> A[i];
	for(int i=0; i<M; i++)
		cin >> B[i];

	string ret = "No";
	for(int i=0; i<N-M+1; i++)
	{
		auto pos = A[i].find(B[0], 0);
		while(pos != string::npos)
		{
			bool ok = true;
			for(int j=1; j<M; j++)
			{
				if(A[i+j].substr(pos, M) != B[j])
				{
					ok = false;
					break;
				}
			}

			if(ok == true)
			{
				ret = "Yes";
				i = N;
				pos = string::npos;
				break;
			}

			pos = A[i].find(B[0], pos+1);
		}

	}

	cout << ret << endl;

	return 0;
}

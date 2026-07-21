#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <map>
using namespace std;

int main()
{
	int R,G,B,N,ANS=0;
	cin >> R >> G >> B >> N;

	for(int i=0;i<=3000;i++)
	{
		for(int j=0;j<=3000;j++)
		{
			if(N>=R*i+G*j&&(N-R*i-G*j)%B==0)
			{
				ANS++;
			}
		}
	}
	cout << ANS << endl;
}

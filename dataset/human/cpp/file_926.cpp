#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

int R,G,B,N;
int ans;

int main()
{
	ios::sync_with_stdio(0);
	cin >> R >> G >> B >> N;
	for (int i = 0;i * R <= N;i++)
		for (int j = 0;i * R + j * G <= N;j++)
			if ((N - i * R - j * G) % B == 0)
				ans++;
	cout << ans << endl;
	return 0;
}

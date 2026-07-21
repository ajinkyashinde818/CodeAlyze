#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <string>

using namespace std;

int N, R;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	cin >> N >> R;
	if (N >= 10)
		cout << R;
	else
		cout << 100*(10 - N) + R;
	
	
}

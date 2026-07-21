#include <iostream>

using namespace std;

int main(void)
{
	int join_times, out_rate;
	cin >> join_times >> out_rate;
	if (join_times < 10) cout << out_rate + (100 * (10 - join_times)) << endl;
	else cout << out_rate << endl;
	return (0);
}

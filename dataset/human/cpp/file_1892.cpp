#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int q;

	cin >> q;

	for (int i = 0; i < q; i++) {
		long long s;
		long double t;

		cin >> hex >> s;

		if (s > 0x80000000 - 1)
			cout << "-";

		s %= 0x80000000;
		t = s;
		t /= 128;

		if (s % 128 != 0)
			cout << setprecision(20) << t << endl;
		else
			cout << t << ".0" << endl;			
	}

	return 0;
}

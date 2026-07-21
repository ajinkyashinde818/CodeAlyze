#include <iostream>
#include <complex>
#include <cmath>
using namespace std;

int main()
{
	int n, m;
	complex<double> w[100];
	int r[100];

	cin >> n;

	while (n > 0) {
		for (int i = 0; i < n; i++) {
			double x, y;

			cin >> x >> y >> r[i];
			w[i] = complex<double> (x, y);
		}

		cin >> m;

		for (int j = 0; j < m; j++) {
			double tx, ty, sx, sy;
			complex<double> t, s;
			bool f = 1;

			cin >> tx >> ty >> sx >> sy;
			t = complex<double>(tx, ty);
			s = complex<double>(sx, sy);

			for (int i = 0; i < n; i++) {
				if ((abs(t - w[i]) - r[i]) * (abs(s - w[i]) - r[i]) <= 0)
					f = 0;
				else if(abs(t - w[i]) > r[i] && abs(s - w[i]) > r[i]){

					if (abs(arg((t - s) / (w[i] - s))) <= asin(r[i] / abs(w[i] - s))
						&& abs(t - s) * abs(t - s) >= abs(w[i] - s) * abs(w[i] - s) - r[i] * r[i])
						f = 0;
				}
			}

			if (f)
				cout << "Danger" << endl;
			else
				cout << "Safe" << endl;
		}

		cin >> n;
	}

	return 0;
}

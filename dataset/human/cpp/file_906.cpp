#include<iostream>

using namespace std;

int main()
{
	unsigned int a, b, c,d,e,f, n,ans=0;


	cin >>d >> e >> f >> n;

	if (d >= e && d >= f) {
		a = d;
		if (e >= f) {
			b = e;
			c = f;
		}
		else {
			b = f;
			c = e;
		}
	}

	if (d <= e && e >= f) {
		a = e;
		if (d >= f) {
			b = d;
			c = f;
		}
		else {
			b = f;
			c = d;
		}
	}
			if (f >= e && d <= f) {
				a = f;
				if (e >= d) {
					b = e;
					c = d;
				}
				else {
					b = d;
					c = e;
				}
			}
		for (int j = 0; j <= n / a; j++)
		{
				for (int k = 0; k <= (n - j * a) / b; k++)
				{
					if ((n - (j * a + b * k)) % c == 0) ans++;
				}
		}
		cout << ans;
	return 0;
}

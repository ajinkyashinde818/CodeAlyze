#include <bits/stdc++.h>

using namespace std;

class Position {
public:
	double x, y, r;
};

const double EXP = 1e-8;
Position CircleData[100];
Position Person, Ghost;
int N, M;

bool isInCircle(const Position &data, const Position &circle) {
	double x, y;

	x = data.x - circle.x;
	y = data.y - circle.y;
	return (x*x + y*y < circle.r*circle.r);
}

bool isSafe() {
	bool inCircle1, inCircle2;
	double lenOfPGToCircle, p, q, r, k, b, deta, x1, x2, y1, y2, min, max;

	for (int j = 0; j < N; j++) {
		p = CircleData[j].x;
		q = CircleData[j].y;
		r = CircleData[j].r;

		inCircle1 = isInCircle(Person, CircleData[j]);
		inCircle2 = isInCircle(Ghost, CircleData[j]);
		if (inCircle1 != inCircle2) {
			return true;
		}
		if (inCircle1 && inCircle2) {
			continue;
		}

		if (Person.x == Ghost.x) {
			lenOfPGToCircle = fabs(Person.x - CircleData[j].x);
			//cout << "lenOfPGToCircle:" << lenOfPGToCircle << endl;
			if (lenOfPGToCircle > CircleData[j].r) {
				continue;
			}

			min = Person.y;
			max = Ghost.y;
			if (min > max) {
				min = Ghost.y;
				max = Person.y;
			}

			if (lenOfPGToCircle == CircleData[j].r) {
				y1 = q;
				if (min <= y1 && y1 <= max) {
					return true;
				}
			}
			else if (lenOfPGToCircle < CircleData[j].r) {
				y1 = q - sqrt(r*r - (Person.x - p)*(Person.x - p));
				y2 = q + sqrt(r*r - (Person.x - p)*(Person.x - p));
				if (min <= y1 && y2 <= max) {
					return true;
				}
			}
			continue;
		}


		k = (Person.y - Ghost.y) / (Person.x - Ghost.x);
		b = Person.y - k*Person.x;
		//cout << "k:" << k << "  b:" << b << endl;

		deta = 4 * pow((k*b - p - k*q), 2) - 4 * (1 + k*k)*(p*p + pow((b - q), 2) - r*r);
		//cout << "deta:" << deta << endl;
		if (deta < 0) {
			continue;
		}

		min = Ghost.x;
		max = Person.x;
		if (min > max) {
			min = Person.x;
			max = Ghost.x;
		}
		if (deta > EXP) {
			x1 = (2 * (p + k*q - k*b) - sqrt(deta)) / (2 * (1 + k*k));
			x2 = (2 * (p + k*q - k*b) + sqrt(deta)) / (2 * (1 + k*k));
			//cout << "x1:" << x1 << "  x2:" << x2 << endl;
			if ((min <= x1 && x1 <= max) || (min <= x2 && x2 <= max) || (min <= x1 && x2 <= max)) {
				return true;
			}
			continue;
		}

		if (deta <= EXP) {
			x1 = (p + k*q - k*b) / (1 + k*k);
			//cout << "x1:" << x1 << endl;
			if (min <= x1 && x1 <= max) {
				return true;
			}
		}
	}

	return false;
}


void solve() {


	if (isSafe()) {
		cout << "Safe" << endl;
	}
	else {
		cout << "Danger" << endl;
	}

}


int main() {

	while (cin >> N, N) {
		for (int i = 0; i < N; i++) {
			cin >> CircleData[i].x >> CircleData[i].y >> CircleData[i].r;
		}
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> Person.x >> Person.y >> Ghost.x >> Ghost.y;
			solve();
		}


		//show();
	}

	return 0;
}

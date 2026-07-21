#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {

	int n, m;

	cin >> n >> m;

	vector<string> a(n), b(m);

	bool itti = true, go = false;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	for (int ay = 0; ay < n; ay++)
	{
		for (int ax = 0; ax < n; ax++)
		{
			//cout << "\n///////////////////////////////\n\nnext";
			//printf("(%d ,%d)\n", ay, ax);

			itti = true;

			for (int by = 0; by < m; by++)
			{
				for (int bx = 0; bx < m; bx++)
				{
					//printf("ay%dax%dby%dbx%d\n", ay, ax, by, bx);
					//if (by + ay <= n && bx + ax <= n) {
						/*if (a[by + ay].at(bx + ax) == b[by].at(bx)) {
							
							cout << a[by + ay].at(bx + ax) << b[by].at(bx);
							cout << "w\n";
						}*/
					//}
					if (ay + m <= n && ax + m <= n) {
						if (a[by + ay].at(bx + ax) != b[by].at(bx)) {
							itti = false;
							//cout << "*  ";
							//printf("ay=%d,ax=%d,by=%d,bx=%d\n", ay, ax, by, bx);
							//cout << a[ay + by].at(ax + bx);
							//cout << b[by].at(bx) << "\n\n";
						}
						else {
							//cout << "o  ";
							//printf("ay=%d,ax=%d,by=%d,bx=%d\n", ay, ax, by, bx);
							//cout << a[ay + by].at(ax + bx);
							//cout << b[by].at(bx) << "\n\n";
						}
					}
					else {
						itti = false;
					}
				}
			}

			if (itti == true) {
				go = true;
				//cout << "\ntrue\n";
			}
		}
	}

	if (go == true)cout << "Yes\n";
	else cout << "No\n";

	return 0;
}

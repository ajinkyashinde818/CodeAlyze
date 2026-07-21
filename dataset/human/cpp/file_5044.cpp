#include <iostream>
using namespace std;

class i_rating
{
public:
	void setNR()
	{
		cin >> N >> R;
	}
	void calculateR()
	{
		if (N < 10)
		{
			cout << R + 100 * (10 - N) << endl;;
		}
		else
		{
			cout << R << endl;
		}
	}
private:
	int N;
	int R;
};

int main()
{
	i_rating r;
	r.setNR();
	r.calculateR();

	return 0;
}

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Point
{
public:
	double x, y;
};

class Circle
{
public:
	double x, y, r;
};

bool isInCircle(Point p, Circle c)
{
	double a = pow(p.x - c.x, 2.0) + pow(p.y - c.y, 2.0);
	if(a < c.r * c.r)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

bool isIntersectCircleAndLine(Point p1, Point p2, Circle c)
{
	if(isInCircle(p1, c) && isInCircle(p2, c)) 
	{
		return(false);
	}

	double vx1 = (c.x - p1.x);
	double vy1 = (c.y - p1.y);
	double vx2 = (p2.x - p1.x);
	double vy2 = (p2.y - p1.y);

	double n1 = vx1 * vx2 + vy1 * vy2;
	double n2 = vx2 * vx2 + vy2 * vy2;
	double n3 = vx1 * vx1 + vy1 * vy1;
	
	if(n1 < 0)
	{
		if(pow(p1.x - c.x, 2.0) + pow(p1.y - c.y, 2.0) <= c.r * c.r)
		{
			return(true);
		}
		else
		{
			return(false);
		}
	}
	else if(n1 > n2)
	{
		if(pow(p2.x - c.x, 2.0) + pow(p2.y - c.y, 2.0) <= c.r * c.r)
		{
			return(true);
		}
		else
		{
			return(false);
		}
	}
	else
	{
		if(n2 <= 0) 
		{
			if(n3 * n2 - n1 * n1 >= c.r * c.r * n2)
			{
				return(true);
			}
			else
			{
				return(false);
			}
		}
		else
		{
			if(n3 * n2 - n1 * n1 <= c.r * c.r * n2)
			{
				return(true);
			}
			else
			{
				return(false);
			}
		} 
	}
}

void solve()
{
	int n;
	while(cin >> n, n)
	{
		vector<Circle> circle(n);
		for(int i = 0; i < n; ++i)
		{
			cin >> circle[i].x >> circle[i].y >> circle[i].r;
		}
		int m;
		cin >> m;
		for(int i = 0; i < m; ++i)
		{
			Point taro, oni;
			cin >> taro.x >> taro.y >> oni.x >> oni.y;
			bool isSafe = false;
			for(int j = 0; j < circle.size(); ++j)
			{
				if(isIntersectCircleAndLine(taro, oni, circle[j]))
				{
					isSafe = true;
				}
			}
			if(isSafe)
			{
				cout << "Safe" << endl;
			}
			else
			{
				cout << "Danger" << endl;
			}
		}
	}
}

int main()
{
	solve();
	return(0);
}

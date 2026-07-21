#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

double const EPS = 1.0e-10;

class Point
{
public:
    double y, x;
    Point(){
        y = x = 0.0;
    }
    Point(double y0, double x0){
        y = y0;
        x = x0;
    }
    double dot(const Point& p) const{
        return y * p.y + x * p.x; // |a|*|b|*cosÆ
    }
    double cross(const Point& p) const{
        return x * p.y - y * p.x; // |a|*|b|*sinÆ
    }
    Point operator+(const Point& p) const{
        return Point(y + p.y, x + p.x);
    }
    Point operator-(const Point& p) const{
        return Point(y - p.y, x - p.x);
    }
    Point operator*(double a) const{
        return Point(y * a, x * a);
    }
    Point operator/(double a) const{
        return Point(y / a, x / a);
    }
};

class Line
{
public:
    double a, b, c; // a*x + b*y + c = 0
    Line(double a0, double b0, double c0){
        a = a0;
        b = b0;
        c = c0;
    }
    Line(const Point& p1, const Point& p2){
        double dy = p2.y - p1.y;
        double dx = p2.x - p1.x;
        if(abs(dy / dx) < EPS){
            a = 0.0;
            b = 1.0;
            c = -p1.y;
        }else if(abs(dx / dy) < EPS){
            a = 1.0;
            b = 0.0;
            c = -p1.x;
        }else{
            a = - dy / dx;
            b = 1.0;
            c = dy / dx * p1.x - p1.y;
        }
    }
};

int circleLineIntersection(const Point& p, double r, const Line& l, vector<Point>& intersection)
{
    double s = l.a * p.x + l.b * p.y + l.c;
    double t = (l.a*l.a + l.b*l.b) * r*r - s*s;

    if(t < -EPS){
        intersection.resize(0);
        return 0;
    }
    if(t < EPS){
        intersection.assign(1, Point(l.b, l.a) * (-s / (l.a*l.a + l.b*l.b)) + p);
        return 1;
    }

    intersection.assign(2, Point(l.a, -l.b) * sqrt(t));
    intersection[1] = intersection[1] * -1;
    for(int i=0; i<2; ++i)
        intersection[i] = (intersection[i] - Point(l.b, l.a) * s) / (l.a*l.a + l.b*l.b) + p;
    return 2;
}

int main()
{
    for(;;){
        int n;
        cin >> n;
        if(n == 0)
            return 0;

        vector<Point> center(n);
        vector<double> r(n);
        for(int i=0; i<n; ++i)
            cin >> center[i].x >> center[i].y >> r[i];

        int m;
        cin >> m;

        while(--m >= 0){
            Point p1, p2;
            cin >> p1.x >> p1.y >> p2.x >> p2.y;
            Line l(p1, p2);

            bool safe = false;
            for(int i=0; i<n; ++i){
                vector<Point> p;
                circleLineIntersection(center[i], r[i], l, p);
                for(unsigned j=0; j<p.size(); ++j){
                    if(min(p1.y, p2.y) - EPS < p[j].y && p[j].y < max(p1.y, p2.y) + EPS
                           && min(p1.x, p2.x) - EPS < p[j].x && p[j].x < max(p1.x, p2.x) + EPS)
                        safe = true;
                }
            }

            if(safe)
                cout << "Safe" << endl;
            else
                cout << "Danger" << endl;
        }
    }
}

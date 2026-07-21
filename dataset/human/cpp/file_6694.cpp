// Hide-and-Seek Supporting System

#include<iostream>
#include<cmath>     // fabs(), hypot()
#include<vector>    // Circle::crosspoint()の戻り値, Polygonのメンバ変数
#include<algorithm> // min()

const double EPS = 1e-10;
enum POSITION {ONLINE_FRONT = -2, CLOCKWISE, ON_SEGMENT, COUNTER_CLOCKWISE, ONLINE_BACK};   // ccw(a, b, p)で3点a, b, pの位置関係を返す
                                                                                            //   0: a-p-b, 2: p-a-b, -2: a-b-p, 1: -a-b-の上にp, -1: -a-b-の下にp
// class
class Point;
class Segment;
class Line;
class Circle;
class Polygon;
// member
class Point {
    double x_value, y_value;
public:
    Point() :x_value(0.0), y_value(0.0) {}
    Point(double d) :x_value(d), y_value(d) {}
    Point(double a, double b) :x_value(a), y_value(b) {}
    double x() const {return x_value;}
    double y() const {return y_value;}
    double x(double d) {return x_value = d;}
    double y(double d) {return y_value = d;}
    bool operator== (const Point&) const;
    bool operator!= (const Point&) const;
    bool operator< (const Point&) const;
    bool operator> (const Point&) const;
    bool operator<= (const Point&) const;
    bool operator>= (const Point&) const;
    const Point operator-() const;
    const Point& operator=(const Point&);
    const Point& operator+=(const Point&);
    const Point& operator-=(const Point&);
    const Point& operator*=(const Point&);
    const Point& operator/=(const Point&);
    double dot(const Point&) const;
    double cross(const Point&) const;
    double abs() const;
    double norm() const;
    double distance(const Point&) const;
    double distance(const Segment&) const;
    double distance(const Line&) const;
    bool intersect(const Point&) const;
    bool intersect(const Segment&) const;
    bool intersect(const Line&) const;
    const Point projection(const Line&) const;
    const Point reflection(const Line&) const;
    POSITION ccw(const Point&, const Point&) const;
};
const Point operator+(const Point& lhs, const Point& rhs);
const Point operator-(const Point& lhs, const Point& rhs);
const Point operator*(const Point& lhs, const Point& rhs);
const Point operator/(const Point& lhs, const Point& rhs);
class Segment {
    Point source_point, target_point;
public:
    Segment(double x1 = 0.0, double y1 = 0.0, double x2 = 0.0, double y2 = 0.0) :source_point(Point(x1, y1)), target_point(Point(x2, y2)) {}
    Segment(const Point& a, const Point& b) :source_point(a), target_point(b) {}
    const Point& source() const {return source_point;}
    const Point& target() const {return target_point;}
    const Point& source(const Point& p) {return source_point = p;}
    const Point& target(const Point& p) {return target_point = p;}
    const Line line() const;
    double distance(const Point&) const;
    double distance(const Segment&) const;
    double distance(const Line&) const;
    bool intersect(const Point&) const;
    bool intersect(const Segment&) const;
    bool intersect(const Line&) const;
    bool parallel(const Segment&) const;
    bool parallel(const Line&) const;
    bool orthogonal(const Segment&) const;
    bool orthogonal(const Line&) const;
    POSITION ccw(const Point&) const;
};
class Line {
    Point source_point, target_point;
public:
    Line(double x1 = 0.0, double y1 = 0.0, double x2 = 0.0, double y2 = 0.0) :source_point(Point(x1, y1)), target_point(Point(x2, y2)) {}
    Line(const Point& a, const Point& b) :source_point(a), target_point(b) {}
    const Point& source() const {return source_point;}
    const Point& target() const {return target_point;}
    const Point& source(const Point& p) {return source_point = p;}
    const Point& target(const Point& p) {return target_point = p;}
    const Segment segment() const;
    double distance(const Point&) const;
    double distance(const Segment&) const;
    double distance(const Line&) const;
    bool intersect(const Point&) const;
    bool intersect(const Segment&) const;
    bool intersect(const Line&) const;
    bool parallel(const Segment&) const;
    bool parallel(const Line&) const;
    bool orthogonal(const Segment&) const;
    bool orthogonal(const Line&) const;
    const Point projection(const Point&) const;
    const Point reflection(const Point&) const;
    const Point crosspoint(const Line&) const;
    POSITION ccw(const Point&) const;
};
class Circle {
    Point center_point;
    double radius;
public:
    Circle(double a = 0.0, double b = 0.0, double c = 0.0) :center_point(Point(a, b)), radius(c) {}
    const Point& center() const {return center_point;}
    double x() const {return center_point.x();}
    double y() const {return center_point.y();}
    double r() const {return radius;}
    const Point& center(const Point& p) {return center_point = p;}
    double x(double d) {return center_point.x(d);}
    double y(double d) {return center_point.y(d);}
    double r(double d) {return radius = d;}
    bool include(const Point&) const;
    bool include(const Segment&) const;
    bool include(const Circle&) const;
    bool intersect(const Circle&) const;
    std::vector<Point> crosspoint(const Circle&) const;
};
class Polygon {
    std::vector<Point> point;
public:
    Polygon() {}
    const std::vector<Point>& vertex() const {return point;}
    const Point& vertex(int i) const {return point.at(i);}
    const std::vector<Segment> edge() const {
        std::vector<Segment> result;
        for(int i = 0; i < size(); ++i) result.push_back(Segment(vertex(i), vertex((i + 1) % size())));
        return result;
    }
    const Segment edge(int i) const {return Segment(vertex(i), vertex((i + 1) % size()));}
    int size() const {return point.size();}
    void add(const Point&);
    double area() const;
    bool convex() const;
    bool include(const Point&) const;
    bool on_edge(const Point&) const;
};
// Point
bool Point::operator== (const Point &p) const {return x() == p.x() && y() == p.y();}
bool Point::operator!= (const Point &p) const {return x() != p.x() || y() != p.y();}
bool Point::operator<(const Point &p) const {return x() != p.x() ? x() < p.x() : y() < p.y();}
bool Point::operator>(const Point &p) const {return x() != p.x() ? x() > p.x() : y() > p.y();}
bool Point::operator<=(const Point &p) const {return x() != p.x() ? x() < p.x() : y() <= p.y();}
bool Point::operator>=(const Point &p) const {return x() != p.x() ? x() > p.x() : y() >= p.y();}
const Point operator+(const Point& lhs, const Point& rhs) {return Point(lhs.x() + rhs.x(), lhs.y() + rhs.y());}
const Point operator-(const Point& lhs, const Point& rhs) {return Point(lhs.x() - rhs.x(), lhs.y() - rhs.y());}
const Point operator*(const Point& lhs, const Point& rhs) {return Point(lhs.x() * rhs.x(), lhs.y() * rhs.y());}
const Point operator/(const Point& lhs, const Point& rhs) {return Point(lhs.x() / rhs.x(), lhs.y() / rhs.y());}
const Point Point::operator-() const {return Point(-x(), -y());}
const Point& Point::operator=(const Point& p) {x(p.x()); y(p.y()); return *this;}
const Point& Point::operator+=(const Point& p) {return *this = *this + p;}
const Point& Point::operator-=(const Point& p) {return *this = *this - p;}
const Point& Point::operator*=(const Point& p) {return *this = *this * p;}
const Point& Point::operator/=(const Point& p) {return *this = *this / p;}
double Point::dot(const Point& p) const {return x() * p.x() + y() * p.y();}
double Point::cross(const Point& p) const {return x() * p.y() - y() * p.x();}
double Point::abs() const {return hypot(x(), y());}
double Point::norm() const {return x() * x() + y() * y();}
double Point::distance(const Point& p) const {return (p - (*this)).abs();}
double Point::distance(const Segment& s) const {return s.distance(*this);}
double Point::distance(const Line& l) const {return l.distance(*this);}
bool Point::intersect(const Point& p) const {return *this == p;}
bool Point::intersect(const Segment& s) const {return s.intersect(*this);}
bool Point::intersect(const Line& l) const {return l.intersect(*this);}
const Point Point::projection(const Line& l) const {return l.projection(*this);}
const Point Point::reflection(const Line& l) const {return l.reflection(*this);}
POSITION Point::ccw(const Point& b, const Point& p) const {
    const Point& a = *this;
    Point v1 = b - a;
    Point v2 = p - a;
    if(v1.cross(v2) > EPS) return COUNTER_CLOCKWISE;
    if(v1.cross(v2) < -EPS) return CLOCKWISE;
    if(v1.dot(v2) < -EPS) return ONLINE_BACK;
    if(v2.norm() - v1.norm() > EPS) return ONLINE_FRONT;
    return ON_SEGMENT;
}
// Segment
const Line Segment::line() const {return Line(source(), target());}
double Segment::distance(const Point& p) const {
    Point q = line().projection(p);
    if(intersect(q)) return q.distance(p);
    return std::min(source().distance(p), target().distance(p));
}
double Segment::distance(const Segment& s) const {
    if(intersect(s)) return 0.0;
    double a = distance(s.source());
    double b = distance(s.target());
    double c = s.distance(source());
    double d = s.distance(target());
    return std::min({a, b, c, d});
}
double Segment::distance(const Line& l) const {return l.distance(*this);}
bool Segment::intersect(const Point& p) const {return source().distance(p) + target().distance(p) - target().distance(source()) <= EPS;}
bool Segment::intersect(const Segment& s) const {
    bool a = ccw(s.source()) * ccw(s.target()) <= 0;
    bool b = s.ccw(source()) * s.ccw(target()) <= 0;
    return a && b;
}
bool Segment::intersect(const Line& l) const {return l.intersect(*this);}
bool Segment::parallel(const Line& l) const {line().parallel(l);}
bool Segment::parallel(const Segment& s) const {return line().parallel(s.line());}
bool Segment::orthogonal(const Line& l) const {return line().orthogonal(l);}
bool Segment::orthogonal(const Segment& s) const {return line().orthogonal(s.line());}
POSITION Segment::ccw(const Point& p) const {return source().ccw(target(), p);}
// Line
const Segment Line::segment() const {return Segment(source(), target());}
double Line::distance(const Point& p) const {return p.distance(projection(p));}
double Line::distance(const Segment& s) const {
    if(intersect(s)) return 0.0;
    double a = distance(s.source());
    double b = distance(s.target());
    return a < b ? a : b;
}
double Line::distance(const Line& l) const {return intersect(l) ? 0.0 : distance(l.source());}
bool Line::intersect(const Point& p) const {
    Point v1 = source() - p;
    Point v2 = target() - p;
    return fabs(v2.cross(v1)) < EPS;
}
bool Line::intersect(const Segment& s) const {
    Point v1 = target() - source();
    Point v2 = s.source() - source();
    Point v3 = s.target() - source();
    return v1.cross(v2) * v1.cross(v3) <= EPS;
}
bool Line::intersect(const Line& l) const {
    Point v1 = target() - source();
    Point v2 = l.target() - l.source();
    Point v3 = l.source() - source();
    return fabs(v1.cross(v2)) > EPS || fabs(v1.cross(v3)) < EPS;
}
bool Line::parallel(const Line& l) const {
    double dx = target().x() - source().x();
    double dy = target().y() - source().y();
    double dxl = l.target().x() - l.source().x();
    double dyl = l.target().y() - l.source().y();
    return fabs(dy * dxl - dyl * dx) <= EPS;
}
bool Line::parallel(const Segment& s) const {return parallel(s.line());}
bool Line::orthogonal(const Line& l) const {
    double dx = target().x() - source().x();
    double dy = target().y() - source().y();
    double dxl = l.target().x() - l.source().x();
    double dyl = l.target().y() - l.source().y();
    return fabs(dy * dyl + dxl * dx) <= EPS;
}
bool Line::orthogonal(const Segment& s) const {return orthogonal(s.line());}
const Point Line::projection(const Point& p) const {
    Point v1 = p - source();
    Point v2 = source() - target();
    return Point(source() + v2 * (v1.dot(v2) / v2.norm()));
}
const Point Line::reflection(const Point& p) const {
    return p + (projection(p) - p) * 2.0;
}
const Point Line::crosspoint(const Line& l) const {
    Point v1 = target() - source();
    Point v2 = l.target() - l.source();
    Point v3 = target() - l.source();
    double a = v1.cross(v2);
    double b = v1.cross(v3);
    if(fabs(a) <= EPS && fabs(b) <= EPS) return l.source();
    return l.source() + v2 * (b / a);
}
POSITION Line::ccw(const Point& p) const {return source().ccw(target(), p);}
// Circle
bool Circle::include(const Point& p) const {return center().distance(p) - r() <= EPS;}
bool Circle::include(const Segment& s) const {return center().distance(s) - r() <= EPS;}
bool Circle::include(const Circle& c) const {return center().distance(c.center()) - (r() - c.r()) <= EPS;}
bool Circle::intersect(const Circle& c) const {return center().distance(c.center()) - r() - c.r() <= EPS;}
std::vector<Point> Circle::crosspoint(const Circle& c) const {
    double angle = atan2(c.y() - y(), c.x() - x());
    double d = center().distance(c.center());
    double add = acos((d * d + r() * r() - c.r() * c.r()) / (2.0 * d * r()));
    std::vector<Point> result;
    result.push_back(Point(x() + r() * cos(angle + add), y() + r() * sin(angle + add)));
    result.push_back(Point(x() + r() * cos(angle - add), y() + r() * sin(angle - add)));
    return result;
}
// Polygon
void Polygon::add(const Point& p) {point.push_back(p);}
double Polygon::area() const {
    double sum = 0.0;
    for(int i = 0; i < size(); ++i) sum += vertex(i).cross(vertex((i+1) % size()));
    return fabs(sum) / 2.0;
}
bool Polygon::convex() const {
    POSITION direction = ONLINE_BACK;
    for(int i = 1; i < size(); ++i) {
        POSITION d = vertex(i - 1).ccw(vertex(i), vertex((i + 1) % size()));
        if(d != CLOCKWISE && d != COUNTER_CLOCKWISE) continue;
        if(direction == ONLINE_BACK) direction = d;
        if(direction != d) return false;
    }
    return true;
}
bool Polygon::include(const Point& p) const {
    bool in = false;
    for(int i = 0; i < size(); ++i) {
        Point a = vertex(i) - p;
        Point b = vertex((i + 1) % size()) - p;
        if(a.y() > b.y()) std::swap(a, b);
        if(a.y() <= 0.0 && 0 < b.y() && a.cross(b) < 0.0) in = !in;
        if(fabs(a.cross(b)) <= EPS && a.dot(b) <= EPS) return true;
    }
    return in;
}
bool Polygon::on_edge(const Point& p) const {
    for(int i = 0; i < size(); ++i) if(vertex(i).ccw(vertex((i + 1) % size()), p) == ON_SEGMENT) return true;
    return false;
}

using namespace std;
int main() {
    int n, m;
    while(cin >> n, n) {
        vector<Circle> wall(n);
        for(auto& w: wall) {
            double x, y, r;
            cin >> x >> y >> r;
            w = Circle(x, y, r);
        }
        for(cin >> m; m > 0; --m) {
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            Segment sight(x1, y1, x2, y2);
            Point Taro = sight.source();
            Point ogre = sight.target();
            bool visible = true;
            for(auto& w: wall) {
                if(w.include(Taro) && !w.include(ogre)) visible = false;
                else if(w.include(Taro) && w.include(ogre)) continue;
                else if(w.include(sight)) visible = false;
                if(!visible) break;
            }
            cout << (visible ? "Danger" : "Safe") << endl;
        }
    }
}

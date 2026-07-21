#include <iostream>
#include <algorithm>
#include <complex>
#include <cmath>
using namespace std;

typedef complex<double> P;
const double eps = 1e-8;

bool equals(double a, double b) {
  return abs(a-b) < eps;
}

double cross(P a, P b) {
  return a.real()*b.imag() - a.imag()*b.real();
}

double dot(P a, P b) {
  return a.real()*b.real() + a.imag()*b.imag();
}

double getDistanceLP(P s1, P s2, P p) {
  return abs(cross(s2-s1, p-s1)/abs(s2-s1));
}

double getDistanceSP(P s1, P s2, P p) {
  if(dot(s2-s1, p-s1) < 0.0) return abs(p-s1);
  if(dot(s1-s2, p-s2) < 0.0) return abs(p-s2);
  return getDistanceLP(s1, s2, p);
}

const int MAXN = 100;
int n;
P w[MAXN];
double r[MAXN];
int m;

bool safe(const P &t, const P &s) {
  for(int i = 0; i < n; ++i) {
    bool a, b;
    a = abs(w[i]-t) < r[i];
    b = abs(w[i]-s) < r[i];
    if(a ^ b) return true;
    if(!a) {
      double dist = getDistanceSP(t, s, w[i]);
      if(equals(dist, r[i]) || dist < r[i]) return true;
    }
  }
  return false;
}

int main() {
  while(cin >> n && n) {
    for(int i = 0; i < n; ++i) {
      cin >> w[i].real() >> w[i].imag() >> r[i];
    }
    cin >> m;
    while(m--) {
      P t, s;
      cin >> t.real() >> t.imag() >> s.real() >> s.imag();
      if(safe(t,s)) cout << "Safe" << endl;
      else cout << "Danger" << endl;
    }
  }
  return 0;
}

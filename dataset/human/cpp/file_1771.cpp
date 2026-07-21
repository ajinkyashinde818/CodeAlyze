#include<bits/stdc++.h>
const int MOD=1000000007;
const int INF=1000000000;
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const double eps=1e-9;
const int inf=1e9;
typedef pair<int,int> P;
struct Point
{
  double x,y;
  Point(){x=0;y=0;}
  Point(double d_x,double d_y){x=d_x,y=d_y;}
  double operator*(Point obj){return obj.x*x+obj.y*y;}
  double operator%(Point obj){return obj.y*x-obj.x*y;}
  Point operator*(double b){Point tmp;tmp.x=x*b;tmp.y=y*b;return tmp;}
  Point operator/(double b){Point tmp;tmp.x=x/b;tmp.y=y/b;return tmp;}
  Point operator+(Point obj){Point tmp;tmp.x=x+obj.x;tmp.y=y+obj.y;return tmp;}
  Point operator-(){Point tmp;tmp.x=-x;tmp.y=-y;return tmp;}
  Point operator-(Point obj){Point tmp;tmp.x=x-obj.x;tmp.y=y-obj.y;return tmp;}
  Point operator-=(Point obj){x-=obj.x;y-=obj.y;return *this;}
  Point operator+=(Point obj){x+=obj.x;y+=obj.y;return *this;}
  Point operator/=(double b){x=x/b;y=y/b;return *this;}
  Point operator*=(double b){x=x*b;y=y*b;return *this;}
  double size(){return hypot(x,y);}
  Point unit(){return Point(x/size(),y/size());}
  Point normal(){return Point(y,-x);}
  double atan(){return atan2(y,x);}
};

bool operator<(Point a,Point b){return a.x!=b.x?a.x<b.x:a.y<b.y;}
bool operator>(Point a,Point b){return b<a;}
bool operator<=(Point a,Point b){return !(b<a);}
bool operator>=(Point a,Point b){return !(a<b);}
bool operator==(Point a,Point b){return (a-b).size()<eps;}
bool operator!=(Point a,Point b){return !(a==b);}

bool equal(double a,double b){return abs(a-b)<eps;}
double cross(Point a,Point b){return a%b;}
double dot(Point a,Point b){return a*b;}

int ccw(Point a,Point b,Point c)
{
  b=b-a;
  c=c-a;
  if(b%c>0) return +1;
  else if(b%c<0)return -1;
  else if(b*c<0) return +2;
  else if(b.size()<c.size()) return -2;
  else return 0;
}

int main(int argc,char const* argv[])
{
  int n,m;
  bool put[200005];
  memset(put,0,sizeof(put));
  vector<int> appear;
  vector<int> inp;
  cin >> n >> m;
  for(int i=0;i<m;i++)
    {
      int e;
      cin >> e;
      inp.push_back(e);
    }
  for(int i=m-1;i>=0;i--)
    {
      if(!put[inp[i]])
	{
	  put[inp[i]]=true;
	  cout << inp[i] << endl;
	}
    }
  for(int i=1;i<=n;i++)
    {
      if(!put[i]) cout << i << endl;
    }

  return 0;
}

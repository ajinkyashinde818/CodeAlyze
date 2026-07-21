#include <cassert>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <map>
#include <queue>
#include <string.h>
#include <vector>

using namespace std;
typedef long long ll;

struct Circle {
  int x;
  int y;
  int r;

  Circle(int x = -1, int y = -1, int r = -1) {
    this->x = x;
    this->y = y;
    this->r = r;
  }
};

struct Node {
  int v;
  double dist;

  Node(int v = -1, double dist = -1) {
    this->v = v;
    this->dist = dist;
  }

  bool operator>(const Node &n) const {
    return dist > n.dist;
  }
};

int main() {
  int XS, YS, XT, YT;
  int N;

  cin >> XS >> YS >> XT >> YT;
  cin >> N;

  vector<Circle> circles;
  circles.push_back(Circle(XS, YS, 0));

  int x, y, r;

  for (int i = 0; i < N; ++i) {
    cin >> x >> y >> r;
    circles.push_back(Circle(x, y, r));
  }

  circles.push_back(Circle(XT, YT, 0));

  priority_queue <Node, vector<Node>, greater<Node> > pque;
  pque.push(Node(0, 0.0));

  bool visited[N + 2];
  memset(visited, false, sizeof(visited));

  while (!pque.empty()) {
    Node node = pque.top();
    Circle from = circles[node.v];
    pque.pop();

    if (visited[node.v]) continue;
    visited[node.v] = true;

    if (node.v == N + 1) {
      cout << setprecision(10) << node.dist << endl;
      break;
    }

    for (int u = 1; u <= N + 1; ++u) {
      if (visited[u]) continue;

      Circle to = circles[u];
      double dist = sqrt(pow(from.y - to.y, 2) + pow(from.x - to.x, 2));
      dist = max(0.0, dist - from.r - to.r);

      pque.push(Node(u, node.dist + dist));
    }
  }

  return 0;
}

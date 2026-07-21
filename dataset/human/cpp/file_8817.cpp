#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using ll = long long;
ll H, W;
ll h, w;

bool is_ok(std::vector< std::string >& grid, std::vector< std::string > temp)
{
  for (ll Y = 0; Y < H-h+1; Y++) {
    for (ll X = 0; X < W-w+1; X++) {
      bool was_found = true;
      for (ll y = 0; y < h; y++) {
	for (ll x = 0; x < w; x++) {
	  if (grid[Y+y][X+x] == temp[y][x]) {
	    ;
	  } else {
	    was_found = false;
	  }
	}
      }
      if (was_found) return true;
    }
  }

  return false;
}

int main(int argc, char* argv[])
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);

  ll N, M;
  std::cin >> N >> M;
  H = N;
  W = N;
  h = M;
  w = M;
  std::vector< std::string > grid(H, std::string(W, 'x'));
  std::vector< std::string > temp(h, std::string(w, 'x'));
  for (ll y = 0; y < H; y++) {
    std::cin >> grid[y];
  }
  for (ll y = 0; y < h; y++) {
    std::cin >> temp[y];
  }

  std::string judge = is_ok(grid, temp) ? "Yes" : "No";
  std::cout << judge << std::endl;

  return 0;
}

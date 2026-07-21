#include <iostream>
#include <limits>
#include <vector>
#include <stack>
#include <algorithm>
#include <array>
#include <queue>
#include <cmath>
#include <iomanip>
#include <set>
#include <map>
#include <cassert>

typedef uint_fast64_t u64;
typedef int_fast64_t i64;
typedef uint_least32_t u32;
typedef int_fast32_t i32;
typedef uint_least16_t u16;
typedef int_fast16_t i16;
typedef uint_least8_t u8;
typedef int_fast8_t i8;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  u64 n,r,g,b, cnt=0;
  std::cin >> r>>g>>b>>n;
  u64 mx = std::max(r,std::max(g,b)), mn=std::min(r,std::min(g,b)), md=r+g+b-mx-mn;
  for (u64 i=0; i<n/mx+1;++i) {
    if (i*mx>n) break;
    u64 tmp = n - i*mx;
    for (u64 j=0; j<tmp/md+1;++j) {
      if (j*md>tmp) break;
      u64 tmp2 = tmp - j*md;
      if (tmp2%mn == 0) ++cnt;
    }
  }

  std::cout << cnt<<std::endl;
  return 0;
}

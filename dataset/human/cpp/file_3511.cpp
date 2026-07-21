#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#define _io ios_base::sync_with_stdio(false); cin.tie(nullptr);
using namespace std;

int main() { _io
    long long n, total=0, k=0;
    cin >> n;
    vector<long long> arr(n);
    for (int i=0; i<n; i++) {
        cin >> arr[i];
        if (arr[i] <= 0) k++;
        arr[i] = abs(arr[i]);
        total += arr[i];
    }
    cout << total - (k%2 ? 2*(*min_element(arr.begin(), arr.end())) : 0);
}

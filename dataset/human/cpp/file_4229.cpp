#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <tuple>
#include <bitset>
#include <memory>
#include <cmath>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <cfloat>
#include <cassert>
#include <random>
#include<iostream>
#include<cmath>


long long int cal_time(const long long int time) {
	if (time <= 3) {
		return time;
	}
	else {
		switch (time % 3) {
		case 0: return cal_time((time - 2) / 3) + 3;
		case 1: return cal_time((time - 2) / 3) + 4;
		case 2: return cal_time((time - 2) / 3) + 2;
		default: throw 0;
		}
	}
}
int main() {
	long long int t; std::cin >> t;
	std::cout << cal_time(t + 1) - 1 << '\n';
}

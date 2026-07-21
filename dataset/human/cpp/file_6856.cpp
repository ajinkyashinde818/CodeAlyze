#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

bool solve_gu(std::vector<int> a, std::vector<int> b) {
	do {
		bool ok = true;
		for (int i = 0; i < (int) a.size(); i++) if (a[i] == b[i]) ok = false;
		if (ok) return true;
	} while (std::next_permutation(b.begin(), b.end()));
	return false;
}
bool solve(std::vector<int> a, std::vector<int> b) {
	int n = a.size();
	std::map<int, std::pair<int, int> > all;
	for (auto i : a) all[i].first++;
	for (auto i : b) all[i].second++;
	int free0 = 0;
	int free1 = 0;
	std::vector<int> free0s;
	std::vector<int> free1s;
	int shared = n;
	std::vector<int> shareds(n);
	std::iota(shareds.begin(), shareds.end(), 0);
	int used = 0;
	
	std::vector<std::pair<int, int> > res(n);
	
	for (auto i : all) {
		int use0 = i.second.first;
		int use1 = i.second.second;
		// std::cerr << "use " << use0 << " " << use1 << std::endl;
		int val = i.first;
		used += use0 + use1;
		if (std::max(0, use0 - free0) + std::max(0, use1 - free1) > shared) return false;
		if (use0 + use1 >= shared) {
			int total = free0 + free1 - use0 - use1 + shared * 2;
			int diff = free1 - free0 + use0 - use1;
			int free0_needed = std::max(0, use0 - shared);
			int free1_needed = std::max(0, use1 - shared);
			// std::cerr << "!" << total << " " << diff << std::endl;
			assert(!((total + diff) & 1));
			int free0_use = free0_needed;
			int free1_use = free1_needed;
			int excess = std::max(0, use0 + use1 - free0_use - free1_use - shared);
			/*
			std::cerr << "!!!" << excess << " " << free0_use << " " << free1_use << std::endl;
			std::cerr << "!!!!" << free0 << " " << free0_needed << std::endl;*/
			free0_use += std::max(0, std::min({free0 - free0_needed, excess, use0 - free0_needed}));
			excess -= std::max(0, std::min({free0 - free0_needed, excess, use0 - free0_needed}));
			free1_use += excess;
			
			// std::cerr << "!!!" << excess << " " << free0_use << " " << free1_use << std::endl;
			
			std::vector<int> news;
			for (int i = 0; i < use0; i++) {
				if (i < free0_use) {
					assert(free0s.size());
					res[free0s.back()].first = val;
					free0s.pop_back();
				} else {
					assert(shareds.size());
					res[shareds.back()].first = val;
					news.push_back(shareds.back());
					shareds.pop_back();
				}
			}
			for (int i = 0; i < use1; i++) {
				if (i < free1_use) {
					assert(free1s.size());
					res[free1s.back()].second = val;
					free1s.pop_back();
				} else {
					assert(shareds.size());
					res[shareds.back()].second = val;
					free0s.push_back(shareds.back());
					shareds.pop_back();
				}
			}
			for (auto j : news) free1s.push_back(j);
			free0 = free0s.size();
			free1 = free1s.size();
			shared = shareds.size();
		} else {
			for (int i = 0; i < use0 + use1; i++) {
				assert(shareds.size());
				if (i < use0) {
					res[shareds.back()].first = val;
					free1s.push_back(shareds.back());
					shareds.pop_back();
				} else {
					res[shareds.back()].second = val;
					free0s.push_back(shareds.back());
					shareds.pop_back();
				}
			}
			free1 += use0, free0 += use1;
		}
		shared = n - free0 - free1 - (used - (free0 + free1)) / 2;
		assert((int) shareds.size() == shared);
		assert((int) free0s.size() == free0);
		assert((int) free1s.size() == free1);
		// std::cerr << free0 << " " << free1 << " " << shared << std::endl;
		/*
		std::cerr << "  free0:";
		for (auto i : free0s) std::cerr << i << " ";
		std::cerr << std::endl;
		std::cerr << "  free1:";
		for (auto i : free1s) std::cerr << i << " ";
		std::cerr << std::endl;
		std::cerr << "  shared:";
		for (auto i : shareds) std::cerr << i << " ";
		std::cerr << std::endl;*/
	}
	
	/*
	for (auto i : resa) std::cerr << i << " ";
	std::cerr << std::endl;
	for (auto i : resb) std::cerr << i << " ";
	std::cerr << std::endl;*/
	
	puts("Yes");
	std::sort(res.begin(), res.end());
	for (auto i : res) printf("%d ", i.second);
	puts("");
	return true;
}

bool test(std::vector<int> a, std::vector<int> b) {
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
		for (auto i : a) std::cerr << i << " ";
		std::cerr << std::endl;
		for (auto i : b) std::cerr << i << " ";
		std::cerr << std::endl;
	bool r0 = solve_gu(a, b);
	bool r1 = solve(a, b);
	if (r0 != r1) {
		std::cerr << r0 << " " << r1 << std::endl;
		for (auto i : a) std::cerr << i << " ";
		std::cerr << std::endl;
		for (auto i : b) std::cerr << i << " ";
		std::cerr << std::endl;
		return false;
	}
	return true;
}

std::random_device rnd_dev;
std::mt19937 rnd(rnd_dev());
bool random_test(int n) {
	std::vector<int> a(n), b(n);
	for (auto &i : a) i = std::uniform_int_distribution<>(0, 10)(rnd);
	for (auto &i : b) i = std::uniform_int_distribution<>(0, 10)(rnd);
	return test(a, b);
}

int main() {
	/*
	for (int i = 0; i < 1000000; i++) random_test(3);
	return 0;*/
	int n = ri();
	std::vector<int> a(n);
	std::vector<int> b(n);
	for (auto &i : a) i = ri();
	for (auto &i : b) i = ri();
	if (!solve(a, b)) puts("No");
	return 0;
}

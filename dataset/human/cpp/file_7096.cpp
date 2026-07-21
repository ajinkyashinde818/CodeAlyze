#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;


template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char c) {
  return string(1,c);
}

string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (int i = int(N)-1; i >= 0; --i) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef COMPETITIVE_PROGRAMMING_LOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) if(0){}
#endif



template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
 
#include <unistd.h>
 
struct Scanner {
  int fd = -1;
  char line[(1 << 15) + 1];
  size_t st = 0, ed = 0;
  void reread() {
    memmove(line, line + st, ed - st);
    ed -= st;
    st = 0;
    ed += ::read(fd, line + ed, (1 << 15) - ed);
    line[ed] = '\0';
  }
  bool succ() {
    while (true) {
      if (st == ed) {
        reread();
        if (st == ed) return false;
      }
      while (st != ed && isspace(line[st])) st++;
      if (st != ed) break;
    }
    if (ed - st <= 50) {
      bool sep = false;
      for (size_t i = st; i < ed; i++) {
        if (isspace(line[i])) {
          sep = true;
          break;
        }
      }
      if (!sep) reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
  bool read_single(T& ref) {
    if (!succ()) return false;
    while (true) {
      size_t sz = 0;
      while (st + sz < ed && !isspace(line[st + sz])) sz++;
      ref.append(line + st, sz);
      st += sz;
      if (!sz || st != ed) break;
      reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  bool read_single(T& ref) {
    if (!succ()) return false;
    bool neg = false;
    if (line[st] == '-') {
      neg = true;
      st++;
    }
    ref = T(0);
    while (isdigit(line[st])) {
      ref = 10 * ref + (line[st++] & 0xf);
    }
    if (neg) ref = -ref;
    return true;
  }
  template <class T> bool read_single(V<T>& ref) {
    for (auto& d : ref) {
      if (!read_single(d)) return false;
    }
    return true;
  }
  void read() {}
  template <class H, class... T> void read(H& h, T&... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }
  Scanner(FILE* fp) : fd(fileno(fp)) {}
};
 
struct Printer {
public:
  template <bool F = false> void write() {}
  template <bool F = false, class H, class... T>
  void write(const H& h, const T&... t) {
    if (F) write_single(' ');
    write_single(h);
    write<true>(t...);
  }
  template <class... T> void writeln(const T&... t) {
    write(t...);
    write_single('\n');
  }
 
  Printer(FILE* _fp) : fp(_fp) {}
  ~Printer() { flush(); }

private:
  static constexpr size_t SIZE = 1 << 15;
  FILE* fp;
  char line[SIZE], small[50];
  size_t pos = 0;
  void flush() {
    fwrite(line, 1, pos, fp);
    pos = 0;
  }
  void write_single(const char& val) {
    if (pos == SIZE) flush();
    line[pos++] = val;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  void write_single(T val) {
    if (pos > (1 << 15) - 50) flush();
    if (val == 0) {
      write_single('0');
      return;
    }
    if (val < 0) {
      write_single('-');
      val = -val; // todo min
    }
    size_t len = 0;
    while (val) {
      small[len++] = char(0x30 | (val % 10));
      val /= 10;
    }
    for (size_t i = 0; i < len; i++) {
      line[pos + i] = small[len - 1 - i];
    }
    pos += len;
  }
  void write_single(const string& s) {
    for (char c : s) write_single(c);
  }
  void write_single(const char* s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) write_single(s[i]);
  }
  template <class T> void write_single(const V<T>& val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write_single(' ');
      write_single(val[i]);
    }
  }
};
 
Scanner sc = Scanner(stdin);
Printer pr = Printer(stdout);

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll n;
  sc.read(n);
  vector<ll> A(n), B(n);
  for (int i = 0; i < n; ++i) sc.read(A[i]), --A[i];
  for (int i = 0; i < n; ++i) sc.read(B[i]), --B[i];
  
  


  map<int,set<int>> s;
  for (int i = 0; i < n; ++i) {
    s[B[i]].insert(i);
  }
  int i = 0;
  while (i < n) {
    int pi = i;
    map<int,set<int>> next_s;
    while (i < n && A[i] == A[pi]) {
      if (B[i] != A[i]) {
        ++i;
        continue;
      }
      auto it = s.upper_bound(B[i]);
      if (it == s.end()) {
        if (prev(it) == s.begin()) {
          pr.writeln("No");
          return 0;
        }
        it = prev(prev(it));
      }
      dbg("swap", i, *it->second.begin());

      swap(B[i], B[*it->second.begin()]);
      s[B[i]].erase(i);
      it->second.erase(it->second.begin());
      
      next_s[B[i]].insert(*it->second.begin());
      next_s[it->first].insert(i);
      if (it->second.empty()) s.erase(it);
      if (s[B[i]].empty()) s.erase(B[i]);
    }
    for (auto [k,ii] : next_s) for (auto v : ii) s[k].insert(v);
  }

  dbg(A);
  dbg(B);
  bool good = true;
  for (i = 0; i < n; ++i) {
    if (A[i] == B[i]) {
      good = false;
      break;
    }
  }

  if (good) {
    pr.writeln("Yes");
    for (i = 0; i < n; ++i) {
      if (i) pr.write(' ');
      pr.write(B[i]+1);
    }
    pr.writeln();

  } else {
    pr.writeln("No");
  }
  

}

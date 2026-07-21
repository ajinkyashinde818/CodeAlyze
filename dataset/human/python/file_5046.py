import std;

void main() {
  int N, M;
  scan(N, M);
  auto to1 = new bool[](N);
  auto toN = new bool[](N);
  foreach (i; 0 .. M) {
    int ai, bi;
    scan(ai, bi);
    ai--, bi--;
    if (ai == 0) {
      to1[bi] = true;
    }
    if (bi == N - 1) {
      toN[ai] = true;
    }
  }
  bool ok;
  foreach (i; 0 .. N) {
    if (to1[i] && toN[i]) ok = true;
  }
  yes(ok, "POSSIBLE", "IMPOSSIBLE");
}

void scan(T...)(ref T args) {
    auto line = readln.split; // @suppress(dscanner.suspicious.unmodified)
    foreach (ref arg; args) {
        arg = line.front.to!(typeof(arg));
        line.popFront;
    }
    assert(line.empty);
}
 
void fillAll(R, T)(ref R arr, T value) {
    static if (is(typeof(arr[] = value))) {
        arr[] = value;
    }
    else {
        foreach (ref e; arr) {
            fillAll(e, value);
        }
    }
}
 
bool chmin(T, U...)(ref T x, U args) {
    bool isChanged;
    foreach (arg; args)
        if (x > arg) {
            x = arg;
            isChanged = true;
        }
    return isChanged;
}
 
bool chmax(T, U...)(ref T x, U args) {
    bool isChanged;
    foreach (arg; args)
        if (x < arg) {
            x = arg;
            isChanged = true;
        }
    return isChanged;
}
 
void yes(bool ok, string y = "Yes", string n = "No") {
    return writeln(ok ? y : n);
}
